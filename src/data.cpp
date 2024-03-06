
#include <data.h>

#include <Windows.h>

#include <defines.h>
#include <offsets.h>



namespace data {

	int latestBuildNumber = 0x36AB;

	uintptr_t client_dll = 0;
	uintptr_t engine2_dll = 0;
	uintptr_t matchmaking_dll = 0;

	dwGameTypes* gameType;

	int* dwForceAttack = 0;

	int* dwForceJump = 0;


	

	
}


void data::setup() {
	client_dll = (uintptr_t)GetModuleHandleA("client.dll");
	engine2_dll = (uintptr_t)GetModuleHandleA("engine2.dll");
	matchmaking_dll = (uintptr_t)GetModuleHandleA("matchmaking.dll");

	gameType = ez_cast(dwGameTypes, matchmaking_dll + offsets::matchmaking_dll::dwGameTypes_mapName);

	dwForceAttack = reinterpret_cast<int*>(client_dll + offsets::client_dll::dwForceAttack);

	dwForceJump = reinterpret_cast<int*>(client_dll + offsets::client_dll::dwForceJump);

}