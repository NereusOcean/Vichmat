//
// Created by nereus on 20.01.2021.
//

#ifndef SLY_NEWTON_H
#define SLY_NEWTON_H


class Newton {
 private:
    double x0,x1,a;
    double accuracy;
public:
    Newton(double x0,double x1,double epsilon,double a);
    double funcCalc(double x,double a);
    double funcCalcDerivative2(double x);
    double funcCalcDerivative1(double x);
    bool isRoot(double left, double right,double a);

    double solve();
};


#endif //SLY_NEWTON_H
