#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void numberClickHandler();
    void operationClickHandler();
    void clear();
    void enter();

private:
    Ui::MainWindow *ui;
    QString number1, number2;
    int operand;
    int state; // 1 = collecting number1, 2 = collecting number2
};

#endif
