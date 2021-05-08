#include "Game.h"
#include <QFont>

Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent)
{ // this will have a parent too
    score = 0;

    //draw text //onlyworks when cpp has Qgraphics text Item
    setPlainText("Score: " + QString::number(score));
    setDefaultTextColor(Qt::black);

    setFont(QFont("Times New Roman", 20));
}

void Score::increase()
{
    score++;
     setPlainText(QString("Score: ") + QString::number(score)); // Score: 1

     //lets increase when we hit the circle?
}

int Score::getScore()
{
    return score;
}
