//
// Created by nereus on 30.12.2020.
//
#include "RigidBody.h"
#include "../ContextDynamic.h"
#include <iostream>

DynamicSystem* RigidBody::f() {
    DynamicSystem* result = new RigidBody(this->height,this->length,this->mass);

    result->r = l * mass;
    result->R = q.toMatrix();
    Vector omega = ((R * INERTIA_TENSOR) * R.transpose()) * L;
    result->q = Quaternion{0, omega.x, omega.y, omega.z} * q * 0.5;
    result->l = Vector{0, 0, 0};
    result->L = Vector{0, 0, 0};
    return result;
}

RigidBody RigidBody::operator+(RigidBody A){
    RigidBody result(this->height,this->length,this->mass);
    result.r = r + A.r;
    result.q = q + A.q;
    result.l = l + A.l;
    result.L = L + A.L;
    return result;
}
RigidBody RigidBody::operator*(double h){
    RigidBody result(this->height,this->length,this->mass);
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


RigidBody::RigidBody(double height,double length,double mass){
    this->height = height;
    this->length = length;
    this->mass = mass;
    INERTIA_TENSOR = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    INERTIA_TENSOR.values[0][0] = 1/((mass*length*length)/40+(3*mass*height*height)/80);
    INERTIA_TENSOR.values[1][1] = 1/((mass*length*length)/40+(3*mass*height*height)/80);
    INERTIA_TENSOR.values[2][2] = 1/((mass*length*length)/20);
    q = {0.5,0.5,0.5,0.5};
    R = q.toMatrix();
    L = Vector{6, 6, 6};
}

