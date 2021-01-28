#ifndef BIJECTION_H
#define BIJECTION_H


class Bijection {
private:
    double x0,x1,a;
    double accuracy;
public:
    Bijection(double x0,double x1,double epsilon,double a);
    double funcCalc(double x,double a);
    bool isRoot(double left, double right,double a);

    double solve();
};



#endif // BIJECTION_H
