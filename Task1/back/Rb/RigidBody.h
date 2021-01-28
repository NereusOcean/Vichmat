//
// Created by nereus on 18.12.2020.
//

#ifndef VMTRIANGLE_RIGIDBODY_H
#define VMTRIANGLE_RIGIDBODY_H
#include "../Matrix.h"
#include "../Vector.h"
#include "../Quaternion.h"
#include "../DynamicSystem.h"

//const double height = 2.4494897427832,length = 1.5;
//const double mass = 2;


class RigidBody: public DynamicSystem{
public:
    double height,length,mass;

    Matrix R;
    Vector r, l, L;
    Quaternion q;
    Matrix INERTIA_TENSOR;

    RigidBody operator=(DynamicSystem* A);
    DynamicSystem* f()override;
    RigidBody operator+(RigidBody A);
    RigidBody operator*(double h);
    RigidBody operator=(RigidBody* A);

    RigidBody(double height,double length,double mass);

};


#endif //VMTRIANGLE_RIGIDBODY_H
