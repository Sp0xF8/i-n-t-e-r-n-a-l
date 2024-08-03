#pragma once

//no default constructor exists for class "Pointer<uintptr_t>" (aka "Pointer<unsigned long long>")C/C++(291)

#include <defines.h>

#define BROKEN_REFERENCE = 0xffffffff
//T based pointer class
template <typename T>
class Pointer
{
public:
    //constructor
    Pointer(T address, const char* ptrName = "Pointer") : m_address(address) {DLOG("%s Created @   0x%p \n", ptrName, address);}
    //no default constructor exists for class "Pointer<uintptr_t>" (aka "Pointer<unsigned long long>")C/C++(291)
    Pointer() : m_address(0) {}

    //destructor
    ~Pointer() {}

    //dereference operator
    T& operator*() { return *reinterpret_cast<T*>(m_address); }

    //member access operator
    T* operator->() { return reinterpret_cast<T*>(m_address); }

    //cast operator
    operator T*() { return reinterpret_cast<T*>(m_address); }

    //no operator "=" matches these operandsC/C++(349)
    //assignment operator
    Pointer& operator=(T address) { m_address = address; return *this; }

    //get address
    T GetAddress() { return m_address; }


    //addition operator
    Pointer offset(int offset) { return Pointer(m_address + offset); }

private:
    T m_address;
};