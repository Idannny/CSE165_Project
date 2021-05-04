#include "MyRect.h"

#include <QGraphicsScene>
#include <QKeyEvent>

#include "Bullet.h"
#include "Enemy.h"

#include <QDebug>


#include <QDebug>

//Game Mechanics:

void MyRect::keyPressEvent(QKeyEvent *event){ //when moving the player left and right with boudaries:
    if (event->key() == Qt::Key_Left){
        if(pos().x()>0){ // if the player reaches the bounds because scene's Left is origin x
        setPos(x()-50,y());
        }
    }
    else if (event->key() == Qt::Key_Right){
        if(pos().x() + 100 <800){ //"+100" is the player's right corner & 800 is the Viewscreen's right boundry
        setPos(x()+50,y());
        }
    }
//    else if (event->key() == Qt::Key_Up){
//        setPos(x(),y()-10);
//    }
//    else if (event->key() == Qt::Key_Down){ //prevent from using up and down
//        setPos(x(),y()+10);
//    }
    else if (event->key() == Qt::Key_Space){
        // create a bullet
        Bullet * bullet = new Bullet();

        bullet->setPos(x(),y());
        scene()->addItem(bullet);
    }
}

void MyRect::spawn(){ //to spawn the enemy as rectangular objects:
    //create enemy

    Enemy * enemy = new Enemy();
    scene() -> addItem(enemy);//additem is member from Qgraphicsscene
}
