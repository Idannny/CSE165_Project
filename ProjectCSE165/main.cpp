
//#include <QGraphicsScene>
//#include "Player.h" //extends QraphicsRect//PORTED TO GAME.CPP
//#include <QGraphicsView>
//#include <QGraphicsItem>
#include <QApplication>
#include "Game.h"


Game * game;//CLASS game is from game.h is now parenting main.cpp

int main(int argc, char *argv[]){
    QApplication videoGame(argc, argv);

       game = new Game();
       game->show();

    return videoGame.exec(); //execution of the command


    //a testing comment

}
