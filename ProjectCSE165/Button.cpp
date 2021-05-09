//#include "Button.h" //including our button header file
#include "Game.h"

extern Game * game;
extern QMouseEvent * press;
extern QGraphicsItem * player;

Button::Button(QPushButton *parent): QPushButton(parent){
    //creating the button:

    my_button = new QPushButton("Reset", this); //"this" is the parent of the button now

    //setting the size and location of the button:

    my_button->setGeometry(QRect(QPoint(100,100) , QSize(100, 100))); //a rectangle at point (0,0) and size (100x100)


    //connecting the button signal to the appropiate slot:

     connect(my_button, &QPushButton::clicked, this, &Button::resetPosition);

 qDebug()<<"button clicked";


} //end of main button definition

//creating a function for the event of the button:



void Button::resetPosition(){

          qDebug()<<"button clicked";

   // connect(my_button,SIGNAL(clicked()),player, SLOT(handleButton()));

     game->player->setPos(500, 600); //so the player in game, movesd to the desired position

        connect(my_button, &QPushButton::released, this, &Button::handleButton);



    //game->releaseMouse();

    //game->update();

}

void Button::handleButton(){

    //change the text
 qDebug()<<"button clicked";
    my_button->setText("Reset Again?");



   // player = new Player();


    //resize the Button:
    my_button->resize(100, 100);

    player = new Player();
    Player(keyPressEvent()); //trying to fix the error where if i click it doesnt let me use the keyboard...

    //my_button->resetPosition();

    //connect(my_button, &QPushButton::clicked, player, &Button::resetPosition);
   //QPushButton::connect(my_button,SIGNAL(clicked), player, SLOT(resetPosition()));

    //can we change the position of the player?

    //game = new Game();
   // game->show();


}
