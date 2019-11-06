#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <vector>
#include "integral.h"
#include "functionpack.h"
#include "ui_mainwindow.h"

#include <QPainter>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void setIntegralsParametersToGUI();
    void drawAxis();

    ~MainWindow();

private slots:

    void on_equalButton_clicked();

    void on_nextFunButton_clicked();

    void on_prevFunButton_clicked();

    void on_averageButton_clicked();

    void on_simpsonButton_clicked();

    void on_newton_cotesButton_clicked();

    void on_horizontalSlider_sliderMoved(int position);

    void on_left_clicked();

    void on_right_clicked();

private:
    std::vector<Integral> integrals;
    FunctionPack fpack;
    QGraphicsScene* sceneForFunc;
    QFile fileIntegrals;


    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
