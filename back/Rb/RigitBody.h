//
// Created by nereus on 18.12.2020.
//

#ifndef VMTRIANGLE_RIGITBODY_H
#define VMTRIANGLE_RIGITBODY_H
#include "../Matrix.h"
#include "../Vector.h"
#include "../Quaternion.h"

const double height = sqrt(1.5),length = 3;
const double mass = 0.1;

class RigidBody {
public:
    Matrix R;
    Vector r, l, L;
    Quaternion q;
    Matrix INERTIA_TENSOR;

    RigidBody();
    RigidBody f();
    RigidBody operator+(RigidBody A) const;
    RigidBody operator*(double h) const;
};

#endif //VMTRIANGLE_RIGITBODY_H
