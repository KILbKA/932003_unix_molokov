#!/bin/sh

cleanup() {
  echo "Cleaning up..."
  # Очищаем временный каталог
  rm -rf "$temp_dir"
  exit 1
}

# Регистрируем функции очистки сигналов
trap cleanup EXIT INT TERM

# Проверяем, есть ли исходный файл
if [ $# -ne 1 ]; then
  echo "Usage: $0 <source_file>"
  exit 1
fi

source_file="$1"

# Проверяем, существует ли исходный файл
if [ ! -f "$source_file" ]; then
  echo "Source file not found: $source_file"
  exit 1
fi

# Создаём временный каталог
temp_dir=$(mktemp -d)
if [ ! -d "$temp_dir" ]; then
  echo "Failed to create a temp directory."
  cleanup
fi

# Находим имя выходного файла в комментарии "&Output"
output_name=$(grep '&Output:' "$source_file" | awk '{print $2}')

if [ -z "$output_name" ]; then
  echo "No '&Output:' comment found in the source file."
  cleanup
fi

# Компилируем исходный файл, помещаем вывод в tempdir
# "g++ -o" используем для компиляции файла C++
g++ -o "$temp_dir/$output_name" "$source_file"

# Перемещаем выходной файл
mv "$temp_dir/$output_name" "./$output_name"

# Очищаем временный каталог
rm -rf "$temp_dir"

# Build successful
echo "Build successful: &Output: $output_name"
