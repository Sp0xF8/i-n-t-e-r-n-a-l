#pragma once

#include <cstdint>

class ClassBase {
protected:
    uintptr_t address;
    public:
    ClassBase(uintptr_t addr) : address(addr) {}
    ClassBase() {}

    bool isValid(){
        return address != 0;
    }

    //offset function
    template <typename T>
    T offset(ptrdiff_t off) {
        return *(T*)(address + off);
    }

    uintptr_t getAddress() {
        return address;
    }


};