#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QPushButton>

// leads to less ambiguity across all our files

#include "Player.h"
#include "Score.h"
#include "Warrants.h"
#include "Button.h"
#include "walls.h"
#include "Color.h"
#include "Goal.h"
//new widget
//parents are for moving items that are on the same character

class Game: public QGraphicsView{

public:
     Game(QWidget * parent=0);

    QGraphicsScene * scene;
    Player * player;
    Score * score;
    Button * my_button;

     void on_pushButton_clicked();

private slots:


private:
    Game * game;


};



#endif // GAME_H
