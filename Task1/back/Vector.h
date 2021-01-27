//
// Created by nereus on 18.12.2020.
//

#ifndef VMTRIANGLE_VECTOR_H
#define VMTRIANGLE_VECTOR_H

class Vector {
public:
    double x;
    double y;
    double z;


    Vector operator*(double h) const {
        Vector result;
        result.x = x * h;
        result.y = y * h;
        result.z = z * h;
        return result;
    }

    Vector operator+(Vector other) const {
        Vector result;
        result.x = x + other.x;
        result.y = y + other.y;
        result.z = z + other.z;
        return result;
    }

    double operator*(Vector h) const {
        double result = 0;
        result += x *h.x;
        result += y * h.y;
        result += z * h.z;
        return result;
    }
 /*   Vector operator=(Vector other) const{
        Vector result;
        result.x = other.x;
        result.y = other.y;
        result.z = other.z;
        return result;
    }*/

};

#endif //VMTRIANGLE_VECTOR_H
