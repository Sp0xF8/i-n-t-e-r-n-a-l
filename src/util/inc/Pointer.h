#pragma once

//no default constructor exists for class "Pointer<uintptr_t>" (aka "Pointer<unsigned long long>")C/C++(291)

#include <defines.h>

#define BROKEN_REFERENCE = 0xffffffff
//T based pointer class

class Pointer
{
public:
    
    Pointer(uintptr_t address, const char* name) {
        m_address = address;
        m_dereferenced = *(uintptr_t*)address;
        DLOG("%s Created @ %p\n",name, m_address);
        DLOG("%s Value @ %p\n", name, m_dereferenced);
    }

    Pointer() {}
    
    
    uintptr_t GetAddress() {
        return m_address;
    }

    template <typename T>
    T GetAddress() {
        return *(T*)m_address;
    }

    uintptr_t getDereference() {
        return m_dereferenced;
    }

    template <typename T>
    T getDereference() {
        return (T)m_dereferenced;
    }

    //offset
    uintptr_t operator+(uintptr_t offset) {
        return m_address + offset;
    }

    //assignment 
    void operator=(uintptr_t address) {
        m_address = address;
        m_dereferenced = *(uintptr_t*)address;
        DLOG("Pointer found @ %p \n", m_address);
        DLOG("Dereferenced Value @ %p\n", m_dereferenced);
    }

    // assignment via pointer
    void operator=(Pointer* pointer) {
        m_address = pointer->GetAddress();
        m_dereferenced = pointer->getDereference();
        DLOG("Pointer found @ %p \n", m_address);
        DLOG("Dereferenced Value @ %p\n", m_dereferenced);
    }

    // assignment via pointer
    void operator=(Pointer pointer) {
        m_address = pointer.GetAddress();
        m_dereferenced = pointer.getDereference();
        DLOG("Pointer found @ %p \n", m_address);
        DLOG("Dereferenced Value @ %p\n", m_dereferenced);
    }


private:
    uintptr_t m_address;
    uintptr_t m_dereferenced;
};

