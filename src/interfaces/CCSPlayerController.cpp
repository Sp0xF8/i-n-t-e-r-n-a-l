#include <CCSPlayerController.h>

#include <client_dll.hpp>
#include <GPointers.h>


int CCSPlayerController::m_hPlayerPawn (){
    return *(uintptr_t*)((uintptr_t)getAddress() + client_dll::CCSPlayerController::m_hPlayerPawn);
}