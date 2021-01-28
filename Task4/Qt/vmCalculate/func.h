#ifndef FUNC_H
#define FUNC_H

#include <QDialog>
#include <QtGui>

namespace Ui {
class Func;
}

class Func : public QDialog
{
    Q_OBJECT

public:
    explicit Func(QWidget *parent = 0);
    ~Func();
    void drawGraph(bool notEmpty = 0);
    void recountPixels(); // в зависимости от точности (об этом позже) считаем количество пикселей на один условный сантиметр
        void getData(); // получаем значения границ графика и точности
        double f(double x, double a); // первая функция
 double leftX,rightX; // границы по х
  double step; // шаг (точность)
  double leftY,rightY; // границы по у
  double LimitedLeft,LimitedRight;
  double argument;
private:
    Ui::Func *ui;


        int pictWidth,pictHeight; // ширина и высота картинки

            double onePixelX,onePixelY; // количество пикселей на шаг
            double Ox,Oy; // координаты центра
};

#endif // FUNC_H
