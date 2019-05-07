#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <newgame.h>
#include <hallfame.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonNewGame_clicked();

    void on_pushButtonExit_clicked();

    void on_pushButtonHallFame_clicked();

    void on_pushButtonGameRules_clicked();

private:
    Ui::MainWindow *ui;
    NewGame *windowNewGame;
    HallFame *windowHallFame;
};

#endif // MAINWINDOW_H
