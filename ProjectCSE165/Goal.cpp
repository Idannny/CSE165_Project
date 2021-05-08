#include "Game.h"
#include <stdlib.h> //rand()
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <QGraphicsItem>
#include <QList>

Goal::Goal(QGraphicsItem *parent): QObject(), QGraphicsEllipseItem(parent){

    //WALLS
    // random spawn pos
     int random_x = rand() % 900; //create random enemy within screen
     int random_y = rand() % 900;

//     qDebug()<<"x: "<<random_x<<"y: " <<random_y;

     if(random_x < 400 || random_x > 500){ // wont spawn on character
//         random_x = 200;

         qDebug()<<"Goal INSIDE x: "<<random_x<< " y: " <<random_y;
         setPos(random_x,random_y);
           setRect(0,0, 10,10 );


     }
}

void Goal::move()
{
//      setPos(100,100);
}


