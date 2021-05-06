
#ifndef BUTTON_H
#define BUTTON_H

#include <QPushButton>



//#include <QMainWindow>

#include "Player.h"


class Button: public QPushButton , virtual public Player{ //to ensure there is only one Player object

public:

    //https://wiki.qt.io/How_to_Use_QPushButton -- on how to create and use the pushButton feature in Qt
     Button(QPushButton * parent = nullptr); //member object of Button (class) -- as to not to convert between constructors

private slots:
    void handleButton();
private:

    QPushButton * my_button;




//    void isClicked();
//    int getScore();
//private:
//    int score;

};
#endif // BUTTON_H
