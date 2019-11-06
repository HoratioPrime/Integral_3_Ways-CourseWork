#include "mainwindow.h"
#include <QApplication>
#include "integral.h"
#include "functionpack.h"
#include <QSplashScreen>
#include <QThread>
//#include <QSound>





int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QCoreApplication::setApplicationName(QString("Integral 3 Ways"));
    //QSplashScreen splashsScreen(QPixmap("/Users/Horatio/source/Integral_3_ways-CourseWork1/img/intro.png"));
    //QSound sound("/Users/Horatio/source/Integral_3_ways-CourseWork1/sound/oxp.wav");
    MainWindow w;
    //splashsScreen.show();
    //QThread::sleep(3);
    //splashsScreen.hide();
    w.show();
    return a.exec();
}

