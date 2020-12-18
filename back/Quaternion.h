//
// Created by nereus on 18.12.2020.
//

#ifndef VMTRIANGLE_QUATERNION_H
#define VMTRIANGLE_QUATERNION_H
#include "Matrix.h"
#include "cmath"

class Quaternion {
public:
    //Кватернион можно записать в виде 3 кординат, x,y,z. НО (как же без но ) там есть свои приколы связанные с мнимыми числами.
    double r;   // дополнение к этим трем кординатам добавляются 3 мнимых единицы.
    double i;   //i^2 = j^2 = k^2 = ijk = −1.
    double j;   //Целиком же это будет выглядеть так q = w + x*i + y*j + z*k
    double k;   //

    Quaternion operator*(Quaternion A) const;
    Quaternion operator*(double h) const;
    Quaternion operator+(Quaternion other) const;
    Matrix toMatrix() const;
    Quaternion normalize() const;
};

#endif //VMTRIANGLE_QUATERNION_H
