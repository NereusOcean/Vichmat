#include <iostream>
#include "Methods/Bijection/Bijection.h"
#include "Methods/Newton/Newton.h"
#include "iomanip"
int main() {
    double left, right, parameter, epsilon, solve;

    std::cout<<"Enter the left border:\n";
    std::cin>>left;
    std::cout<<"Enter the right border:\n";
    std::cin>>right;
    std::cout<<"Enter equation parameter(a) - x^5 + x + a = 0:\n";
    std::cin>>parameter;
    std::cout<<"Epsilon:\n";
    std::cin>>epsilon;
    std::cout<<"Root of the equation x^5 + x + "<<parameter<< ", with accuracy "<<epsilon<<"\n";
    Bijection b(left,right,epsilon,parameter);
    solve = b.solve();
    std::cout<<"Bijection: "<<std::setprecision(25)<<b.solve()<<"\n";
    Newton n(left,right,epsilon,parameter);
    solve = n.solve();
    std::cout<<"Newton: "<<std::setprecision(25)<<n.solve();
    return 0;
}
