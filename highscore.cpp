#include "highscore.h"
#include "ui_highscore.h"
#include "gamehandler.h"
#include <string>
#include <iostream>
#include <QIODevice>
#include <QFile>


highScore::highScore(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::highScore)
{
    ui->setupUi(this);

}

highScore::~highScore()
{
    delete ui;
}

void highScore::on_scoreButton_clicked()
{
    QStringList scores;
    QFile file("Scores.txt");

            if (file.open(QIODevice::ReadOnly | QIODevice::Text)){
                QTextStream stream(&file);
                while (!stream.atEnd()){
                    scores += stream.readLine();

                }
            }
            file.close();

            ui->scoreList->clear();
            ui->scoreList->addItems(scores);
}

void highScore::on_exitScore_clicked()
{
    this -> hide();
}
