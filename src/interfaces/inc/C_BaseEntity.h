#pragma once

#include <ClassBase.h>
// #include <Pointer.h>
#include <vectors.h>


class C_BaseEntity: public ClassBase
{

public:

    C_BaseEntity(uintptr_t address) : ClassBase(address) {}
    //direct pointer constructro
    C_BaseEntity() {}


    int getHealth();
    Vector3 getPosition();
    int getTeam();






};

