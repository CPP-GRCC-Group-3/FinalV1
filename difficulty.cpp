#include "difficulty.h"
#include "ui_difficulty.h"
#include <string>
#include "gamewindow.h"

GameHandler handler;

Difficulty::Difficulty(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Difficulty)
{
    ui->setupUi(this);
}



Difficulty::~Difficulty()
{
    delete ui;
}

/*
Difficulty::Difficulty(GameHandler gamer)  :
    ui(new Ui::Difficulty) {
    handler = gamer;
    ui->setupUi(this);
}
*/

void Difficulty::on_StartGame_clicked()
{
    if (this->ui->EasyRadio->isChecked()) {
        GameWindow game("Easy");
        game.setModal(true);
        game.exec();
    }
    else if (this->ui->MediumRadio->isChecked()) {
        GameWindow game("Medium");
        game.setModal(true);
        game.exec();
    }
    else {
        GameWindow game("Hard");
        game.setModal(true);
        game.exec();
    }


    this->hide();

}
