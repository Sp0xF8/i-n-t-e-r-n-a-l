#pragma once

#include <cstddef>
#include <cstdint> // Include the necessary header file

#include <structs.h>

namespace data {

	extern uintptr_t client_dll;
	extern uintptr_t engine2_dll;
	extern uintptr_t matchmaking_dll;

	void setup();
}