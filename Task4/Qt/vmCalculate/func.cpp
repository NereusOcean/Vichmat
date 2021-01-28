#include "func.h"
#include "ui_func.h"
#include <cmath>
#include <QDebug>
using namespace std;


Func::Func(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Func)
{
    ui->setupUi(this);
    pictHeight = 370; // задаем высоту картинки
       pictWidth = 540; // и её ширину
       step = 0.1; // задаем начальный шаг
       leftX = -100; rightX = 100; // и начальные значения границ
       leftY = -100; rightY = 100;
       drawGraph(); // сразу же отрисовываем пустой график
}

double Func::f(double x, double a){
    return pow(x,5)+x+a;
}

void Func::recountPixels()
{
    onePixelX = 540.0/(rightX-leftX);
    onePixelY = 370.0/(rightY-leftY);
    Ox = fabs(leftX); Oy = rightY;
}

void Func::drawGraph(bool notEmpty)
{
    QPixmap graph(540,370); // создаем саму картинку
       QPainter paint; // и пэинтер
       paint.begin(&graph); // запускаем отрисовку
       paint.eraseRect(0,0,540,370); // очищаем рисунок
       paint.drawLine(Ox*onePixelX,0,Ox*onePixelX,pictHeight); // и рисуем координатные оси
       paint.drawLine(0,Oy*onePixelY,pictWidth,Oy*onePixelY);

       paint.setPen(QPen(Qt::black,3)); // устанавливаем цвет и толщину "пера"
       for(double i = leftX;i<=rightX;i+=1.0) // рисуем черточки на координатой оси
           if(i == LimitedLeft || i == LimitedRight){
               paint.setPen(QPen(Qt::green,6));
               paint.drawPoint((i+Ox)*onePixelX,Oy*onePixelY);
               paint.setPen(QPen(Qt::black,3));
           }else paint.drawPoint((i+Ox)*onePixelX,Oy*onePixelY);

       for(double i = leftY;i<=rightY;i+=1.0)
           paint.drawPoint(Ox*onePixelX,(Oy-i)*onePixelY);

       // если мы не рисуем график, то отображаем координатную ось и выключаемся
       if(!notEmpty) {
           paint.end();
           ui->outputGraph->setPixmap(graph);
           return;
       }
       paint.setPen(QPen(Qt::green,1,Qt::SolidLine)); // снова задаем цвет и тип линии
           paint.setRenderHint(QPainter::Antialiasing, true); // задаем параметры рендеринга
           QPainterPath path,p[3]; // QPainterPath означаем, что мы вначале занесем все необходимые точки, а затем соединим их
           bool first[4] = {1,1,1,1}; // узнаем первая ли точка, или надо сдвигаться

           // последовательно проходимся по всем точкам графика, проверяем, существует ли функция в данной точке, и если существует -- заносим точку в массив отрисовки

           for(double i = (double)leftX+step;i<=(double)rightX;i+=step) {
               if(!isnan(f(i,argument))) {
                   if(first[0]) {
                       path.moveTo((i+Ox)*onePixelX,Oy-(f(i,argument))*onePixelY);
                       first[0] = false;
                   }
                   else
                       path.lineTo((i+Ox)*onePixelX,(Oy-f(i,argument))*onePixelY);
               }
           }

           paint.setPen(QPen(Qt::blue,1,Qt::SolidLine));
           paint.drawPath(path);
           paint.end(); // заканчиваем рисование
           ui->outputGraph->setPixmap(graph); // и помещаем рисунок на форму
           return;

}
Func::~Func()
{
    delete ui;
}
