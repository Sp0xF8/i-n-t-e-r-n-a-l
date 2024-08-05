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

	C_CSPlayerPawn localPawn = gPointers.LocalPlayerPawn;
	Pointer localController = gPointers.LocalPlayerController;

	// int health = localPawn.getHealth();
	// int team = localPawn.getTeam();

	// DLOG("Health: %d", health);
	// DLOG("Team: %d", team);

	int health = localPawn.getDereference() + client_dll::C_BaseEntity::m_iHealth;
	int health2 = *(int*)(localPawn.getDereference() + client_dll::C_BaseEntity::m_iHealth);
	int health3 = localPawn.getHealth();

	DLOG("Health1: %d\n", health);
	DLOG("Health2: %d\n", health2);
	DLOG("Health3: %d\n", health3);

}
