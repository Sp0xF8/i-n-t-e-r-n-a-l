#pragma once


#include <cstdint>
#include <Pointer.h>


class GPointers {
public:
    Pointer<uintptr_t> Client_dll;
    Pointer<uintptr_t> Engine_dll;

    Pointer<uintptr_t*> EntityList;
    Pointer<uintptr_t*> LocalPlayerController;
    Pointer<uintptr_t*> LocalPlayerPawn;
    Pointer<uintptr_t*> ViewMatrix;



    // GPointers();
    ~GPointers();


    void init();
};

//inline definition to access globally
inline GPointers gPointers;