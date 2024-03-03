#include <playerlist.h>
#include <data.h>
#include <defines.h>
#include <visuals.h>



bool player_t::Active() {


	if (pawn == nullptr || controller == nullptr) {
		return false;
	}

	if(pawn->m_pClassType != playerlist::localPlayer.pawn->m_pClassType){
		return false;
	}

	if(controller->m_pClassType != playerlist::localPlayer.controller->m_pClassType){
		return false;
	}
	

	if (pawn->m_iHealth <= 0) {
		return false;
	}

	return true;
	
}

namespace playerlist {

	player_t localPlayer = { 0 };

	uintptr_t entitylist = NULL;

	player_t players[32] = { 0 };

	bool setupcomplete = false;
}


bool playerlist::setup() {
	if (!data::client_dll || !data::matchmaking_dll) {
		return false;
	}

	//check that the first character is not "<"(empty>) to avoid reading when not in a map.
	if (data::gameType->m_sMapName[0] == '<') {
		DLOG("Not in a map\n");
		return false;
	}

	localPlayer.pawn = ez_cast(C_CSPlayerPawn, data::client_dll + offsets::client_dll::dwLocalPlayerPawn);
	localPlayer.controller = ez_cast(CCSPlayerController, data::client_dll + offsets::client_dll::dwLocalPlayerController);

	if(localPlayer.pawn == nullptr || localPlayer.controller == nullptr){
		return false;
	}

	entitylist = *reinterpret_cast<uintptr_t*>(data::client_dll + offsets::client_dll::dwEntityList);

	visuals::viewMatrix = (view_matrix_t*)(data::client_dll + offsets::client_dll::dwViewMatrix);

	setupcomplete = true;

	return true;
}



void playerlist::updatePlayers() {

	if (!setupcomplete) {
		setup();
		return;
	}

	for (uint64_t entities = 0; entities < 32; entities++) {

		uintptr_t Entity = *reinterpret_cast<uintptr_t*>(data::client_dll + offsets::client_dll::dwEntityList);

		uintptr_t listEntity = *reinterpret_cast<uintptr_t*>(Entity + ((8 * (entities & 0x7FFF) >> 9) + 16));
		if (listEntity == 0){

			players[entities].controller = nullptr;
			players[entities].pawn = nullptr;
			continue;
		}

		uintptr_t entityController = *reinterpret_cast<uintptr_t*>(listEntity + (120) * (entities & 0x1FF));
		if (entityController == 0){

			players[entities].controller = nullptr;
			players[entities].pawn = nullptr;
			continue;
		}

		uintptr_t entityControllerPawn = *reinterpret_cast<uintptr_t*>(entityController + 0x7E4); // +hPawn
		if (entityControllerPawn == 0){

			players[entities].controller = nullptr;
			players[entities].pawn = nullptr;
			continue;
		}

		listEntity = *reinterpret_cast<uintptr_t*>(Entity + (0x8 * ((entityControllerPawn & 0x7FFF) >> 9) + 16));
		if (listEntity == 0){

			players[entities].controller = nullptr;
			players[entities].pawn = nullptr;
			continue;
		}

		uintptr_t entityPawn = *reinterpret_cast<uintptr_t*>(listEntity + (120) * (entityControllerPawn & 0x1FF));
		if (entityPawn == 0){

			players[entities].controller = nullptr;
			players[entities].pawn = nullptr;
			continue;
		}


		players[entities].controller = (CCSPlayerController*)entityController;
		players[entities].pawn = (C_CSPlayerPawn*)entityPawn;

		DLOG("PlayerPawn: %p\n", entityPawn);
		DLOG("PlayerController: %p\n", entityController);


	}
}


void playerlist::scrapPlayers() {

	localPlayer.controller = nullptr;
	localPlayer.pawn = nullptr;


	for (int i = 0; i < 32; i++) {
		players[i].controller = nullptr;
		players[i].pawn = nullptr;
	}

	setupcomplete = false;
}