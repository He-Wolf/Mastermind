#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qmessagebox.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonNewGame_clicked()
{
    hide();
    windowNewGame = new NewGame(this);
    windowNewGame->show();
}

void MainWindow::on_pushButtonExit_clicked()
{
    this->close();
}

void MainWindow::on_pushButtonHighScores_clicked()
{
    hide();
    windowHighScores = new HighScores(this);
    windowHighScores->show();
}

void MainWindow::on_pushButtonAbout_clicked()
{
    QMessageBox::information(this, "About", "Here will be text ebout the game");
}
