#include "Game.h"
#include <stdlib.h> //rand()
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <QGraphicsItem>
#include <QList>

extern Score * score;

Goal::Goal(QGraphicsItem *parent): QObject(), QGraphicsEllipseItem(parent){


     int random_x = rand() % 900; //create random enemy within screen
     int random_y = rand() % 900;

     qDebug()<<"Spawning Goal";
     qDebug()<<"x: "<< random_x << "y: " << random_y;

     //if(random_x < 400 || random_x > 500){ // wont spawn on character
         random_x = 200;

         qDebug()<<"Goal INSIDE x: "<<random_x<< " y: " <<random_y;
         setPos(random_x,random_y);
           setRect(0,0, 20,20 );

//end of while
}

void Goal::move()
{
    QList<QGraphicsItem *> coinCollect = collidingItems();
    for (int i = 0, n = coinCollect.size(); i<n; i++){ //when player hits walls
        if(typeid(*(coinCollect[i])) == typeid(Goal)){

          qDebug()<<"goal check";
             }
            }
//      setPos(100,100);

}


