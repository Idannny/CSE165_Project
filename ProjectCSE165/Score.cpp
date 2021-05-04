#include "Score.h"
#include <QFont>

Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent)
{ // this will have a parent too
    score = 0;

    //draw text //onlyworks when cpp has Qgraphics text Item
    setPlainText("Score: " + QString::number(score));
    setDefaultTextColor(Qt::blue);

    setFont(QFont("times", 16));
}

void Score::increase()
{
    score++;
     setPlainText(QString("Score: ") + QString::number(score)); // Score: 1
}

int Score::getScore()
{
    return score;
}
