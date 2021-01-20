//
// Created by nereus on 30.12.2020.
//
#include "RigidBody.h"
#include "../ContextDynamic.h"
#include <iostream>

DynamicSystem* RigidBody::f() {
    DynamicSystem* result = new RigidBody();

    result->r = l * mass;
    result->R = q.toMatrix();
    Vector omega = ((R * INERTIA_TENSOR) * R.transpose()) * L;
    result->q = Quaternion{0, omega.x, omega.y, omega.z} * q * 0.5;
    result->l = Vector{0, 0, 0};
    result->L = Vector{0, 0, 0};
    return result;
}

RigidBody RigidBody::operator+(RigidBody A){
    RigidBody result;
    result.r = r + A.r;
    result.q = q + A.q;
    result.l = l + A.l;
    result.L = L + A.L;
    return result;
}
RigidBody RigidBody::operator*(double h){
    RigidBody result;
    result.r = r * h;
    result.q = q * h;
    result.l = l * h;
    result.L = L * h;
    return result;
}
RigidBody RigidBody::operator=(DynamicSystem* A){
   // RigidBody result;
   INERTIA_TENSOR = A->INERTIA_TENSOR;
    l = A->l;
    r = A->r;
    L = A->L;
    q = A->q;
    R = A->R;
    return *this;
}

RigidBody::RigidBody() {
    INERTIA_TENSOR = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    INERTIA_TENSOR.values[0][0] = ((mass*length*length)/40+(3*mass*height*height)/80);
    INERTIA_TENSOR.values[1][1] = ((mass*length*length)/20);
    INERTIA_TENSOR.values[2][2] = ((mass*length*length)/40+(3*mass*height*height)/80);
    double tr,s;
    tr =  INERTIA_TENSOR.values[0][0] +  INERTIA_TENSOR.values[1][1] + INERTIA_TENSOR.values[2][2];

    q = {cos(30),1,0,0};
    R = q.toMatrix();
    L = Vector{4000, -2000, 2000};
}