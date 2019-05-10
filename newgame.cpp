#include "newgame.h"
#include "ui_newgame.h"

NewGame::NewGame(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewGame)
{
    ui->setupUi(this);
}

NewGame::~NewGame()
{
    delete ui;
}

void NewGame::on_pushButtonBack_clicked()
{
    hide();
    QWidget *parent=this->parentWidget();
    parent->show();
}

void NewGame::on_pushButtonStartGame_clicked()
{
    hide();
    windowGamePlay=new GamePlay(this);
    windowGamePlay->show();
    windowGamePlay->setDefaultGamePlay();
    windowGamePlay->setCode();
}
