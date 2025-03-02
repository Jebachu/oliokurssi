#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , player1Time(0)
    , player2Time(0)
    , currentPlayer(1)
    , gameTime(0)
    , pQTimer(new QTimer(this))
{
    ui->setupUi(this);
    setGameInfoText("Select playtime and press START GAME", 12);

    connect(ui->buttonStartGame, &QPushButton::clicked, this, &MainWindow::startGame);
    connect(ui->buttonStopGame, &QPushButton::clicked, this, &MainWindow::stopGame);
    connect(ui->buttonSwitchPlayer1, &QPushButton::clicked, this, &MainWindow::switchPlayer);
    connect(ui->buttonSwitchPlayer2, &QPushButton::clicked, this, &MainWindow::switchPlayer);
    connect(ui->buttonSetTime1, &QPushButton::clicked, this, &MainWindow::setTime);
    connect(ui->buttonSetTime2, &QPushButton::clicked, this, &MainWindow::setTime);
    connect(pQTimer, &QTimer::timeout, this, &MainWindow::timeout);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setGameInfoText(QString text, short size)
{
    ui->labelGameInfo->setText(text);
    ui->labelGameInfo->setStyleSheet(QString("font-size: %1px;").arg(size));
}

void MainWindow::updateProgressBar()
{
    ui->progressBarPlayer1->setValue((player1Time * 100) / gameTime);
    ui->progressBarPlayer2->setValue((player2Time * 100) / gameTime);
}

void MainWindow::setTime()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (button == ui->buttonSetTime1)
        gameTime += 10; // Lisää 10 sekuntia
    else if (button == ui->buttonSetTime2)
        gameTime += 30; // Lisää 30 sekuntia

    player1Time = player2Time = gameTime;
    updateProgressBar();
}

void MainWindow::startGame()
{
    if (gameTime == 0) return;
    setGameInfoText("Ready to play", 12);
    player1Time = player2Time = gameTime;
    currentPlayer = 1;
    pQTimer->start(1000);
    setGameInfoText("Game ongoing", 12);
    updateProgressBar();
}

void MainWindow::stopGame()
{
    pQTimer->stop();
    setGameInfoText("New game via START GAME button", 12);
}

void MainWindow::switchPlayer()
{
    currentPlayer = (currentPlayer == 1) ? 2 : 1;
}

void MainWindow::timeout()
{
    if (currentPlayer == 1)
        player1Time--;
    else
        player2Time--;

    updateProgressBar();

    if (player1Time <= 0)
    {
        pQTimer->stop();
        setGameInfoText("Player 2 won", 14);
    }
    else if (player2Time <= 0)
    {
        pQTimer->stop();
        setGameInfoText("Player 1 won", 14);
    }
}
