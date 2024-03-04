#pragma once

#include <structs.h>
#include <offsets.h>
#include <vector>


struct player_t {
	C_CSPlayerPawn* pawn;
	CCSPlayerController* controller;
	bool filled = false;

	


	bool Active();
};

namespace playerlist{

	extern player_t localPlayer;

	extern view_matrix_t viewMatrix;

	extern uintptr_t entitylist;

	extern player_t players[32];

	extern bool setupcomplete;

	bool setup();

	void updatePlayers();

	void scrapPlayers();

}