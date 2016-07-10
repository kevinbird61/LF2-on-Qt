#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new StageSelect();
    scene->setSceneRect(0,0,this->width(),5*this->height()/6);

    QImage bg;
    bg.load(":/background/stage1_land1.bmp");
    bg.scaled(this->width(),this->height());
    scene->setBackgroundBrush(bg);
    ui->graphicsView->setScene(scene);
    scene->bgSetting();
    man_timer = new QTimer(this);
    connect(man_timer , SIGNAL(timeout()) , this , SLOT(spot_character()));
    man_timer->start(10);

    init_screen();
}

void MainWindow::init_screen()
{
    ui->man1_health->setValue(100);
    ui->man1_mana->setValue(100);
    ui->man2_health->setValue(0);
    ui->man2_mana->setValue(0);
    ui->man3_health->setValue(0);
    ui->man3_mana->setValue(0);
    ui->man4_health->setValue(0);
    ui->man4_mana->setValue(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::spot_character()
{
    ui->graphicsView->centerOn(scene->getPlayerLoc());
}
