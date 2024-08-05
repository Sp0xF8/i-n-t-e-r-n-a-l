#pragma once

#include <Pointer.h>
#include <C_BaseEntity.h>

class C_CSPlayerPawn : public C_BaseEntity 
{
public:
    C_CSPlayerPawn(uintptr_t address, const char* name) : C_BaseEntity(address, name) {}
    C_CSPlayerPawn() {}
    C_CSPlayerPawn(Pointer* pointer) : C_BaseEntity() {
        m_address = pointer->GetAddress();
        m_dereferenced = pointer->getDereference();
        DLOG("Pointer found @ %p \n", m_address);
        DLOG("Dereferenced Value @ %p\n", m_dereferenced);
    }
    C_CSPlayerPawn(Pointer pointer) : C_BaseEntity() {
        m_address = pointer.GetAddress();
        m_dereferenced = pointer.getDereference();
        DLOG("Pointer found @ %p \n", m_address);
        DLOG("Dereferenced Value @ %p\n", m_dereferenced);
    }

};