#pragma once

#include <cstdint>



namespace CHandler
{
    extern uintptr_t listEntry;
	
    void setList();

    // get base entity from entity handle
    template <typename T>
    T GetEntityFromHandle(int handle);


    // auto Get(int iHandle) const { return reinterpret_cast<T *>(this.GetEntityFromHandle(iHandle)); }
};


