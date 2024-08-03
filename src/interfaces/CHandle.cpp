#include <CHandle.h>
#include <offsets.h>
#include <GPointers.h>
#include <C_BaseEntity.h>


#include <CCSPlayerController.h>
#include <C_CSPlayerPawn.h>

namespace CHandler {
    uintptr_t listEntry = NULL;
}

void CHandler::setList(){
    listEntry = *(uintptr_t*)(gPointers.EntityList.GetAddress() + ((8 * (42 & 0x7FFF) >> 9) + 16));
}


template <typename T>
T CHandler::GetEntityFromHandle(int handle) {

    if(!listEntry){
		return 0;
	}
    
    uintptr_t entity = *(uintptr_t*)(listEntry + (120) * (handle & 0x1FF));
    if(!entity){
        return 0;
    }

    return reinterpret_cast<T>(entity);
}


// templates
template CCSPlayerController* CHandler::GetEntityFromHandle<CCSPlayerController*>(int handle);
template C_CSPlayerPawn* CHandler::GetEntityFromHandle<C_CSPlayerPawn*>(int handle);