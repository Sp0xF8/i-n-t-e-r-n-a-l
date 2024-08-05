#pragma once

// #include <ClassBase.h>
#include <Pointer.h>
#include <vectors.h>


class C_BaseEntity: public Pointer
{

public:

    C_BaseEntity(uintptr_t address, const char* name) : Pointer(address, name) {}
    //direct pointer constructro
    C_BaseEntity() {}


    int getHealth();
    // Vector3 getPosition();
    int getTeam();






};

