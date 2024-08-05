#pragma once

#include <cstdint>

#include <Pointer.h>

#include <C_BaseEntity.h>


class CCSPlayerController: public C_BaseEntity
{
public:

    CCSPlayerController(uintptr_t addr) : C_BaseEntity(addr) {}
    CCSPlayerController() : C_BaseEntity() {}

    int m_hPlayerPawn();
};


