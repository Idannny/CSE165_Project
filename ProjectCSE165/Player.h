#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsRectItem>
#include <QGraphicsItem>
#include <QObject>

class Player: public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
        Player(QGraphicsItem * parent=0); // now our item is a pointer we can manipulate
    void keyPressEvent(QKeyEvent * event);

public slots:
    void spawn(); //spawn is an event that will be created by extension
};

#endif // PLAYER_H
