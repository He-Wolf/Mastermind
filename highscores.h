#ifndef HIGHSCORES_H
#define HIGHSCORES_H

#include <QDialog>

namespace Ui {
class HighScores;
}

class HighScores : public QDialog
{
    Q_OBJECT

public:
    explicit HighScores(QWidget *parent = nullptr);
    ~HighScores();

private slots:
    void on_pushButtonBack_clicked();

private:
    Ui::HighScores *ui;
};

#endif // HIGHSCORES_H
