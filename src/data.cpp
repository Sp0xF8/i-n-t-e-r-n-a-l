
#include <data.h>

#include <Windows.h>

#include <defines.h>
#include <offsets.h>



namespace data {
	uintptr_t client_dll = 0;
	uintptr_t engine2_dll = 0;
	uintptr_t matchmaking_dll = 0;
}


void data::setup() {
	client_dll = (uintptr_t)GetModuleHandleA("client.dll");
	engine2_dll = (uintptr_t)GetModuleHandleA("engine2.dll");
	matchmaking_dll = (uintptr_t)GetModuleHandleA("matchmaking.dll");


}