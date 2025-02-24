#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), operand(-1), state(1) {
    ui->setupUi(this);


    for (int i = 0; i <= 9; ++i) {
        QString buttonName = "N" + QString::number(i);
        QPushButton *button = findChild<QPushButton*>(buttonName);
        if (button) {
            connect(button, &QPushButton::clicked, this, &MainWindow::numberClickHandler);
        }
    }


    connect(ui->add, &QPushButton::clicked, this, &MainWindow::operationClickHandler);
    connect(ui->sub, &QPushButton::clicked, this, &MainWindow::operationClickHandler);
    connect(ui->mul, &QPushButton::clicked, this, &MainWindow::operationClickHandler);
    connect(ui->div, &QPushButton::clicked, this, &MainWindow::operationClickHandler);


    connect(ui->clear, &QPushButton::clicked, this, &MainWindow::clear);
    connect(ui->enter, &QPushButton::clicked, this, &MainWindow::enter);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::numberClickHandler() {
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (!button) return;

    QString digit = button->text();
    if (state == 1) {
        number1 += digit;
        ui->num1->setText(number1);
    } else {
        number2 += digit;
        ui->num2->setText(number2);
    }
    qDebug() << "Number1:" << number1 << "Number2:" << number2;
}

void MainWindow::operationClickHandler() {
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (!button) return;

    if (button == ui->add) operand = 0;
    else if (button == ui->sub) operand = 1;
    else if (button == ui->mul) operand = 2;
    else if (button == ui->div) operand = 3;

    state = 2;
}

void MainWindow::clear() {
    number1 = "";
    number2 = "";
    state = 1;
    operand = -1;
    ui->num1->setText("");
    ui->num2->setText("");
    ui->result->setText("");
}

void MainWindow::enter() {
    if (number1.isEmpty() || number2.isEmpty()) return;

    float num1 = number1.toFloat();
    float num2 = number2.toFloat();
    float result = 0;

    switch (operand) {
    case 0: result = num1 + num2; break;
    case 1: result = num1 - num2; break;
    case 2: result = num1 * num2; break;
    case 3: if (num2 != 0) result = num1 / num2; break;
    }

    ui->result->setText(QString::number(result));
}
