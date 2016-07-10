#include "mainwindow.h"
#include <QApplication>
#include <QDesktopWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QDesktopWidget wid;
    // ============= Moving the window to center of screen =============
    w.setGeometry(wid.screen()->width()/2 - (w.width()/2) , wid.screen()->height()/2 - (w.height()/2) , w.width() , w.height());
    // ============= Disable scaling size =============
    w.setFixedSize(w.width(),w.height());
    // ============= Setting the icon and name =============
    w.setWindowIcon(QIcon("Image/icon/lf2-icon.png"));
    w.setWindowTitle("LF2 on Qt");
    w.show();

    return a.exec();
}
