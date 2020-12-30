//
// Created by nereus on 30.12.2020.
//

#ifndef VMTRIANGLE_CONTEXTDYNAMIC_H
#define VMTRIANGLE_CONTEXTDYNAMIC_H
#include "DynamicSystem.h"
class ContextDynamic{
public:
    DynamicSystem* setTypeOfBody(DynamicSystem* body){
         return body->f();
    }

};
#endif //VMTRIANGLE_CONTEXTDYNAMIC_H
