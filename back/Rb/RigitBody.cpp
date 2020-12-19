//
// Created by nereus on 18.12.2020.
//
#include "RigitBody.h"

RigidBody RigidBody::f() {
    RigidBody result;
    result.r = l * mass;
    R = q.toMatrix();
    Vector omega = ((R * INERTIA_TENSOR) * R.transpose()) * L;
    result.q = Quaternion{0, omega.x, omega.y, omega.z} * q * 0.5;
    result.l = Vector{0, 0, 0};
    result.L = Vector{0, 0, 0};
    return result;
}

RigidBody RigidBody::operator+(RigidBody A) const {
    RigidBody result;
    result.r = r + A.r;
    result.q = q + A.q;
    result.l = l + A.l;
    result.L = L + A.L;
    return result;
}

RigidBody RigidBody::operator*(double h) const {
    RigidBody result;
    result.r = r * h;
    result.q = q * h;
    result.l = l * h;
    result.L = L * h;
    return result;
}
/*INERTIA_TENSOR.values[0][0] = 3/(4*height/1.5);
INERTIA_TENSOR.values[1][1] = 3/(4*(1.5*height*height*height)/12);
INERTIA_TENSOR.values[2][2] = 3/(4*(1.5*height*height*height)/12);*/
RigidBody::RigidBody() {
    INERTIA_TENSOR = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    INERTIA_TENSOR.values[0][0] = 2/(height/length);
 INERTIA_TENSOR.values[1][1] = 2/((length*height*height*height)/12);
 INERTIA_TENSOR.values[2][2] = 2/((length*height*height*height)/12);
    q = {1, 1, 0, 0};
    R = q.toMatrix();
    L = Vector{2000, -1000, 1000};
}
