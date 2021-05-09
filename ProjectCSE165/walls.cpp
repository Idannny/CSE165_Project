
#include "Game.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <QGraphicsItem>
#include <QObject>
#include <QList>
#include <stdlib.h> //rand()

extern Score* score;
extern Game * game; //ALLOWS WALLS TO DESTROY PLAYER



extern  QGraphicsRectItem * rectangle1;
extern Button * my_button;
extern QGraphicsRectItem * rectangle2;


//extern  QGraphicsRectItem * rectangle3;


//t random_number2 = rand() % 800;\

//WE SHOULD HAVE ENEMY TURRETS

//############################################################
//Bug Found: whenever you shoot a wall on the left side of the screen... it cuts through the shape.
//###############################################################


Walls::Walls(QGraphicsItem *parent): QObject(), QGraphicsRectItem(parent){

    //eding a sound to reset with:

    resetSound = new QMediaPlayer();

    resetSound->setMedia(QUrl("qrc:/audio/zoom.wav"));



    //to generate the walls we see in the game:

    QTimer * timer = new QTimer(this);

    int random_number = rand() % 950;

    setPos(random_number,50);

    setRect(0,0,50,50);

    //     qDebug()<<"Wall 1 INSIDE x: "<<random_number<<"y: " <<y();
    //if(character picks up a )


    // connect signal to object, bullet's constructor //every timeout bullet will move


    if(game->score->getScore()>=0){ //if a player's score is 0:
        connect(timer,SIGNAL(timeout()),this,SLOT(moveDown()));
        timer->start(75);
        //every 75 ms timeout signals move to move bullet
    }

    //game gets a step harder when you get a point:

    if(game->score->getScore() >= 1){
        connect(timer,SIGNAL(timeout()),this,SLOT(moveLeft()));
        timer->start(105);
    }


    //    //WALLS
    //    // random spawn pos

    //     int random_x = rand() % 800; //create random enemy within screen
    //     int random_y = rand() % 800;

    //     qDebug()<<" ORIGINAL x: "<<random_x<<"y: " <<random_y;

    // //y first
    //     if(random_y < 500){ // if
    ////         qDebug()<<"INSIDE x: "<<random_x<<"y: " <<random_y;

    //            setPos(random_x,490);
    //          setRect(0,0,50,-400); //LOOK out for top boundary Deletion (reason why bullets delete)
    //     }

    //     if(random_y > 525){ // wont spawn boundaries on character and the goal so i need current coords of player and goal

    ////         qDebug()<<"INSIDE x: "<<random_x<<"y: " <<random_y;

    //          setPos(random_x,530);
    //          setRect(0,0,50,500);
    //     }                                      //REMEMBER random_x and Random_y are the corners of the rectangles so technically you make the pont before rect
    //                                            //MAYBE DO RANDOM COLORS

    //     if(random_x < 400){ //width of player

    ////         qDebug()<<"INSIDE x: "<<random_x<<"y: " <<random_y;

    //          setPos(390,random_y);
    //          setRect(0,0,-500,50);
    //     }
    //     if(random_x > 430){

    ////         qDebug()<<"INSIDE x: "<<random_x<<"y: " <<random_y;

    //          setPos(440,random_y); //WE CAN CHANGE SO IT ISNT AT THE NEAR EDGES OF THE PLAYER
    //          setRect(0,0,500,50);
    //     }



    //    //IN THEORY THIS IS WHATWE NEED TO DO if(setPos(random_x,random_y) >= setPos(400,500)) (Wall vs player)

    //     qDebug()<<" updated x: "<<random_x<<"y: " <<random_y;
    ////     setPos(450,450);
    ////     setRect(0,0,-50,30);                                                                 //negative Height and width will flip the figure
    //                                                                                        //PLAYER'S LOCATION WILL ALWAYS BE LOWER CENTER(400,500)
    ////     if(random_x<400 || random_x>500){ // wont spawn on character
    ////         random_x = 200;

    ////  qDebug()<<"INSIDE x: "<<random_x<<"y: " <<random_y;
    ////         setPos(random_x,random_y);

    ////         setRect(0,0,90,700);
    ////     }


    //code we have let go of:

    // connect(timer,SIGNAL(timeout()),this,SLOT(moveLeft()));
    // timer1->start(25);



    //     qDebug()<<"Moving first Block";
    //this->move();

    //setPos(x() + 5, y() + 0);

    // timer->start(250);

    // setPos(x() + 10, y() );

    //       qDebug()<<"After 1st block";

    /*
    //QTimer * timer2 = new QTimer(this);

       setPos(500,random_number2);
       setRect(0,0,100,100);
     qDebug()<<"Wall 2 INSIDE x: "<<500<<"y: " <<random_number2;
   //connect(timer2 ,SIGNAL(timeout()),this,SLOT(move2()));
   //timer2->start(25);

     this->move2();
   qDebug()<<"Test";

//}
*/



}



void Walls::moveDown(){ //we also want different types of walls moving


    QList<QGraphicsItem *> wallHitsPlayer = collidingItems();

    for (int i = 0, n = wallHitsPlayer.size(); i<n; i++){
        if(typeid(*(wallHitsPlayer[i])) == typeid(Player)){

            game->score->decrease();
            game->player->resetPlayer();

            if (resetSound->state() == QMediaPlayer::PlayingState){
                resetSound->setPosition(0);
            }

            else if (resetSound->state() == QMediaPlayer::StoppedState){ //this will decide when music will play
                resetSound->play();
            }


            delete this;

            return;//no memory errors
        }
    }



    setPos(x() , y() + 30);


    //when blocks move off the screen delete them waste of memoory
    if (pos().y() + rect().height() < 0 ){// 0 is origin for y (Topleft)// with rect().height()we now have that after the size of the
        scene() -> removeItem(this);
        delete this;
        qDebug() << "Bullet dead";
    }



} //end of move Down


void Walls::moveLeft(){ //we also want different types of walls moving

    setPos(x() + 50 ,y());


    setPos(x()+ 0, y() + 0);

    setRect(0,0,100,100);
    setPos(x() + 10,y() + 0);
    //rectangle2->setPos(x(),y()+ 10);

    /*
    //when bullets move off the screen delete them waste of memoory
    if (pos().y() + rect().height() < 0 ){// 0 is origin for y (Topleft)// with rect().height()we now have that after the size of the
        scene() -> removeItem(this);
        delete this;
//        qDebug() << "Bullet dead";
    }

    */
} //end of move Left
