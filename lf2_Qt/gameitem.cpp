#include "gameitem.h"

GameItem::GameItem()
{

}

void GameItem::setPicture(const QString str, int w, int h)
{
    setPixmap(QPixmap(str).copy(w,h,80,80));
}

void GameItem::action()
{

}
