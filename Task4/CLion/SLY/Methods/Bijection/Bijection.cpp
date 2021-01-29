//
// Created by nereus on 20.01.2021.
//

#include "Bijection.h"
#include <iostream>
#include <math.h>

Bijection::Bijection(double x0,double x1,double epsilon,double a){
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
    double stop =-1;
    bool hey;
    //std::cout<<tempRight -tempLeft;
    while((tempRight - tempLeft > accuracy)){
        if(isRoot(tempLeft, center,a)){
            tempRight = center;
            hey=true;
        }else {
            tempLeft = center;
            hey=false;
        }
        center = tempLeft + (tempRight - tempLeft)/2;
        if(hey == true){
            if(stop == fabs(tempRight - center)){
                break;
            }
            stop = fabs(tempRight - center);
        }else{
            if(stop == fabs(tempLeft - center)){
                break;
            }
            stop = fabs(tempLeft - center);
        }
    }
    return center;
}