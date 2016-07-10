#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QImage>
#include <QTimer>
#include <stageselect.h>
#include <iostream>

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void init_screen();
    ~MainWindow();

public slots:
    void spot_character();

private:
    Ui::MainWindow *ui;
    StageSelect *scene;
    QTimer *man_timer;
};

#endif // MAINWINDOW_H
