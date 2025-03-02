#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void timeout();

private slots:
    void updateProgressBar();
    void setGameInfoText(QString text, short size);
    void setTime();
    void startGame();
    void stopGame();
    void switchPlayer();

private:
    Ui::MainWindow *ui;
    short player1Time;
    short player2Time;
    short currentPlayer;
    short gameTime;
    QTimer *pQTimer;
};

#endif // MAINWINDOW_H
