#include "stageselect.h"

StageSelect::StageSelect()
{
    p1_loc_x = 100;
    p1_loc_y = 200;
    moving_state = 0;
    face_mode = 0;
    iter_num = 1;
    // Setting character frame
    p1 = new Player();
    p1->setPicture(":/character/bandit_0",0,0);
    p1->setZValue(1);
    p1->setPos(p1_loc_x,p1_loc_y);
    addItem(p1);
}

void StageSelect::bgSetting()
{
    // Add the sky
    QGraphicsPixmapItem *item = new QGraphicsPixmapItem();
    item->setPixmap(QPixmap(":/background/stage1_forests_1.bmp").scaled(this->width(),QPixmap(":/background/stage1_forests_1.bmp").height(),Qt::IgnoreAspectRatio));
    item->setPos(0,0);
    item->setZValue(-1);
    addItem(item);

    // Add the tree layer 1
    for(int i = 0 ; i < this->width() / QPixmap(":/background/stage1_forests_2").height() ; i++){
        QGraphicsPixmapItem *item_wrapper2 = new QGraphicsPixmapItem();
        item_wrapper2->setPixmap(QPixmap(":/background/stage1_forests_2"));
        item_wrapper2->setPos(i*QPixmap(":/background/stage1_forests_2").height(),2*QPixmap(":/background/stage1_forests_1.bmp").height()/3);
        item_wrapper2->setZValue(0);
        addItem(item_wrapper2);
    }

    // Add the tree layer 2
    for(int i = 0 ; i < this->width() / QPixmap(":/background/stage1_forests_2").height() ; i++){
        QGraphicsPixmapItem *item_wrapper2 = new QGraphicsPixmapItem();
        item_wrapper2->setPixmap(QPixmap(":/background/stage1_forests_2"));
        item_wrapper2->setPos(i*QPixmap(":/background/stage1_forests_2").height(),3*QPixmap(":/background/stage1_forests_1.bmp").height()/2);
        item_wrapper2->setZValue(0);
        addItem(item_wrapper2);
    }

    // Set the y_limit
    y_limit = 5*QPixmap(":/background/stage1_forests_1.bmp").height()/2;
}

void StageSelect::keyPressEvent(QKeyEvent *event)
{
    switch(event->key()){
    // Dealing the P1
    case Qt::Key_W:
        moving_state+=2*iter_num;
        character_moving(face_mode);
        p1_loc_y -= 5;
        break;
    case Qt::Key_S:
        moving_state+=2*iter_num;
        character_moving(face_mode);
        p1_loc_y += 5;
        break;
    case Qt::Key_A:
        moving_state+=2*iter_num;
        face_mode = 1;
        character_moving(face_mode);
        p1_loc_x -= 5;
        break;
    case Qt::Key_D:
        moving_state+=2*iter_num;
        face_mode = 0;
        character_moving(face_mode);
        p1_loc_x += 5;
        break;
    }

    if(moving_state >= 25 || moving_state < 0){
        iter_num = -iter_num;
    }
    boundary_checking();
    p1->setPos(p1_loc_x,p1_loc_y);
}

void StageSelect::character_moving(int mode)
{
    if(mode == 0){
        // face to right
        if(moving_state >= 1 && moving_state < 5)
            p1->setPicture(":/character/bandit_0",0,0);
        else if(moving_state >= 5 && moving_state < 10)
            p1->setPicture(":/character/bandit_0",320,0);
        else if(moving_state >= 10 && moving_state < 15)
            p1->setPicture(":/character/bandit_0",400,0);
        else if(moving_state >= 15 && moving_state < 20)
            p1->setPicture(":/character/bandit_0",480,0);
        else if(moving_state >= 20 && moving_state < 25)
            p1->setPicture(":/character/bandit_0",560,0);
    }
    else{
        if(moving_state >= 1 && moving_state < 5)
            p1->setPicture(":/character/bandit_0_mirror",720,0);
        else if(moving_state >= 5 && moving_state < 10)
            p1->setPicture(":/character/bandit_0_mirror",400,0);
        else if(moving_state >= 10 && moving_state < 15)
            p1->setPicture(":/character/bandit_0_mirror",320,0);
        else if(moving_state >= 15 && moving_state < 20)
            p1->setPicture(":/character/bandit_0_mirror",240,0);
        else if(moving_state >= 20 && moving_state < 25)
            p1->setPicture(":/character/bandit_0_mirror",160,0);
    }
}

void StageSelect::boundary_checking()
{
    if(p1_loc_x <=0)
        p1_loc_x = 0;
    else if(p1_loc_x >= this->width()-80)
        p1_loc_x = this->width()-80;
    if(p1_loc_y <= y_limit)
        p1_loc_y = y_limit;
    else if(p1_loc_y >= this->height()-80)
        p1_loc_y = this->height()-80;
}

QPointF StageSelect::getPlayerLoc()
{
    return QPointF(p1_loc_x,p1_loc_y);
}
