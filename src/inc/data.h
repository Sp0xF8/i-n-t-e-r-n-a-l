#pragma once

#include <cstddef>
#include <cstdint> // Include the necessary header file

#include <structs.h>

namespace data {

	extern int latestBuildNumber;

	extern uintptr_t client_dll;
	extern uintptr_t engine2_dll;
	extern uintptr_t matchmaking_dll;


	extern dwGameTypes* gameType;

	extern int* dwForceAttack;

	


	void setup();
}