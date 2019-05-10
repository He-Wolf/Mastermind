#include "gameplay.h"
#include "ui_gameplay.h"

GamePlay::GamePlay(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GamePlay)
{
    ui->setupUi(this);
    actualStep=1;

    for (int i=0;i<4;i++) {
        codeNum[i]=0;
    }
    for (int i=0;i<48;i++) {
        guessNum[i]=0;
    }

    guesses[0]=ui->pushButtonGuess11;
    guesses[1]=ui->pushButtonGuess12;
    guesses[2]=ui->pushButtonGuess13;
    guesses[3]=ui->pushButtonGuess14;

    guesses[4]=ui->pushButtonGuess21;
    guesses[5]=ui->pushButtonGuess22;
    guesses[6]=ui->pushButtonGuess23;
    guesses[7]=ui->pushButtonGuess24;

    guesses[8]=ui->pushButtonGuess31;
    guesses[9]=ui->pushButtonGuess32;
    guesses[10]=ui->pushButtonGuess33;
    guesses[11]=ui->pushButtonGuess34;

    guesses[12]=ui->pushButtonGuess41;
    guesses[13]=ui->pushButtonGuess42;
    guesses[14]=ui->pushButtonGuess43;
    guesses[15]=ui->pushButtonGuess44;

    guesses[16]=ui->pushButtonGuess51;
    guesses[17]=ui->pushButtonGuess52;
    guesses[18]=ui->pushButtonGuess53;
    guesses[19]=ui->pushButtonGuess54;

    guesses[20]=ui->pushButtonGuess61;
    guesses[21]=ui->pushButtonGuess62;
    guesses[22]=ui->pushButtonGuess63;
    guesses[23]=ui->pushButtonGuess64;

    guesses[24]=ui->pushButtonGuess71;
    guesses[25]=ui->pushButtonGuess72;
    guesses[26]=ui->pushButtonGuess73;
    guesses[27]=ui->pushButtonGuess74;

    guesses[28]=ui->pushButtonGuess81;
    guesses[29]=ui->pushButtonGuess82;
    guesses[30]=ui->pushButtonGuess83;
    guesses[31]=ui->pushButtonGuess84;

    guesses[32]=ui->pushButtonGuess91;
    guesses[33]=ui->pushButtonGuess92;
    guesses[34]=ui->pushButtonGuess93;
    guesses[35]=ui->pushButtonGuess94;

    guesses[36]=ui->pushButtonGuess101;
    guesses[37]=ui->pushButtonGuess102;
    guesses[38]=ui->pushButtonGuess103;
    guesses[39]=ui->pushButtonGuess104;

    guesses[40]=ui->pushButtonGuess111;
    guesses[41]=ui->pushButtonGuess112;
    guesses[42]=ui->pushButtonGuess113;
    guesses[43]=ui->pushButtonGuess114;

    guesses[44]=ui->pushButtonGuess121;
    guesses[45]=ui->pushButtonGuess122;
    guesses[46]=ui->pushButtonGuess123;
    guesses[47]=ui->pushButtonGuess124;

    code[0]=ui->labelCode1;
    code[1]=ui->labelCode2;
    code[2]=ui->labelCode3;
    code[3]=ui->labelCode4;

    marks[0]=ui->labelMark1;
    marks[1]=ui->labelMark2;
    marks[2]=ui->labelMark3;
    marks[3]=ui->labelMark4;
    marks[4]=ui->labelMark5;
    marks[5]=ui->labelMark6;
    marks[6]=ui->labelMark7;
    marks[7]=ui->labelMark8;
    marks[8]=ui->labelMark9;
    marks[9]=ui->labelMark10;
    marks[10]=ui->labelMark11;
    marks[11]=ui->labelMark12;

    for (int i=0;i<48;i++) {
        connect(guesses[i],SIGNAL(clicked()),this,SLOT(on_pushButtonGuess_pressed()));
    }
    ui->lcdNumberSteps->display(actualStep);
}

GamePlay::~GamePlay()
{
    delete ui;
}

