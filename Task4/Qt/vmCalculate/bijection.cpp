#include "bijection.h"

#include <iostream>
#include <math.h>

Bijection::Bijection(double x0,double x1,double epsilon,double a0){
    this->x0 = x0;
    this->x1 = x1;
    this-> accuracy = epsilon;
    this->a = a0;
    if(!isRoot(x0,x1,a)){
        std::cout<<"There is no root!\n";

    }
}

double Bijection::funcCalc(double x,double a){
    return pow(x,5)+x+a;
}

bool Bijection::isRoot(double left, double right,double a){
    return funcCalc(left,a) * funcCalc(right,a) <= 0;
}

double Bijection::solve(){
    double  tempLeft = x0;
    double  tempRight = x1;
    double  center = tempLeft + (tempRight-tempLeft)/2;
    //std::cout<<tempRight -tempLeft;
    while((tempRight - tempLeft > accuracy)){
        if(isRoot(tempLeft, center,a)){
            tempRight = center;
        }else {
            tempLeft = center;
        }
        center = tempLeft + (tempRight - tempLeft)/2;
    }
    return center;
}
