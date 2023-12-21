// mainwindow.h
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QLabel>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private slots:
    void onMulButtonClicked();
    void onClearButtonClicked();

private:
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QPushButton *mulButton;
    QPushButton *clearButton;
    QLabel *labelResult;
};

#endif // MAINWINDOW_H
