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

#include <structs.h>


Vector3 WorldToScreen(const Vector3 vecOrigin, view_matrix_t matrix)
{
    
    float _w = matrix.matrix[3][0] * vecOrigin.x + matrix.matrix[3][1] * vecOrigin.y + matrix.matrix[3][2] * vecOrigin.z + matrix.matrix[3][3];

	if (_w < 0.01f)
		return { -1, -1, 0 };

	float _x = matrix.matrix[0][0] * vecOrigin.x + matrix.matrix[0][1] * vecOrigin.y + matrix.matrix[0][2] * vecOrigin.z + matrix.matrix[0][3];
	float _y = matrix.matrix[1][0] * vecOrigin.x + matrix.matrix[1][1] * vecOrigin.y + matrix.matrix[1][2] * vecOrigin.z + matrix.matrix[1][3];


	_x = (gui::windowWidth / 2) * (1 + _x / _w);
	_y = (gui::windowHeight / 2) * (1 - _y / _w);

		

    return Vector3(_x, _y, _w);
}


void visuals::run(){
	if(!config::visuals::enabled){
		return;
	}

	DLOG("--------------VISUALS--------------\n");

	C_CSPlayerPawn localPawn = gPointers.LocalPlayerPawn->deref();

	int health = localPawn.getHealth();
	int team = localPawn.getTeam();

	DLOG("Health: %d\n", health);
	DLOG("Team: %d\n", team);

	Vector3 position = localPawn.getPosition();

	DLOG("Position: %f %f %f\n", position.x, position.y, position.z);

	CHandler::setList();

	view_matrix_t viewMatrix = gPointers.ViewMatrix->deref<view_matrix_t>();

	// // print viewmatrix
	// for (int i = 0; i < 4; i++){
	// 	for (int j = 0; j < 4; j++){
	// 		DLOG("%f ", viewMatrix[i][j]);
	// 	}
	// 	DLOG("\n");
	// }


	for (int i = 0; i < 64; i++){

		CCSPlayerController entity = CHandler::GetEntityFromHandle(i);
		if(!entity.isValid()){
			continue;
		}

		uintptr_t pawn = entity.m_hPlayerPawn();
		if(!pawn){
			continue;
		}

		C_CSPlayerPawn playerPawn = CHandler::GetEntityFromHandle(pawn);

		if(!playerPawn.isValid()){
			continue;
		}


		int playerHealth = playerPawn.getHealth();
		if (playerHealth > 100 || playerHealth < 1){
			continue;
		}

		int playerTeam = playerPawn.getTeam();

		if (!config::visuals::drawTeam && playerTeam == team){
			DLOG("%d : %d\n", i, playerTeam);
			continue;
		}
		Vector3 playerPos = playerPawn.getPosition();

		// DLOG("Player Controller %d @ %p \n",i, entity.getAddress());
		// DLOG("EntityHandle: %d\n", pawn);
		// DLOG("Player Pawn %d @ %p\n",i, playerPawn.getAddress());


		//add dot to draw list
		Vector3 screenPos = WorldToScreen(playerPos, viewMatrix);

		if (config::visuals::esp::dot) {
			DLOG("%d : %f %f %f\n", i, playerPos.x, playerPos.y, playerPos.z);

			if(screenPos.x != -1 && screenPos.y != -1){
				//void ImDrawList::AddCircle(const ImVec2& center, float radius, ImU32 col, int num_segments, float thickness)
				// ImGui::GetBackgroundDrawList()->AddCircle(ImVec2(screenPos.x, screenPos.y), 5, ImColor(255, 255, 255, 255), 4, 3);
				Draw::Circle(Vector2(screenPos.x,screenPos.y), 5, FromFloatToColour(config::visuals::esp::dotColour), 3, 4 );
				
			}
		}


		if (config::visuals::esp::health) {
			DLOG("%d : %d\n", i, playerHealth);
			
			float health_perc = playerHealth/100;
			Colour healthColour;
			if(health_perc > 0.75) {
				healthColour = {0.0700, 1.00, 0.256, 1.0};
			} else if (health_perc > 0.25) {
				healthColour = {0.920, 0.665, 0.156, 1.0 };
			} else {
				healthColour = {0.820, 0.303, 0.321, 1.0};
			}

			int barSize = playerHealth;

			Draw::RectFilled(Vector2(screenPos.x - barSize/2 +2, screenPos.y + 8), Vector2(screenPos.x + barSize/2 +2, screenPos.y + 17), {0.0f, 0.0f, 0.0f, 1.0f});
			Draw::RectFilled(Vector2(screenPos.x - barSize/2, screenPos.y + 10), Vector2(screenPos.x + barSize/2, screenPos.y + 15), healthColour);
		}

		if (config::visuals::esp::distance){

			Vector3 Distance = position - playerPos;

			float distance = sqrt(Distance.x * Distance.x + Distance.y * Distance.y + Distance.z * Distance.z);
			if(distance < config::visuals::esp::distanceLimit){
				char buffer[256];
				sprintf(buffer, "Distance: %f", distance);
				Draw::Text(Vector2(screenPos.x, screenPos.y + 30), buffer, FromFloatToColour(config::visuals::esp::distanceColour), true);
			}
		}

		if (config::visuals::esp::name) {

			uintptr_t player_name = entity.m_sSanitizedPlayerName();
			if(player_name){
				char buffer[256];
				sprintf(buffer, "Name: %s", (char*)player_name);
				Draw::Text(Vector2(screenPos.x, screenPos.y - 40), buffer, FromFloatToColour(config::visuals::esp::nameColour), true);
			}
		}

	}

}
