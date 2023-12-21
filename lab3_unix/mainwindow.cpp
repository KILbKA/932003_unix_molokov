// mainwindow.cpp
#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    // Textbox
    lineEdit = new QLineEdit(this);
    lineEdit_2 = new QLineEdit(this);

    // Button
    mulButton = new QPushButton("Mul", this);
    clearButton = new QPushButton("Clear", this);

    // Result Label
    labelResult = new QLabel("Result: ", this);

    // Layout
    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(lineEdit);
    layout->addWidget(lineEdit_2);
    layout->addWidget(mulButton);
    layout->addWidget(clearButton);
    layout->addWidget(labelResult);


    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);

    // Connect Signals and Slots
    connect(mulButton, SIGNAL(clicked()), this, SLOT(onMulButtonClicked()));
    connect(clearButton, SIGNAL(clicked()), this, SLOT(onClearButtonClicked()));
}

void MainWindow::onMulButtonClicked()
{
    double num1 = lineEdit->text().toDouble();
    double num2 = lineEdit_2->text().toDouble();

    // multiply
    double mul = num1 * num2;

    // Display result
    labelResult->setText("Result: " + QString::number(mul));
}

void MainWindow::onClearButtonClicked()
{
    // Clear Line Edits and result Label
    lineEdit->clear();
    lineEdit_2->clear();
    labelResult->clear();
}
