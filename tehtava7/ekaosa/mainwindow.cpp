#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), count(0) {
    ui->setupUi(this);
    connect(ui->countButton, &QPushButton::clicked, this, &MainWindow::increment);
    connect(ui->resetButton, &QPushButton::clicked, this, &MainWindow::reset);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::increment() {
    count++;
    ui->lineEdit->setText(QString::number(count));
}

void MainWindow::reset() {
    count = 0;
    ui->lineEdit->setText("0");
}