void GamePlay::on_pushButtonBack_clicked()
{
    hide();
    QWidget *parent=this->parentWidget();
    parent->show();
}

void GamePlay::setDefaultGamePlay()
{
    int i, j;
    for (i=1;i<12;i++) {
        for (j=0;j<4;j++) {
            guesses[i*4+j]->setVisible(false);
        }
    }
    for (i=0;i<12;i++) {
        marks[i]->setVisible(false);
    }
}

void GamePlay::on_pushButtonGuess_pressed()
{
    int buttonNumber;
    QPushButton *GuessClicked=qobject_cast<QPushButton*>(QObject::sender());
    QIcon buttonColor;

    for (buttonNumber=0; GuessClicked!=guesses[buttonNumber];buttonNumber++);

    switch (guessNum[buttonNumber]) {
    case 0:
        buttonColor.addPixmap(QPixmap(":/images/codeElementBrown"),QIcon::Normal);
        buttonColor.addPixmap(QPixmap(":/images/codeElementBrown"),QIcon::Disabled);
        GuessClicked->setIcon(buttonColor);
        guessNum[buttonNumber]++;
        break;
    case 1:
        buttonColor.addPixmap(QPixmap(":/images/codeElementGreen"),QIcon::Normal);
        buttonColor.addPixmap(QPixmap(":/images/codeElementGreen"),QIcon::Disabled);
        GuessClicked->setIcon(buttonColor);
        guessNum[buttonNumber]++;
        break;
    case 2:
        buttonColor.addPixmap(QPixmap(":/images/codeElementPink"),QIcon::Normal);
        buttonColor.addPixmap(QPixmap(":/images/codeElementPink"),QIcon::Disabled);
        GuessClicked->setIcon(buttonColor);
        guessNum[buttonNumber]++;
        break;
    case 3:
        buttonColor.addPixmap(QPixmap(":/images/codeElementRed"),QIcon::Normal);
        buttonColor.addPixmap(QPixmap(":/images/codeElementRed"),QIcon::Disabled);
        GuessClicked->setIcon(buttonColor);
        guessNum[buttonNumber]++;
        break;
    case 4:
        buttonColor.addPixmap(QPixmap(":/images/codeElementYellow"),QIcon::Normal);
        buttonColor.addPixmap(QPixmap(":/images/codeElementYellow"),QIcon::Disabled);
        GuessClicked->setIcon(buttonColor);
        guessNum[buttonNumber]++;
        break;
    case 5:
        buttonColor.addPixmap(QPixmap(":/images/codeElementBlue"),QIcon::Normal);
        buttonColor.addPixmap(QPixmap(":/images/codeElementBlue"),QIcon::Disabled);
        GuessClicked->setIcon(buttonColor);
        guessNum[buttonNumber]=0;
        break;
    }

    qDebug()<<buttonNumber<<"th button's color is:"<<guessNum[buttonNumber];
}

void GamePlay::setNewRow()
{
    for (int i=0;i<4;i++) {
        guesses[(actualStep-1)*4+i]->setDisabled(true);
        guesses[actualStep*4+i]->setVisible(true);
    }
}

void GamePlay::setCode()
{
    std::uniform_int_distribution<int>distribution(0,5);

    for (int i=0;i<4;i++) {
        codeNum[i]=distribution(*QRandomGenerator::global());
    }
    for (int i=0;i<4;i++) {
        switch (codeNum[i]) {
        case 0:
            code[i]->setPixmap(QPixmap(":/images/codeElementBlue"));
            break;
        case 1:
            code[i]->setPixmap(QPixmap(":/images/codeElementBrown"));
            break;
        case 2:
            code[i]->setPixmap(QPixmap(":/images/codeElementGreen"));
            break;
        case 3:
            code[i]->setPixmap(QPixmap(":/images/codeElementPink"));
            break;
        case 4:
            code[i]->setPixmap(QPixmap(":/images/codeElementRed"));
            break;
        case 5:
            code[i]->setPixmap(QPixmap(":/images/codeElementYellow"));
            break;
        }
    }
}

