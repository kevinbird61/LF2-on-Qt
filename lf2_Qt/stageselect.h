#ifndef STAGESELECT_H
#define STAGESELECT_H

#include <QGraphicsScene>
#include <QWidget>
#include <player.h>
#include <QKeyEvent>
#include <QDebug>

class StageSelect : public QGraphicsScene
{
public:
    StageSelect();
    void bgSetting();
    void keyPressEvent(QKeyEvent *event);
    void character_moving(int mode);
    void boundary_checking();
    QPointF getPlayerLoc();
private:
    Player *p1;
    int p1_loc_x;
    int p1_loc_y;
    int y_limit;
    int moving_state;
    int face_mode;
};

#endif // STAGESELECT_H
