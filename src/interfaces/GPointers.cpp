#include <GPointers.h>

#include <offsets.h>
#include <Windows.h>


// 

void GPointers::init(){
    Client_dll = new Pointer((uintptr_t)GetModuleHandleA("client.dll"), "Client.dll");
    Engine_dll = new Pointer((uintptr_t)GetModuleHandleA("engine2.dll"), "Engine.dll");

    DLOG("Client_dll->ptr : %p\n", Client_dll->ptr);
    DLOG("Dereferenced pClient.dll : %p\n", Client_dll->deref());
    DLOG("Engine.dll : %p\n", Engine_dll);
    DLOG("pEngine.dll : %p\n", Engine_dll->ptr);

    // EntityList = Client_dll + offsets::client_dll::dwEntityList;

    LocalPlayerController =  new Pointer(Client_dll->ptr + offsets::client_dll::dwLocalPlayerController, "LocalController");

    DLOG("LocalPlayerController->ptr : %p\n", LocalPlayerController->ptr);
    DLOG("LocalPlayerController->deref() : %p\n", LocalPlayerController->deref());
    
    LocalPlayerPawn = new Pointer(Client_dll->ptr + offsets::client_dll::dwLocalPlayerPawn, "LocalPawn");

    DLOG("LocalPlayerPawn->ptr : %p\n", LocalPlayerPawn->ptr);
    DLOG("LocalPlayerPawn->deref() : %p\n", LocalPlayerPawn->deref());

    ViewMatrix = new Pointer(Client_dll->ptr + offsets::client_dll::dwViewMatrix, "ViewMatrix");
    DLOG("ViewMatrix->ptr : %p\n", ViewMatrix->ptr);
    DLOG("ViewMatrix->deref() : %p\n", ViewMatrix->deref());

    EntityList = new Pointer(Client_dll->ptr + offsets::client_dll::dwEntityList, "EntityList");
    DLOG("EntityList->ptr : %p\n", EntityList->ptr);
    DLOG("EntityList->deref() : %p\n", EntityList->deref());



};


