#include <visuals.h>
#include <config.h>
#include <draw.h>
#include <gui.h>
// #include <data.h>
#include <offsets.h>
#include <client_dll.hpp>
#include <imgui.h>


#include <CHandle.h>

#include <GPointers.h>
// #include <C_BaseEntity.h>
#include <C_CSPlayerPawn.h>
#include <CCSPlayerController.h>

// Vector3 WorldToScreen(const Vector3 vecOrigin, view_matrix_t matrix)
// {
    
//     float _w = matrix.matrix[3][0] * vecOrigin.x + matrix.matrix[3][1] * vecOrigin.y + matrix.matrix[3][2] * vecOrigin.z + matrix.matrix[3][3];

// 	if (_w < 0.01f)
// 		return { -1, -1, 0 };

// 	float _x = matrix.matrix[0][0] * vecOrigin.x + matrix.matrix[0][1] * vecOrigin.y + matrix.matrix[0][2] * vecOrigin.z + matrix.matrix[0][3];
// 	float _y = matrix.matrix[1][0] * vecOrigin.x + matrix.matrix[1][1] * vecOrigin.y + matrix.matrix[1][2] * vecOrigin.z + matrix.matrix[1][3];


// 	_x = (gui::windowWidth / 2) * (1 + _x / _w);
// 	_y = (gui::windowHeight / 2) * (1 - _y / _w);

		

//     return Vector3(_x, _y, _w);
// }


void visuals::run(){
	if(!config::visuals::enabled){
		return;
	}

	C_CSPlayerPawn localPawn = gPointers.LocalPlayerPawn->deref();

	int health = localPawn.getHealth();
	int team = localPawn.getTeam();

	DLOG("Health: %d\n", health);
	DLOG("Team: %d\n", team);

	Vector3 position = localPawn.getPosition();

	DLOG("Position: %f %f %f\n", position.x, position.y, position.z);

	CHandler::setList();


	for (int i = 0; i < 64; i++){

		CCSPlayerController entity = CHandler::GetEntityFromHandle(i);
		if(!entity.isValid()){
			continue;
		}
		DLOG("Player Controller %d @ %p \n",i, entity.getAddress());

		uintptr_t pawn = entity.m_hPlayerPawn();
		if(!pawn){
			continue;
		}
		DLOG("EntityHandle: %d\n", pawn);

		C_CSPlayerPawn playerPawn = CHandler::GetEntityFromHandle(pawn);

		if(!playerPawn.isValid()){
			continue;
		}

		DLOG("Player Pawn %d @ %p\n",i, playerPawn.getAddress());


		int playerHealth = playerPawn.getHealth();
		int playerTeam = playerPawn.getTeam();
		Vector3 playerPos = playerPawn.getPosition();

		DLOG("%d : %d\n", i, playerHealth);
		DLOG("%d : %d\n", i, playerTeam);
		DLOG("%d : %f %f %f\n", i, playerPos.x, playerPos.y, playerPos.z);

	}

}
