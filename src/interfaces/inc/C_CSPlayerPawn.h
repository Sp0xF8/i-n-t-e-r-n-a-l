#pragma once

#include <Pointer.h>
#include <C_BaseEntity.h>

class C_CSPlayerPawn : public C_BaseEntity 
{

    uintptr_t skeleton;
public:

    C_CSPlayerPawn(uintptr_t addr) : C_BaseEntity(addr) {}
    C_CSPlayerPawn() : C_BaseEntity() {}


    void setSkeleton();
    Vector3 jointPos(int);

    bool bSpotted();

};