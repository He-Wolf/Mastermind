#include "hallfame.h"
#include "ui_hallfame.h"

HallFame::HallFame(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HallFame)
{
    ui->setupUi(this);
}

HallFame::~HallFame()
{
    delete ui;
}

void HallFame::on_pushButtonBack_clicked()
{
    hide();
    QWidget *parent=this->parentWidget();
    parent->show();
}
