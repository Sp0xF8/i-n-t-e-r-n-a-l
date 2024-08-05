#pragma once

//no default constructor exists for class "Pointer<uintptr_t>" (aka "Pointer<unsigned long long>")C/C++(291)

#include <defines.h>

#define BROKEN_REFERENCE = 0xffffffff
//T based pointer class

class Pointer
{

public:
    Pointer(uintptr_t ptr, const char* name) : ptr(ptr) {
        DLOG("%s found @ %p \n", name, ptr);
    }
    
    Pointer(uintptr_t ptr) : ptr(ptr) {
        DLOG("Pointer found @ %p \n", ptr);
    }

  

    Pointer() : ptr(0) {}

    uintptr_t deref() {
        return *(uintptr_t*)ptr;
    }

    template <typename T>
    T deref(){
        return *(T*)ptr;
    }

    template <typename T = uintptr_t>
    T offset(uintptr_t off) {
        return *(T*)(deref() + off);
    }



    uintptr_t ptr;

};