void GamePlay::on_pushButtonNextStep_clicked()
{
    if (actualStep!=12) {
        setNewRow();
        setMarks();
        actualStep++;
        ui->lcdNumberSteps->display(actualStep);
    }
    else {
        for (int i=0;i<4;i++)
            guesses[(actualStep-1)*4+i]->setDisabled(true);
        setMarks();
    }
}

void GamePlay::setMarks()
{
    int black=0, white=0, empty=0;
    bool scored[4]={false,false,false,false};

    for (int i=0;i<4;i++) {
        if (guessNum[(actualStep-1)*4+i]==codeNum[i]) {
            black++;
            scored[i]=true;
        }
    }
    for (int i=0;i<4;i++) {
        for (int j=0; j<4;j++) {
            if (guessNum[(actualStep-1)*4+i]==codeNum[j] && scored[j]==false && guessNum[(actualStep-1)*4+i]!=codeNum[i]) {
                white++;
                scored[j]=true;
                break;
            }
        }
    }
    empty=4-black-white;

    if (black==4) {
        marks[actualStep-1]->setPixmap(QPixmap(":/images/feedbackBBBB"));
        marks[actualStep-1]->setVisible(true);
    }
    else if (black==3 && empty==1) {
        marks[actualStep-1]->setPixmap(QPixmap(":/images/feedbackBBBE"));
        marks[actualStep-1]->setVisible(true);
    }
    else if (black==3 && white==1) {
        marks[actualStep-1]->setPixmap(QPixmap(":/images/feedbackBBBW"));
        marks[actualStep-1]->setVisible(true);
    }
    else if (black==2 && empty==2) {
        marks[actualStep-1]->setPixmap(QPixmap(":/images/feedbackBBEE"));
        marks[actualStep-1]->setVisible(true);
    }
    else if (black==2 && white==1 && empty==1) {
        marks[actualStep-1]->setPixmap(QPixmap(":/images/feedbackBBWE"));
        marks[actualStep-1]->setVisible(true);
    }
    else if (black==2 && white==2) {
        marks[actualStep-1]->setPixmap(QPixmap(":/images/feedbackBBWW"));
        marks[actualStep-1]->setVisible(true);
    }
    else if (black==1 && empty==3) {
        marks[actualStep-1]->setPixmap(QPixmap(":/images/feedbackBEEE"));
        marks[actualStep-1]->setVisible(true);
    }
    else if (black==1 && white==1 && empty==2) {
        marks[actualStep-1]->setPixmap(QPixmap(":/images/feedbackBWEE"));
        marks[actualStep-1]->setVisible(true);
    }
    else if (black==1 && white==2 && empty==1) {
        marks[actualStep-1]->setPixmap(QPixmap(":/images/feedbackBWWE"));
        marks[actualStep-1]->setVisible(true);
    }
    else if (black==1 && white==3) {
        marks[actualStep-1]->setPixmap(QPixmap(":/images/feedbackBWWW"));
        marks[actualStep-1]->setVisible(true);
    }
    else if (empty==4) {
        marks[actualStep-1]->setPixmap(QPixmap(":/images/feedbackEEEE"));
        marks[actualStep-1]->setVisible(true);
    }
    else if (white==1 && empty==3) {
        marks[actualStep-1]->setPixmap(QPixmap(":/images/feedbackWEEE"));
        marks[actualStep-1]->setVisible(true);
    }
    else if (white==2 && empty==2) {
        marks[actualStep-1]->setPixmap(QPixmap(":/images/feedbackWWEE"));
        marks[actualStep-1]->setVisible(true);
    }
    else if (white==3 && empty==1) {
        marks[actualStep-1]->setPixmap(QPixmap(":/images/feedbackWWWE"));
        marks[actualStep-1]->setVisible(true);
    }
    else if (white==4) {
        marks[actualStep-1]->setPixmap(QPixmap(":/images/feedbackWWWW"));
        marks[actualStep-1]->setVisible(true);
    }
}
