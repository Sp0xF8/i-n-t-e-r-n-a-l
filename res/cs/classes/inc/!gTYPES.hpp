#pragma once

#include <handle.hpp>
#include <defines.h>
#include <utlvector.hpp>
#include <cstdint> // Add this line to include the header file that defines int32_t
#include <!OVERRIDES.hpp>


struct GameTick_t
{
public:
	int32_t m_Value; // 0x0	
};

struct GameTime_t
{
public:
	float m_Value; // 0x0	
};


struct thinkfunc_t
{
private:
	[[maybe_unused]] uint8_t __pad0000[0x8]; // 0x0
public:
	HSCRIPT m_hFn; // 0x8	
	CUtlStringToken m_nContext; // 0x10	
	GameTick_t m_nNextThinkTick; // 0x14	
	GameTick_t m_nLastThinkTick; // 0x18	
	
	// Datamap fields:
	// void m_think; // 0x0
};
