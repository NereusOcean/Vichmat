//
// Created by nereus on 20.01.2021.
//

#include "Newton.h"
#include <math.h>
#include <iostream>


Newton::Newton(double x0,double x1,double epsilon,double a){
    this->x0 = x0;
    this->x1 = x1;
    this-> accuracy = epsilon;
    this->a = a;
    if(!isRoot(x0,x1,a)){
        std::cout<<"There is no root!\n";
        system("pause");
        exit(1);
    }
}

double Newton::funcCalc(double x,double a){
    return pow(x,5)+x+a;
}
double Newton::funcCalcDerivative1(double x){
    return 5*x*x*x*x+1;

}
double Newton::funcCalcDerivative2(double x){
    return 20*x*x*x;

}


bool Newton::isRoot(double left, double right,double a){
    return funcCalc(left,a) * funcCalc(right,a) <= 0;
}

double Newton::solve(){
    double next, result;
    if(funcCalc(x0,a)*funcCalcDerivative2(x0) > 0 ){
        next = x0;
    }else{
        next = x1;
    }
    result = next - funcCalc(next,a)/funcCalcDerivative1(next);

    while(fabs(next - result)>accuracy){
        next = result;
        result = next - funcCalc(next,a)/funcCalcDerivative1(next);
    }
    return result;
}