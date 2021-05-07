//#include <Player.h>
#include "Game.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <QGraphicsItem>
#include <QList>
#include <stdlib.h> //rand()


//WE SHOULD HAVE ENEMY TURRETS

Walls::Walls(QGraphicsItem *parent): QObject(), QGraphicsRectItem(parent){



    //WALLS
    // random spawn pos
     int random_x = rand() % 900; //create random enemy within screen
     int random_y = rand() % 800;

     qDebug()<<" ORIGINAL x: "<<random_x<<"y: " <<random_y;

 //y first
     if(random_y < 500){ // if
//         qDebug()<<"INSIDE x: "<<random_x<<"y: " <<random_y;

            setPos(random_x,490);
          setRect(0,0,50,-400); //LOOK out for top boundary Deletion (reason why bullets delete)
     }

     if(random_y > 525){ // wont spawn boundaries on character and the goal so i need current coords of player and goal

//         qDebug()<<"INSIDE x: "<<random_x<<"y: " <<random_y;

          setPos(random_x,530);
          setRect(0,0,50,500);
     }                                      //REMEMBER random_x and Random_y are the corners of the rectangles so technically you make the pont before rect

     if(random_x < 400){ //width of player

//         qDebug()<<"INSIDE x: "<<random_x<<"y: " <<random_y;

          setPos(390,random_y);
          setRect(0,0,-500,50);
     }
     if(random_x > 430){

//         qDebug()<<"INSIDE x: "<<random_x<<"y: " <<random_y;

          setPos(440,random_y); //WE CAN CHANGE SO IT ISNT AT THE NEAR EDGES OF THE PLAYER
          setRect(0,0,500,50);
     }



    //IN THEORY THIS IS WHATWE NEED TO DO if(setPos(random_x,random_y) >= setPos(400,500)) (Wall vs player)

     qDebug()<<" updated x: "<<random_x<<"y: " <<random_y;
//     setPos(450,450);
//     setRect(0,0,-50,30);                                                                 //negative Height and width will flip the figure
                                                                                        //PLAYER'S LOCATION WILL ALWAYS BE LOWER CENTER(400,500)
//     if(random_x<400 || random_x>500){ // wont spawn on character
//         random_x = 200;

//  qDebug()<<"INSIDE x: "<<random_x<<"y: " <<random_y;
//         setPos(random_x,random_y);

//         setRect(0,0,90,700);
//     }




    // connect
    QTimer * timer = new QTimer(this);

   connect(timer,SIGNAL(timeout()),this,SLOT(move())); // connect signal to object, bullet's constructor //every timeout bullet will move

   timer->start(25); //every 25 ms timeout signals move to move bullet

}



void Walls::move(){ //we also want different types of walls moving

//          setPos(x(),y()); //WILL MAKE WALS MOVE

    //when bullets move off the screen delete them waste of memoory
    if (pos().y() + rect().height() < 0 ){// 0 is origin for y (Topleft)// with rect().height()we now have that after the size of the
        scene() -> removeItem(this);
        delete this;
//        qDebug() << "Bullet dead";
    }

}
