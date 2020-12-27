//
// Created by nereus on 18.12.2020.
//

#ifndef VMTRIANGLE_RIGITBODY_H
#define VMTRIANGLE_RIGITBODY_H
#include "../Matrix.h"
#include "../Vector.h"
#include "../Quaternion.h"

const double height = sqrt(1.5),length = 3;
const double mass = 2;

class RigidBody {
public:
    Matrix R;
    Vector r, l, L;
    Quaternion q;
    Matrix INERTIA_TENSOR;

    RigidBody f() {
        RigidBody result;
        result.r = l * mass;
        R = q.toMatrix();
        Vector omega = ((R * INERTIA_TENSOR) * R.transpose()) * L;
        result.q = Quaternion{0, omega.x, omega.y, omega.z} * q * 0.5;
        result.l = Vector{0, 0, 0};
        result.L = Vector{0, 0, 0};
        return result;
    }

    RigidBody operator+(RigidBody A) const {
        RigidBody result;
        result.r = r + A.r;
        result.q = q + A.q;
        result.l = l + A.l;
        result.L = L + A.L;
        return result;
    }

    RigidBody operator*(double h) const {
        RigidBody result;
        result.r = r * h;
        result.q = q * h;
        result.l = l * h;
        result.L = L * h;
        return result;
    }

    RigidBody() {
        INERTIA_TENSOR = {0, 0, 0, 0, 0, 0, 0, 0, 0};
        INERTIA_TENSOR.values[0][0] = 1/((mass*length*length)/40+(3*mass*height*height)/80);
        INERTIA_TENSOR.values[1][1] = 1/((mass*length*length)/20);
        INERTIA_TENSOR.values[2][2] = 1/((mass*length*length)/40+(3*mass*height*height)/80);
        q = {1, 1, 0, 0};
        R = q.toMatrix();
        L = Vector{2000, -1000, 1000};
    }
};

#endif //VMTRIANGLE_RIGITBODY_H
