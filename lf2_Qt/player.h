#ifndef PLAYER_H
#define PLAYER_H

#include <gameitem.h>

class Player : public GameItem
{
public:
    Player();
    void action();
};

#endif // PLAYER_H
