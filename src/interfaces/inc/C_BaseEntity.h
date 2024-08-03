#pragma once

#include <ClassBase.h>
#include <vectors.h>


class C_BaseEntity: public ClassBase
{

public:


    int getPlayerHealth();
    Vector3 getPosition();
    int getTeam();


    uintptr_t* getPointer() { return address; }

    void setAddress(uintptr_t addr) { *address = addr; }




};

