#include "mainwindow.h"
#include <cmath>
#include <QtMath>
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    method = METHOD::AVERAGE;

    QPixmap bkgnd("/Users/Horatio/source/Integral_3_ways-CourseWork/img/mainUI/integral-GUI_back2.png");
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

    //Initialize scene with function by basic parameters
    sceneForFunc = new QGraphicsScene();
    sceneForFunc->addPixmap(QPixmap(fpack.getCurrentFunc().getPath().c_str()));
    ui->graphicsView->setScene(sceneForFunc);

    //ui->tryInImage->setScaledContents(true);


    ui->graphicsView->scale(2, 2);

    sceneForPrevFunc = new QGraphicsScene();
    //sceneForPrevFunc->setBackgroundBrush(QBrush(QColor().fromRgb(37,37,37)));
    ui->prevFunc->setScene(sceneForPrevFunc);
    ui->prevFunc->scale(1.4, 1.4);

    //Graphic

    ui->graphic->setChart(graphic.getChartView()->chart());
    ui->graphic->setBackgroundBrush(QBrush(QColor().fromRgb(37,37,37)));
    ui->graphic->show();

    //Prev and next func buttons
    ui->nextFunButton->setIcon(QIcon("/Users/Horatio/source/Integral_3_ways-CourseWork/img/left-right-button/Asset_right_button@3x.png"));
    ui->prevFunButton->setIcon(QIcon("/Users/Horatio/source/Integral_3_ways-CourseWork/img/left-right-button/Asset_left_button@3x.png"));
    ui->nextFunButton->setFlat(true);
    ui->prevFunButton->setFlat(true);
    //ui->textBrowser->setTextBackgroundColor();

    //Prev and next integral buttons
    ui->left->setEnabled(false);
    ui->right->setEnabled(false);


    //Set MainWindow stylesheet
   this->setStyleSheet(   "QGroupBox::title { color: #9b9b9b;} QGroupBox{border:none;}"
                          "QRadioButton{color: rgb(37,37,37);}"
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
    fileIntegrals.setFileName("/Users/Horatio/source/Integral_3_ways-CourseWork/res/PastIntegrals.txt");
    //fileIntegrals.open(QIODevice::ReadWrite);

    //Setup for slider
    ui->step->setText("1");
    ui->horizontalSlider->setTickInterval(10);
    ui->horizontalSlider->setRange(0,4);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_equalButton_clicked()
{
    if(Integral::currentIdx != -1)
    {
        ui->left->setEnabled(true);
    }

    ui->right->setEnabled(false);
    integrals.push_back(Integral());
    Integral::currentIdx = integrals.size()-1;
    ui->sizeOfVector->setNum(int(integrals.size()));

    integrals[Integral::currentIdx].setParameters(
                ui->aLineEdit->text().toDouble(),
                ui->bLineEdit->text().toDouble(),
                ui->cLineEdit->text().toDouble(),
                ui->dLineEdit->text().toDouble()
                );
    integrals[Integral::currentIdx].setMethod(method);
    integrals[Integral::currentIdx].setFunc(fpack.getCurrentFunc().getFunc());
    integrals[Integral::currentIdx].setIdxOfFunc(fpack.getCurrIdx());
    integrals[Integral::currentIdx].setStep(ui->step->text().toDouble());

    ui->label->setText(QString::number(integrals[Integral::currentIdx].execute(), 'd', 8));

    setIntegralsParametersToGUI();

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
    //integrals.back().setMethod(METHOD::AVERAGE);
    method = METHOD::AVERAGE;
}

void MainWindow::on_simpsonButton_clicked()
{
    //integrals.back().setMethod(METHOD::SIMPSON);
     method = METHOD::SIMPSON;
}

void MainWindow::on_newton_cotesButton_clicked()
{
    //integrals.back().setMethod(METHOD::NEWTON_COTES);
     method = METHOD::NEWTON_COTES;
}

void MainWindow::on_horizontalSlider_sliderMoved(int position)
{
    ui->step->setText(QString::number(1./pow(10.,position)));}

void MainWindow::setIntegralsParametersToGUI()
{
    sceneForPrevFunc->clear();

    ui->prevA->setText(QString::number(integrals[Integral::currentIdx].getA()));
    ui->prevB->setText(QString::number(integrals[Integral::currentIdx].getB()));
    ui->prevC->setText(QString::number(integrals[Integral::currentIdx].getC()));
    ui->prevD->setText(QString::number(integrals[Integral::currentIdx].getD()));
    ui->prevPrecision->setText(QString::number(integrals[Integral::currentIdx].getH()));
    ui->qOfIter->setText(QString::number(integrals[Integral::currentIdx].getN()));


    ui->currNum->setNum(Integral::currentIdx + 1);
    ui->label->setNum(integrals[Integral::currentIdx].getRes());

    sceneForPrevFunc->addPixmap(
                QPixmap(fpack.getFuncByIdx(integrals[Integral::currentIdx].getIdxOfFunc()).getWhitePath().c_str()));

    drawFunc();

    switch(integrals[Integral::currentIdx].getMethod())
    {
        case METHOD::AVERAGE:
            ui->prevMeth->setText("Средних");
        break;
        case METHOD::SIMPSON:
            ui->prevMeth->setText("Симпсона");
        break;
        case METHOD::NEWTON_COTES:
            ui->prevMeth->setText("Ньютона-Котеса");
        break;
    }
}

void MainWindow::setDefaultPrevGUI()
{
    sceneForPrevFunc->clear();

    ui->prevA->setText(QString::number(0));
    ui->prevB->setText(QString::number(0));
    ui->prevC->setText(QString::number(0));
    ui->prevD->setText(QString::number(0));
    ui->qOfIter->setText(QString::number(0));
    ui->prevPrecision->setText(QString::number(0));
    ui->qOfIter->setText(QString::number(0));
    ui->prevMeth->setText("-");

    ui->currNum->setNum(0);
    ui->sizeOfVector->setNum(0);
    ui->label->setNum(0);

    graphic.removeSeries();
    graphic.settleDownAxis();

}

void MainWindow::drawFunc()
{
    graphic.removeSeries();
    integrals[Integral::currentIdx].constructSeries();
    graphic.settleDownAxis();
    graphic.addSeries(integrals[Integral::currentIdx].getSeries());
}

void MainWindow::on_left_clicked()
{
    if(Integral::currentIdx != 0)
    {
        Integral::currentIdx--;

    }
    if(Integral::currentIdx == 0)
    {
        ui->left->setEnabled(false);
    }else{
        ui->left->setEnabled(true);
    }
    ui->right->setEnabled(true);
    setIntegralsParametersToGUI();
}

void MainWindow::on_right_clicked()
{
    if(Integral::currentIdx != integrals.size()-1)
    {
        Integral::currentIdx++;       
    }
    if(Integral::currentIdx == integrals.size()-1)
    {
        ui->right->setEnabled(false);
    }else{
        ui->right->setEnabled(true);
    }
    ui->left->setEnabled(true);
    setIntegralsParametersToGUI();
}

void MainWindow::on_exitButton_clicked()
{
    fileIntegrals.close();
    close();
}

void MainWindow::on_Clear_clicked()
{
    if(integrals.size() > 1)
    {
        integrals.erase(integrals.begin() + Integral::currentIdx);
        if(Integral::currentIdx == integrals.size())
        {
            Integral::currentIdx--;
        }
        setIntegralsParametersToGUI();
    }else
    {
        integrals.pop_back();
        setDefaultPrevGUI();
        setDefaultPrevGUI();
        Integral::currentIdx = -1;
    }
    if(integrals.size() < 2)
    {
        ui->left->setEnabled(false);
        ui->right->setEnabled(false);
    }
    ui->sizeOfVector->setNum(int(integrals.size()));
}

void MainWindow::on_ClearAll_clicked()
{
    integrals.clear();
    ui->left->setEnabled(false);
    ui->right->setEnabled(false);
    setDefaultPrevGUI();
    Integral::currentIdx = -1;
    //integrals.push_back(Integral());
    //ui->sizeOfVector->setNum(int(integrals.size()));
    //setIntegralsParametersToGUI();
}

void MainWindow::on_SAVE_clicked()
{
    fileIntegrals.open(QIODevice::WriteOnly);
    if(fileIntegrals.isOpen())
    {
        fileIntegrals.resize(0);
        QTextStream stream(&fileIntegrals);
        //stream << integrals.size() << endl;
        foreach (auto integral, integrals)
        {
           stream << QString::number(integral.getA()) << ' ';
           stream << QString::number(integral.getB()) << ' ';
           stream << QString::number(integral.getC()) << ' ';
           stream << QString::number(integral.getD()) << ' ';
           stream << QString::number(integral.getH()) << ' ';
           stream << QString::number(integral.getIdxOfFunc()) << ' ';
           switch(integral.getMethod())
           {
            case METHOD::AVERAGE:
               stream << QString::number(0);
               break;
           case METHOD::SIMPSON:
              stream << QString::number(1);
              break;
           case METHOD::NEWTON_COTES:
              stream << QString::number(2);
              break;
           }
           stream << endl;
        }
        fileIntegrals.close();
    }

}

void MainWindow::on_LOAD_clicked()
{
    fileIntegrals.open(QIODevice::ReadOnly);
    if(fileIntegrals.isOpen())
    {
        QTextStream stream(&fileIntegrals);
        integrals.clear();
        double a;
        double b;
        double c;
        double d;
        double h;
        short idxOfF;
        int meth;

        while(!stream.atEnd())
        {
            stream >> a >> b >> c >> d >> h >> idxOfF >> meth;
            integrals.push_back(Integral());
            integrals.back().setParameters(a, b, c, d);
            integrals.back().setStep(h);
            integrals.back().setIdxOfFunc(idxOfF);
            switch(meth)
            {
                case 0:
                integrals.back().setMethod(METHOD::AVERAGE);
                break;
                case 1:
                integrals.back().setMethod(METHOD::SIMPSON);
                break;
                case 2:
                integrals.back().setMethod(METHOD::NEWTON_COTES);
                break;
            }
            integrals.back().setFunc(fpack.getFuncByIdx(idxOfF).getFunc());
            integrals.back().execute();
            stream.readLine();
        }
        if(integrals.size() > 0)
        {
            Integral::currentIdx = 0;
            ui->left->setEnabled(false);
            if(integrals.size() > 1)
            {
                ui->right->setEnabled(true);
            }else
            {
                ui->right->setEnabled(false);
            }
            ui->sizeOfVector->setNum(int(integrals.size()));
            setIntegralsParametersToGUI();
        }

        fileIntegrals.close();
    }
}
