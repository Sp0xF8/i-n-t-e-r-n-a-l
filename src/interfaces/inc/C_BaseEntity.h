#pragma once

#include <ClassBase.h>

#include <CBodyComponent.h>


class C_BaseEntity: public ClassBase
{

public:


    int getPlayerHealth();
    CBodyComponent getBodyComponent();


    uintptr_t* getPointer() { return address; }

    void setAddress(uintptr_t addr) { *address = addr; }




};

