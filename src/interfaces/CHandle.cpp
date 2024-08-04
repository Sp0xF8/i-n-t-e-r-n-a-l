#include <CHandle.h>
#include <offsets.h>
#include <GPointers.h>
#include <C_BaseEntity.h>


#include <CCSPlayerController.h>
#include <C_CSPlayerPawn.h>

namespace CHandler {
    uintptr_t listEntry;
}

void CHandler::setList(){
    CHandler::listEntry = *(uintptr_t*)(gPointers.EntityList.GetAddress() + ((8 * (42 & 0x7FFF) >> 9) + 16));
    DLOG("Entity List: %p\n", listEntry);
    // DLOG("EntityList2: %p", *(uintptr_t*)(gPointers.EntityList.GetAddress() + ((8 * (42 & 0x7FFF) >> 9) + 16)));
}


// template <typename T>
uintptr_t CHandler::GetEntityFromHandle(int handle) {

    DLOG("List Entry: %p \n", listEntry);

    if(!listEntry){
		return 0;
	}
    
    uintptr_t entity = *(uintptr_t*)(listEntry + (120) * (handle & 0x1FF));
    if(!entity){
        return 0;
    }
    DLOG("EntityInClass: %p\n", entity);

    return entity;
}


// templates
// template CCSPlayerController* CHandler::GetEntityFromHandle<CCSPlayerController*>(int handle);
// template C_CSPlayerPawn* CHandler::GetEntityFromHandle<C_CSPlayerPawn*>(int handle);