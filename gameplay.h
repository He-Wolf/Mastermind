#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QIcon>
#include <QRandomGenerator>
#include <QDebug>
#include <QKeyEvent>
#include <QApplication>

namespace Ui {
class GamePlay;
}

class GamePlay : public QDialog
{
    Q_OBJECT

public:
    explicit GamePlay(QWidget *parent = nullptr);
    ~GamePlay();
    void setDefaultGamePlay();
    void setCode();
    void setNewRow();
    void setMarks();

protected:
    void keyPressEvent(QKeyEvent *);
    void keyReleaseEvent(QKeyEvent *);

private slots:
    void on_pushButtonBack_clicked();
    void on_pushButtonGuess_pressed();
    void on_pushButtonNextStep_clicked();

private:
    Ui::GamePlay *ui;
    QPushButton *guesses[48];
    QLabel *marks[12], *code[4];
    int actualStep, codeNum[4], guessNum[48];
};

#endif // GAMEPLAY_H
