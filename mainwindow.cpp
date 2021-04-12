#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>
#include <iostream>
#include <ctime>
#include "gamehandler.h"
#include <QPalette>
#include "difficulty.h"
#include "gamewindow.h"
#include "editwindow.h"
#include "highscore.h"
#include "MemoryTracking.h"

using namespace std;



GameHandler gamer;
int iSecret;
int colorTimer = 0;
//int iValue;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
//    ui->centralwidget->setStyleSheet("Background-color: rgb(255,0,0);");
    ui->statusbar->setStyleSheet("background-color: rgb(25, 255, 155);");
    ui->statusbar->showMessage("Hello",10000);

    timer = new QTimer(this);
    //connect(timer, SIGNAL(timeout()),this, SLOT(MyTimerSlot()));
    timer->start(1000);

    colorChangeTimer = new QTimer(this);
    connect(colorChangeTimer, SIGNAL(timeout()),this, SLOT(colorTimerSlot()));
    colorChangeTimer->start(60000);

    //ui->lcdNumber->setPalette(QColor(0,0,255));

}

MainWindow::~MainWindow()
{
    dumpUnfreedMemory();
    delete ui;
}

/*
void MainWindow::MyTimerSlot()
{

    //iValue = ui->lcdNumber->intValue();
    iValue++;
    //ui->lcdNumber->display(iValue);

}
*/

void MainWindow::colorTimerSlot()
{

    if (colorTimer % 2 == 0) {
        ui->centralwidget->setStyleSheet("Background-color: rgb(110,216,255);");
    }
    else {
        ui->centralwidget->setStyleSheet("Background-color: rgb(200,255,194);");
    }

    colorTimer++;
}


void MainWindow::on_InitialsButton_clicked()
{
    //GameHandler gamer;

    srand(time(NULL));
    iSecret = rand() % 11 + 0;

    string init = this->ui->InitialsTextBox->toPlainText().toStdString();
    gamer.setInitials(init);

    QString qstr = QString::fromStdString(gamer.getInitials());
    this->ui->CurrentInitials->setText(qstr);

    //this->ui->GuessPushButton->setEnabled(true);
    //this->ui->GuessBox->setEnabled(true);

    gamer.hide(true, iSecret);
}

void MainWindow::on_exitButton_clicked()
{
    exit(0);
}

void MainWindow::cust_Slot() {

    //this->ui->GuessBox->clear();
    this->ui->InitialsTextBox->clear();
    this->ui->CurrentInitials->clear();
    this->ui->WordIs->clear();
    //this->ui->scoreLabel->clear();
    //this->ui->GameWinOrLose->clear();
    //iValue = 0;
    gamer.setCurrentScore(0);
    gamer.clearBank();
    gamer.clearScore();
}

/*
void MainWindow::on_GuessPushButton_clicked()
{

    bool guessStatus;
    string guess;

    //this->ui->LABELGuessFeedback->setText("Please enter your guess. If you would like a hint, type 'hint' ");

    gamer.bankStore(true,iSecret);

    //guess = this->ui->GuessBox->toPlainText().toStdString();

    if (guess == "hint") {
        char hint = gamer.displayHint();
        QString qstr = QChar(hint);
        this->ui->WordIs->setText("Hint: " + qstr);
    }

    else {
        //check if users guess was valid
        guess = guess.substr(0, 1);
        guessStatus = gamer.checkGuess(guess);

        gamer.hide(true, iSecret);


        if (guessStatus) {
            //this->ui->GameWinOrLose->setText("Correct!");
        }
        else {
            //this->ui->GameWinOrLose->setText("Incorrect");
        }
    }

    //this->ui->GuessBox->clear();

    string number = to_string(gamer.getCurrentScore());

    QString score = QString::fromStdString(number);

    this->ui->scoreNumber->setText(score);

    string position = gamer.display(true, iSecret);
    QString qstr = QString::fromStdString(position);

    //this->ui->WordIs->setText(qstr);
    gamer.gameState();

}
*/

void MainWindow::on_pushButton_clicked()
{
    //QString difficulty;

    Difficulty DifficultyWindow;
    DifficultyWindow.setModal(true);
    DifficultyWindow.exec();


}

void MainWindow::cust_Slot2(){
    editWindow editwindow;
    editwindow.setModal(true);
    editwindow.exec();
}

void MainWindow::cust_Slot3(){
    highScore highscore;
    highscore.setModal(true);
    highscore.exec();
}
