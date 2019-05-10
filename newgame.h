#ifndef NEWGAME_H
#define NEWGAME_H

#include <QDialog>
#include <gameplay.h>

namespace Ui {
class NewGame;
}

class NewGame : public QDialog
{
    Q_OBJECT

public:
    explicit NewGame(QWidget *parent = nullptr);
    ~NewGame();

private slots:
    void on_pushButtonBack_clicked();

    void on_pushButtonStartGame_clicked();

private:
    Ui::NewGame *ui;
    GamePlay *windowGamePlay;
};

#endif // NEWGAME_H
