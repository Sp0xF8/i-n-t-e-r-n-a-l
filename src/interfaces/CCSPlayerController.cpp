#include <CCSPlayerController.h>

#include <client_dll.hpp>
#include <GPointers.h>


int CCSPlayerController::m_hPlayerPawn (){
    return offset<uintptr_t>(client_dll::CCSPlayerController::m_hPlayerPawn);
}