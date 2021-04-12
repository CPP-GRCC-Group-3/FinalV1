#include "gamewindow.h"
#include "ui_gamewindow.h"
#include "gamehandler.h"

using namespace std;
extern GameHandler gamer;
extern int iSecret;
//int colorTimer = 0;
int iValue;

GameWindow::GameWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);
}

GameWindow::~GameWindow()
{
    delete ui;
}

GameWindow::GameWindow(QString difficulty) :
ui(new Ui::GameWindow)
{
    //gamer = game;

    if (difficulty == "Easy"){
        gamer.setWordArrayEasy();
    }
    else if (difficulty == "Medium"){
        gamer.setWordArrayMedium();
    }
    else {
        gamer.setWordArrayHard();
    }
    ui->setupUi(this);

    //QString qstr = QString::fromStdString(gamer.getInitials());
    //this->ui->ScoreLabel->setText(qstr);


}


void GameWindow::on_pushButton_clicked()
{
    bool guessStatus;
    QString QGuess;
    string guess;

    //this->ui->LABELGuessFeedback->setText("Please enter your guess. If you would like a hint, type 'hint' ");

    gamer.bankStore(true,iSecret);

    QGuess = this->ui->GuessInput->text();

    //this->ui->WinLabel->setText(QGuess);

    guess = QGuess.toStdString();

    if (guess == "hint") {
        char hint = gamer.displayHint();
        QString qstr = QChar(hint);
        this->ui->CorrectLabel->setText("Hint: " + qstr);
    }

    else {
        //check if users guess was valid
        guess = guess.substr(0, 1);
        guessStatus = gamer.checkGuess(guess);

        gamer.hide(true, iSecret);


        if (guessStatus) {
            this->ui->CorrectLabel->setText("Correct!");
        }
        else {
            this->ui->CorrectLabel->setText("Incorrect");
        }
    }

    this->ui->GuessInput->clear();

    string number = "Score: " + to_string(gamer.getCurrentScore());

    QString score = QString::fromStdString(number);

    this->ui->ScoreLabel->setText(score);

    string position = gamer.display(true, iSecret);
    QString qstr = QString::fromStdString(position);

    this->ui->label->setText(qstr);

    gamer.gameState();
    this->ui->WinLabel->setText(QString::fromStdString(gamer.getOutcome()));

}

void GameWindow::on_ExitButton_clicked()
{
    gamer.setCurrentScore(0);

    this->hide();
}
