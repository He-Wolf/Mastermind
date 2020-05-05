#ifndef HALLFAME_H
#define HALLFAME_H

#include <QDialog>

namespace Ui {
class HallFame;
}

class HallFame : public QDialog
{
    Q_OBJECT

public:
    explicit HallFame(QWidget *parent = nullptr);
    ~HallFame();

private slots:
    void on_pushButtonBack_clicked();

private:
    Ui::HallFame *ui;
};

#endif // HALLFAME_H
