#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QString>
#include <QDebug>
#include "QMessageBox"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_left_2_editingFinished()
{
   QString tempLeft = ui->left_2->text();
  // if(isInteger(tempLeft)){
       left = tempLeft.toDouble();
   //}
}

void MainWindow::on_right_2_editingFinished()
{
    QString tempRight = ui->right_2->text();
   // if(isInteger(tempRight)){
        right = tempRight.toDouble();
   // }
}

void MainWindow::on_argument_2_editingFinished()
{
    QString tempA = ui->argument_2->text();
    //if(isInteger(tempA)){
        a = tempA.toDouble();
    //}
}

void MainWindow::on_epsilon_editingFinished()
{
    QString tempepsilon = ui->epsilon->text();
    //if(isInteger(tempA)){
        epsilon = tempepsilon.toDouble();
        //std::cout<<epsilon;
        qDebug() <<epsilon;
    //}
}

void MainWindow::on_pushButton_clicked()
{
    if(epsilon <= 1){
         b = new Bijection(left,right,epsilon,a);
        if(b->funcCalc(left,a) * b->funcCalc(right,a) <= 0){
          double e = b->solve();
          QString a = QString::number(e, 'd', 10);
           ui->resB->setText(a);
        }else  ui->resB->setText("Нету корня");
    }else{
        QMessageBox messageBox;
        messageBox.critical(0,"Error","Epsilon should be <= 1!");
    }

}

void MainWindow::on_pushButton_2_clicked(bool checked)
{
    if(epsilon <= 1){
        n = new Newton(left,right,epsilon,a);
     if(n->funcCalc(left,a) * n->funcCalc(right,a) <= 0){
          double e = n->solve();
          QString a = QString::number(e, 'd', 10);
          ui->resN->setText(a);
     }else  ui->resN->setText("Нету корня");
    }else{
        QMessageBox messageBox;
        messageBox.critical(0,"Error","Epsilon should be <= 1!");
    }

}

void MainWindow::on_pushButton_3_clicked()
{
   // Func funcShow;
   // funcShow.setModal(true);
   // funcShow.exec();
    if(epsilon <= 1){
        funcShow = new Func(this);

         funcShow->leftX = -10;
         funcShow->rightX = 10;
         if(a>34){
             funcShow->rightY = 10;
             funcShow->leftY = -10;
         }else{
             funcShow->rightY = a+1;
             funcShow->leftY = -a-1;
         }

         funcShow->argument = a;
     funcShow->LimitedLeft = left;
     funcShow->LimitedRight = right;
     funcShow->step = epsilon;

     funcShow->show();
     funcShow->recountPixels();
     funcShow->drawGraph(1);

    }else{
        QMessageBox messageBox;
        messageBox.critical(0,"Error","Epsilon should be <= 1!");
    }


}
