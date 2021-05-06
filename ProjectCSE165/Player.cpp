#include "Player.h"

#include <QGraphicsScene>
#include <QKeyEvent>

#include "Bullet.h"
#include "Enemy.h"

#include <QDebug>

//Game Mechanics:

Player::Player(QGraphicsItem *parent): QGraphicsRectItem(parent){ //Player is able to use in main

}

void Player::keyPressEvent(QKeyEvent *event){ //when moving the player left and right with boudaries:
    if (event->key() == Qt::Key_Left){
        if(pos().x()>0){ // if the player reaches the bounds because scene's Left is origin x
        setPos(x()-95,y());
        }
    }
    else if (event->key() == Qt::Key_Right){
        if(pos().x() + 100 <800){ //"+100" is the player's right corner & 800 is the Viewscreen's right boundry
        setPos(x()+95,y());
        }
    }
   else if (event->key() == Qt::Key_Up){
        setPos(x(),y()-90);
    }
    else if (event->key() == Qt::Key_Down){ //prevent from using up and down
        setPos(x(),y()+90);
    }
    else if (event->key() == Qt::Key_Space){
        // create a bullet
        Bullet * bullet = new Bullet();

        bullet->setPos(x(),y());

        scene()->addItem(bullet);
    }
}

void Player::spawn(){ //to spawn the enemy as rectangular objects: similar to user
    //create enemy

    Enemy * enemy = new Enemy();
    scene() -> addItem(enemy);//additem is member from Qgraphicsscene
}
