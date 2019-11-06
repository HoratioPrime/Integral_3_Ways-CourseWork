#include "mainwindow.h"
#include <cmath>
#include <QtMath>



#include <QtCharts>
using namespace QtCharts;



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap bkgnd("/Users/Horatio/source/Integral_3_ways-CourseWork/img/integral-GUI_back.png");
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

    //Initialize scene with function by basic parameters
    sceneForFunc = new QGraphicsScene();
    sceneForFunc->addPixmap(QPixmap(fpack.getCurrentFunc().getPath().c_str()));
    ui->graphicsView->setScene(sceneForFunc);
    ui->graphicsView->scale(1.4,1.4);


    //Initialize scene with graphic of function by basic parameters
    Integral::scene = new QGraphicsScene(ui->graphic);
    Integral::scene->setSceneRect(0, 0, ui->graphic->width(), ui->graphic->height());
    ui->graphic->setScene(Integral::scene);
    Integral::cx = Integral::scene->width()/2;
    Integral::cy = Integral::scene->height()/2;
    Integral::pen = QPen(QColor().fromRgb(255,255,255));
    drawAxis();

    //Prev and next button
    ui->nextFunButton->setFlat(true);
    ui->prevFunButton->setFlat(true);



    //Set MainWindow stylesheet
   this->setStyleSheet(   "QGroupBox::title { color: #9b9b9b;} QGroupBox{border:none;}"
                          "QRadioButton{color: #ebebeb;}"
                          "QGraphicsView{background:transparent; border:none;}"
                          "QLineEdit{border:none; background-color: rgba(0, 0, 0, 0);}"
                      );


    //Starter Radio button activated
    ui->averageButton->setChecked(true);


    //Initialize base parameters for integral
    ui->aLineEdit->setText("0");
    ui->bLineEdit->setText("1");
    ui->cLineEdit->setText("1");
    ui->dLineEdit->setText("1");

    //Open file with past integrals
    //fileIntegrals.setFileName("./res/PastIntegrals.txt");

    ui->step->setText("1");

    ui->horizontalSlider->setTickInterval(10);
    ui->horizontalSlider->setRange(0,4);



    //Create first integral
    //and initialize them by starter function
    integrals.push_back(Integral());
    integrals.back().setFunc(fpack.getCurrentFunc().getFunc());



    //Testng....

    QChart* chart = new QChart();
    QLineSeries *series = new QLineSeries();
    series->setPen(QPen(QColor().fromRgb(41,98,255)));
    for (int i=-100;i<150; i++) series->append(i, i*i);
    chart->addSeries(series);
    chart->setTitle("QT Charts example");


    QValueAxis *axisX = new QValueAxis;
    axisX->setTickCount(10);
    axisX->setTitleText("X");
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis;
    axisY->setLabelFormat("%i");
    axisY->setTitleText("Y");
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    //ui->graphicsView->setScene(chartView);
    //ui->graphic->set;
    chartView->setGeometry(200, 100, 200, 100);
    chartView->show();



}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_equalButton_clicked()
{
    integrals[Integral::currentIdx].setParameters(
                ui->aLineEdit->text().toDouble(),
                ui->bLineEdit->text().toDouble(),
                ui->cLineEdit->text().toDouble(),
                ui->dLineEdit->text().toDouble()
                );
    integrals[Integral::currentIdx].setFunc(fpack.getCurrentFunc().getFunc());
    integrals[Integral::currentIdx].setIdxOfFunc(fpack.getCurrIdx());
    integrals[Integral::currentIdx].setStep(ui->step->text().toDouble());
    ui->label->setText(QString::number(integrals[Integral::currentIdx].execute(), 'd', 8));

    drawAxis();
    if(Integral::currentIdx == integrals.size() - 1)
    {
        integrals.push_back(Integral());
    }
}

void MainWindow::on_nextFunButton_clicked()
{
    fpack.next();
    sceneForFunc->clear();
    sceneForFunc->addPixmap(QPixmap(fpack.getCurrentFunc().getPath().c_str()));
}

void MainWindow::on_prevFunButton_clicked()
{
    fpack.prev();
    sceneForFunc->clear();
    sceneForFunc->addPixmap(QPixmap(fpack.getCurrentFunc().getPath().c_str()));
}

void MainWindow::on_averageButton_clicked()
{
    integrals.back().setMethod(METHOD::AVERAGE);
}

void MainWindow::on_simpsonButton_clicked()
{
    integrals.back().setMethod(METHOD::SIMPSON);
}

void MainWindow::on_newton_cotesButton_clicked()
{
    integrals.back().setMethod(METHOD::NEWTON_COTES);
}

void MainWindow::on_horizontalSlider_sliderMoved(int position)
{
    ui->step->setText(QString::number(1./pow(10.,position)));
}


void MainWindow::setIntegralsParametersToGUI()
{
    sceneForFunc->clear();
    ui->aLineEdit->setText(QString::number(integrals[Integral::currentIdx].getA()));
    ui->bLineEdit->setText(QString::number(integrals[Integral::currentIdx].getB()));
    ui->cLineEdit->setText(QString::number(integrals[Integral::currentIdx].getC()));
    ui->dLineEdit->setText(QString::number(integrals[Integral::currentIdx].getD()));
    ui->step->setText(QString::number(integrals[Integral::currentIdx].getH()));
    //ui->horizontalSlider->setTickPosition();

    if(Integral::currentIdx != integrals.size()-1)
        ui->label->setNum(integrals[Integral::currentIdx].getRes());
    else
        ui->label->setNum(0);

    switch(integrals[Integral::currentIdx].getMethod())
    {
        case METHOD::AVERAGE:
            ui->averageButton->setChecked(true);
        break;
        case METHOD::SIMPSON:
            ui->simpsonButton->setChecked(true);
        break;
        case METHOD::NEWTON_COTES:
            ui->newton_cotesButton->setChecked(true);
        break;
    }
    fpack.setCurrFunc(integrals[Integral::currentIdx].getIdxOfFunc());
    sceneForFunc->addPixmap(QPixmap(fpack.getCurrentFunc().getPath().c_str()));
}

void MainWindow::drawAxis()
{
    int cx = Integral::cx;
    int cy = Integral::cy;

    Integral::pen.setColor(QColor().fromRgb(81,81,81));
    Integral::scene->addLine(cx, 0, cx, cy*2, Integral::pen);
    Integral::scene->addLine(cx, 0, cx-4, 5, Integral::pen);
    Integral::scene->addLine(cx, 0, cx+4, 5, Integral::pen);

    Integral::scene->addLine(0, cy, cx*2, cy, Integral::pen);
    Integral::scene->addLine(2*cx, cy, 2*cx-5, cy-4, Integral::pen);
    Integral::scene->addLine(2*cx, cy, 2*cx-5, cy+4, Integral::pen);
    Integral::pen = QPen(QColor().fromRgb(255,255,255));
}


void MainWindow::on_left_clicked()
{
    if(Integral::currentIdx != 0)
    {
        Integral::currentIdx--;
        setIntegralsParametersToGUI();
    }
}



void MainWindow::on_right_clicked()
{
    if(Integral::currentIdx != integrals.size()-1)
    {
        Integral::currentIdx++;
        setIntegralsParametersToGUI();

    }
}
