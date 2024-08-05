#pragma once


#include <cstdint>
#include <Pointer.h>


class GPointers {
public:
    Pointer* Client_dll;
    Pointer* Engine_dll;

    Pointer* EntityList;
    Pointer* LocalPlayerController;
    Pointer* LocalPlayerPawn;
    Pointer* ViewMatrix;



    // GPointers();
    // ~GPointers();


    void init();
};

//inline definition to access globally
inline GPointers gPointers;