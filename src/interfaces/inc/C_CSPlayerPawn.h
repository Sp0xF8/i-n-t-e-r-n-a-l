#pragma once

#include <Pointer.h>
#include <C_BaseEntity.h>

class C_CSPlayerPawn : public C_BaseEntity 
{
public:

    C_CSPlayerPawn(uintptr_t addr) : C_BaseEntity(addr) {}
    C_CSPlayerPawn() : C_BaseEntity() {}


};