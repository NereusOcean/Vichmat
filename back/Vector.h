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

    Vector operator*(double h) const;
    Vector operator+(Vector other) const;
};

#endif //VMTRIANGLE_VECTOR_H
