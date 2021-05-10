#include "titlewindow.h"
#include "ui_titlewindow.h"
#include "Game.h"

extern Game * game;

TitleWindow::TitleWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TitleWindow)
{
    ui->setupUi(this);
}

TitleWindow::~TitleWindow()
{
    delete ui;
}

void TitleWindow::on_pushButton_clicked()
{

    //Effectively links two windows together:

    game = new Game(); //generates game window

    delete this; //deletes the instance of memory allocated to the Title window... allowing us to move after pressing it...

    game->show();


}
