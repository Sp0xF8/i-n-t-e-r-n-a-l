#include <GPointers.h>

#include <offsets.h>
#include <Windows.h>


// 

void GPointers::init(){
    Client_dll = Pointer((uintptr_t)GetModuleHandleA("client.dll"), "Client.dll");
    Engine_dll = Pointer((uintptr_t)GetModuleHandleA("engine2.dll"), "Engine.dll");

    
    EntityList = Pointer<uintptr_t>(this->Client_dll.GetAddress() + offsets::client_dll::dwEntityList, "Entity List");
    LocalPlayerController = Pointer<uintptr_t>(this->Client_dll.GetAddress() + offsets::client_dll::dwLocalPlayerController, "Local Controller");
    LocalPlayerPawn = Pointer<uintptr_t>(this->Client_dll.GetAddress() + offsets::client_dll::dwLocalPlayerPawn, "Local Pawn");
    ViewMatrix = Pointer<uintptr_t>(this->Client_dll.GetAddress() + offsets::client_dll::dwViewMatrix, "View Matrix");
};

GPointers::~GPointers(){
    delete EntityList;
    delete LocalPlayerController;
    delete LocalPlayerPawn;
    delete ViewMatrix;
};