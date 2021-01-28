#include "mainwindow.h"
#include <QApplication>
class main2{
public:
    double left, right, parameter, epsilon, solve;
     //Bijection b(left,right,epsilon,parameter);
    // solve = b.solve();
       // std::cout<<std::setprecision(25)<<b.solve();;
};
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
