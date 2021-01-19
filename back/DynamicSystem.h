//
// Created by nereus on 30.12.2020.
//

#ifndef VMTRIANGLE_DYNAMICSYSTEM_H
#define VMTRIANGLE_DYNAMICSYSTEM_H
#include "Vector.h"
#include "Matrix.h"
#include "Quaternion.h"

class DynamicSystem{
public:
    Matrix R;
    Vector r, l, L;
    Quaternion q;
    Matrix INERTIA_TENSOR;

   // virtual void Construct(DynamicSystem res,double mass,double length,double height) ;
    virtual DynamicSystem* f() = 0;

};

#endif //VMTRIANGLE_DYNAMICSYSTEM_H
