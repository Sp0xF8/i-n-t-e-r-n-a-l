#include <CHandle.h>
#include <offsets.h>
#include <GPointers.h>
#include <C_BaseEntity.h>



uintptr_t CHandler::GetEntityFromHandle(int handle) {
    uintptr_t listEntry = *(uintptr_t*)(gPointers.EntityList.GetAddress() + ((8 * (42 & 0x7FFF) >> 9) + 16));
    
    uintptr_t entity = *(uintptr_t*)(listEntry + (120) * (handle & 0x1FF));
    if(!entity){
        return 0;
    }

    return entity;
}