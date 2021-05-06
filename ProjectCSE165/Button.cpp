//#include "Button.h" //including our button header file
#include "Game.h"



Button::Button(QPushButton *parent): QPushButton(parent){
    //creating the button:

    my_button = new QPushButton("Reset", this); //"this" is the parent of the button now

    //setting the size and location of the button:

    my_button->setGeometry(QRect(QPoint(0,0) , QSize(100, 100))); //a rectangle at point (0,0) and size (100x100)


    //connecting the button signal to the appropiate slot:

    connect(my_button, &QPushButton::released, this, &Button::handleButton);



} //end of main button definition

//creating a function for the event of the button:

void Button::handleButton(){

    //change the text
    my_button->setText("Something happens");

    //resize the Button:
    my_button->resize(100, 100);

    //can we change the position of the player?

    //game = new Game();
   // game->show();


}
