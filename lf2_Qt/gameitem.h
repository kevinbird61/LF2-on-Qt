#ifndef GAMEITEM_H
#define GAMEITEM_H

#include <QGraphicsPixmapItem>
#include <QPixmap>

class GameItem : public QGraphicsPixmapItem
{
public:
    GameItem();
    void setPicture(const QString str, int w , int h );
    virtual void action();
};

#endif // GAMEITEM_H
