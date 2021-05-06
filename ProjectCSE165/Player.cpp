#include "Player.h"

#include <QGraphicsScene>
#include <QKeyEvent>

#include "Bullet.h"
#include "Enemy.h"
#include <QList>
#include <QDebug>

//Game Mechanics:

Player::Player(QGraphicsItem *parent): QGraphicsRectItem(parent){ //Player is able to use in main

}

void Player::keyPressEvent(QKeyEvent *event){ //when moving the player left and right with boudaries:

//    QList<QGraphicsItem *> colliding_items = collidingItems(); //we cand find what the bullet is colliding with


    for (int i = 0, n = colliding_items.size(); i<n; i++){
        if(typeid(*(colliding_items[i])) == typeid(Enemy)){

            qDebug()<<"collide check";

        this->setPos(x()+400, y()+500);

             }
            }

    if (event->key() == Qt::Key_Left){
        if(pos().x()>0){ // if the player reaches the bounds because scene's Left is origin x
            setPos(x()-20,y());
            }
    }
    else if (event->key() == Qt::Key_Right){
        if(pos().x() + 30 <800){ //30 is the player's right corner & 800 is the Viewscreen's right boundry
        setPos(x()+20,y());
        }
    }
   else if (event->key() == Qt::Key_Up){

        if(pos().y()>0){ //up boundary
        setPos(x(),y()-30);
        }
    }
    else if (event->key() == Qt::Key_Down){ //prevent from using up and down
        if(pos().y() +40 <600){ //"down boundary
        setPos(x(),y()+30);
        }
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

void Player::reset()
{



}
