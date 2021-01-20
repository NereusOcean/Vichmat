//
// Created by nereus on 20.01.2021.
//

#ifndef SLY_BIJECTION_H
#define SLY_BIJECTION_H


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


#endif //SLY_BIJECTION_H
