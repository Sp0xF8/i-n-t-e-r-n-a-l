#include <GPointers.h>

#include <offsets.h>
#include <Windows.h>


// 

void GPointers::init(){
    Client_dll = Pointer((uintptr_t)GetModuleHandleA("client.dll"), "Client.dll");
    Engine_dll = Pointer((uintptr_t)GetModuleHandleA("engine2.dll"), "Engine.dll");

    EntityList = Client_dll + offsets::client_dll::dwEntityList;

    LocalPlayerController = Client_dll + offsets::client_dll::dwLocalPlayerController;
    LocalPlayerPawn = Client_dll + offsets::client_dll::dwLocalPlayerPawn;

    ViewMatrix = Client_dll + offsets::client_dll::dwViewMatrix;


};


