#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QPushButton>

#include "Player.h"
#include "Score.h"

//new widget
//parents are for moving items that are on the same character

class Game: public QGraphicsView{

public:
    Game(QWidget * parent=0);

    QGraphicsScene * scene;
    Player * player;
    Score * score;
    QPushButton * button;


};



#endif // GAME_H
