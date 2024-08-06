#include <CHandle.h>
#include <offsets.h>
#include <GPointers.h>
#include <C_BaseEntity.h>


#include <CCSPlayerController.h>
#include <C_CSPlayerPawn.h>

namespace CHandler {
    Pointer* listEntry;
}

void CHandler::setList(){
    CHandler::listEntry = new Pointer(gPointers.EntityList->deref() + ((8 * (42 & 0x7FFF) >> 9) + 16));
    DLOG("ListEntry: %p\n", listEntry->ptr);
    DLOG("ListEntryDeref: %p\n", listEntry->deref());
    // DLOG("EntityList2: %p", *(uintptr_t*)(gPointers.EntityList.GetAddress() + ((8 * (42 & 0x7FFF) >> 9) + 16)));
}


// template <typename T>
uintptr_t CHandler::GetEntityFromHandle(int handle) {

    // DLOG("List Entry: %p \n", listEntry);

    if(!listEntry->deref()){
		return 0;
	}
    
    uintptr_t entity = listEntry->dOffset((120) * (handle & 0x1FF));
    if(!entity){
        return 0;
    }
    // DLOG("EntityInClass: %p\n", entity);

    return entity;
}


// templates
// template CCSPlayerController* CHandler::GetEntityFromHandle<CCSPlayerController*>(int handle);
// template C_CSPlayerPawn* CHandler::GetEntityFromHandle<C_CSPlayerPawn*>(int handle);