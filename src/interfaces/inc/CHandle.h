#pragma once

#include <cstdint>
#include <Pointer.h>
#include <C_BaseEntity.h>



namespace CHandler
{


    // get base entity from entity handle
    
    extern uintptr_t GetEntityFromHandle(int handle);

    // auto Get(int iHandle) const { return reinterpret_cast<T *>(this.GetEntityFromHandle(iHandle)); }
};


