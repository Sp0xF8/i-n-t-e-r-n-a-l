#pragma once

#include <cstdint>

class ClassBase {
protected:
    uintptr_t* address;
    public:
    ClassBase(uintptr_t* addr) : address(addr) {}

    uintptr_t getAddress() { return (uintptr_t)(address);}
};