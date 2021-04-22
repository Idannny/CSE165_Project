#ifndef CHARACTERMOD_H
#define CHARACTERMOD_H

#include <QGraphicsRectItem>


class characterOne :public QGraphicsRectItem{
public:
    void keyPressEvent(QKeyEvent*event);
};


#endif // CHARACTERMOD_H
