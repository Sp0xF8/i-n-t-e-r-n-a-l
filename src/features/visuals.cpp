#include <visuals.h>
#include <config.h>
#include <draw.h>
#include <gui.h>
// #include <data.h>
#include <offsets.h>
#include <client_dll.hpp>
#include <imgui.h>

#include <GPointers.h>
// #include <C_BaseEntity.h>
#include <C_CSPlayerPawn.h>
#include <CCSPlayerController.h>

// Vector3 WorldToScreen(const Vector3 vecOrigin, view_matrix_t matrix)
// {
    
    
//     float _w = matrix[3][0] * vecOrigin.x + matrix[3][1] * vecOrigin.y + matrix[3][2] * vecOrigin.z + matrix[3][3];

// 	if (_w < 0.01f)
// 		return { -1, -1, 0 };

// 	float _x = matrix[0][0] * vecOrigin.x + matrix[0][1] * vecOrigin.y + matrix[0][2] * vecOrigin.z + matrix[0][3];
// 	float _y = matrix[1][0] * vecOrigin.x + matrix[1][1] * vecOrigin.y + matrix[1][2] * vecOrigin.z + matrix[1][3];


// 	_x = (gui::windowWidth / 2) * (1 + _x / _w);
// 	_y = (gui::windowHeight / 2) * (1 - _y / _w);

		

//     return Vector3(_x, _y, _w);
// }

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

	CCSPlayerController* localPlayer = reinterpret_cast<CCSPlayerController*>(gPointers.LocalPlayerController.GetAddress());
	printf("Entry found: %p \n", localPlayer);


	if(!localPlayer){
		return;
	}

	C_CSPlayerPawn*  localPlayerPawn = reinterpret_cast<C_CSPlayerPawn*>(gPointers.LocalPlayerPawn.GetAddress());
	printf("local Pawn: %p \n", localPlayerPawn);

	if(!localPlayerPawn){
		return;
	}

	int playerHealth = localPlayerPawn->getPlayerHealth();

	// //get local player pos for distance calc
	// uintptr_t gameNode = *(uintptr_t*)(localPlayerPawn + client_dll::C_BaseEntity::m_pGameSceneNode);
	// if(!gameNode){
	// 	return;
	// }
	// Vector3 localPos = *reinterpret_cast<Vector3*>(gameNode + client_dll::CGameSceneNode::m_vecOrigin);

	// Vector3 localPos = localPlayerPawn->getBodyComponent()->getGameSceneNode()->getVecOrigin();

	// int localTeam =  *reinterpret_cast<int*>(localPlayerPawn + client_dll::C_BaseEntity::m_iTeamNum);

	// //print local player pos
	// printf("Local Player Position: %f %f %f \n", localPos.x, localPos.y, localPos.z);

	

	// //print health
	printf("Health: %d \n", playerHealth);


	// uintptr_t EntityList = *(uintptr_t*)(data::client_dll + offsets::client_dll::dwEntityList);
	// printf("Entity List: %p \n", EntityList);

	// if(!EntityList){
	// 	return;
	// }

	// uintptr_t listEntry = *(uintptr_t*)(EntityList + ((8 * (42 & 0x7FFF) >> 9) + 16));
	// 	printf("Entity: %p \n", listEntry);

	// if(!listEntry){
	// 	return;
	// }

	// view_matrix_t viewMatrix = *(view_matrix_t*)(data::client_dll + offsets::client_dll::dwViewMatrix);

	// for (int i = 0; i < 64; i++){

	// 	uintptr_t entityController = *(uintptr_t*)(listEntry + (120) * (i & 0x1FF));
	// 	if(!entityController){
	// 		continue;
	// 	}

	// 	uintptr_t entityControllerPawn = *(uintptr_t*)(entityController + client_dll::CCSPlayerController::m_hPlayerPawn);
	// 	if(!entityControllerPawn){
	// 		continue;
	// 	}

	// 	uintptr_t entityPawn = *(uintptr_t*)(listEntry + (120) * (entityControllerPawn & 0x1FF));
	// 	if(!entityPawn){
	// 		continue;
	// 	}

	// 	int teamnum = *reinterpret_cast<int*>(entityPawn + client_dll::C_BaseEntity::m_iTeamNum);

	// 	if(!config::visuals::drawTeam && teamnum == localTeam){
	// 		continue;
	// 	}


	// 	int pHealth = *reinterpret_cast<int*>(entityPawn + client_dll::C_BaseEntity::m_iHealth);

	// 	if(pHealth < 1){
	// 		continue;
	// 	}

	// 	DLOG("========================================================\n");
	// 	DLOG("Entity Controller: %p \n", entityController);
	// 	DLOG("Entity Controller Pawn: %p \n", entityControllerPawn);
	// 	DLOG("Entity Pawn: %p \n", entityPawn);
	// 	DLOG("--------------------------------------------------------\n");
	// 	DLOG("Player %p Health : %d \n", entityPawn, pHealth);


	// 	uintptr_t gameNode = *(uintptr_t*)(entityPawn + client_dll::C_BaseEntity::m_pGameSceneNode);
	// 	if(!gameNode){
	// 		continue;
	// 	}

	// 	Vector3 pos = *reinterpret_cast<Vector3*>(gameNode + client_dll::CGameSceneNode::m_vecOrigin);
	// 	DLOG("Position: %f %f %f \n", pos.x, pos.y, pos.z);

	// 	//add dot to draw list
	// 	Vector3 screenPos = WorldToScreen(pos, viewMatrix);

	// 	if (config::visuals::esp::dot) {

	// 		if(screenPos.x != -1 && screenPos.y != -1){
	// 			//void ImDrawList::AddCircle(const ImVec2& center, float radius, ImU32 col, int num_segments, float thickness)
	// 			// ImGui::GetBackgroundDrawList()->AddCircle(ImVec2(screenPos.x, screenPos.y), 5, ImColor(255, 255, 255, 255), 4, 3);
	// 			Draw::Circle(Vector2(screenPos.x,screenPos.y), 5, FromFloatToColour(config::visuals::esp::dotColour), 3, 4 );
				
	// 		}
	// 	}


	// 	if (config::visuals::esp::health) {
			
	// 		float health_perc = pHealth/100;
	// 		Colour healthColour;
	// 		if(health_perc > 0.75) {
	// 			healthColour = {0.0700, 1.00, 0.256, 1.0};
	// 		} else if (health_perc > 0.25) {
	// 			healthColour = {0.920, 0.665, 0.156, 1.0 };
	// 		} else {
	// 			healthColour = {0.820, 0.303, 0.321, 1.0};
	// 		}

	// 		int barSize = pHealth;

	// 		Draw::RectFilled(Vector2(screenPos.x - barSize/2 +2, screenPos.y + 8), Vector2(screenPos.x + barSize/2 +2, screenPos.y + 17), {0.0f, 0.0f, 0.0f, 1.0f});
	// 		Draw::RectFilled(Vector2(screenPos.x - barSize/2, screenPos.y + 10), Vector2(screenPos.x + barSize/2, screenPos.y + 15), healthColour);
	// 	}

	// 	if (config::visuals::esp::distance){

	// 		Vector3 Distance = localPos - pos;

	// 		float distance = sqrt(Distance.x * Distance.x + Distance.y * Distance.y + Distance.z * Distance.z);
	// 		if(distance < config::visuals::esp::distanceLimit){
	// 			char buffer[256];
	// 			sprintf(buffer, "Distance: %f", distance);
	// 			Draw::Text(Vector2(screenPos.x, screenPos.y + 30), buffer, FromFloatToColour(config::visuals::esp::distanceColour), true);
	// 		}
	// 	}

	// 	if (config::visuals::esp::name) {

	// 		uintptr_t player_name = *reinterpret_cast<uintptr_t*>(entityController + client_dll::CCSPlayerController::m_sSanitizedPlayerName);
	// 		if(player_name){
	// 			char buffer[256];
	// 			sprintf(buffer, "Name: %s", (char*)player_name);
	// 			Draw::Text(Vector2(screenPos.x, screenPos.y - 40), buffer, FromFloatToColour(config::visuals::esp::nameColour), true);
	// 		}
	// 	}


	// 	// if (config::visuals::esp::ammo) {
			
	// 	// 	uintptr_t weaponServices = *reinterpret_cast<uintptr_t*>(entityPawn + client_dll::C_BasePlayerPawn::m_pWeaponServices);

	// 	// 	// CHandle<uintptr_t> activeWeapon = *reinterpret_cast<CHandle<uintptr_t>*>(weaponServices + client_dll::CPlayer_WeaponServices::m_hActiveWeapon);

	// 	// 	// if(activeWeapon.Get()){
	// 	// 	// 	uintptr_t* weapon = activeWeapon.Get();
	// 	// 	// 	uintptr_t weaponAmmo = *reinterpret_cast<uintptr_t*>(weapon + client_dll::C_BasePlayerWeapon::m_iClip1);
	// 	// 	// 	if(weaponAmmo){
	// 	// 	// 		char buffer[256];
	// 	// 	// 		sprintf(buffer, "Ammo: %s", (char*)weaponAmmo);
	// 	// 	// 		Draw::Text(Vector2(screenPos.x, screenPos.y - 50), buffer, FromFloatToColour(config::visuals::esp::ammoColour), true);
	// 	// 	// 	}
	// 	// 	// }

	// 	// 	//        constexpr std::ptrdiff_t m_iAmmo = 0x60; // uint16[32]

	// 	// 	UINT16 ammo[32] = *reinterpret_cast<UINT16*>			

	// 	// }


		
		
		

	// }

	// if (config::visuals::esp::bomb) {

	// 	uintptr_t wbomb = *(uintptr_t*)(data::client_dll + offsets::client_dll::dwWeaponC4);
	// 	if (wbomb) {
	// 	printf("Weapon C4: %p", wbomb);
	// 	}

	// 	uintptr_t pbomb = *(uintptr_t*)(data::client_dll + offsets::client_dll::dwPlantedC4);
	// 	if (pbomb) {
	// 	printf("Planted C4: %p", pbomb);
	// 	}


	// 	// if(bomb){
	// 	// 	uintptr_t bombNode = *(uintptr_t*)(bomb + client_dll::C_BaseEntity::m_pGameSceneNode);
	// 	// 	if (!bombNode) {
	// 	// 		return;
	// 	// 	}

	// 	// 	// bool bombPlanted = *reinterpret_cast<bool*>(bomb + client_dll::C_C4::m_bBombPlanted);
	// 	// 	// if(bombNode){
	// 	// 	// 	Vector3 bombPos = *reinterpret_cast<Vector3*>(bombNode + client_dll::CGameSceneNode::m_vecOrigin);
	// 	// 	// 	Vector3 screenPos = WorldToScreen(bombPos, viewMatrix);
	// 	// 	// 	if(bombPlanted){
	// 	// 	// 		// float timeLeft = *reinterpret_cast<float*>(bomb + client_dll::C_PlantedC4::m_flTimerLength);


	// 	// 	// 		if(screenPos.x != -1 && screenPos.y != -1){
	// 	// 	// 			char buffer[256];
	// 	// 	// 			sprintf(buffer, "Bomb Planted");
	// 	// 	// 			Draw::Text(Vector2(screenPos.x, screenPos.y - 20), buffer, FromFloatToColour(config::visuals::esp::bombColour), true);
	// 	// 	// 			// sprintf(buffer, "Time Left: %f", timeLeft);
	// 	// 	// 			// Draw::Text(Vector2(screenPos.x, screenPos.y), buffer, FromFloatToColour(config::visuals::esp::bombColour), true);
	// 	// 	// 		}
	// 	// 	// 	}
	// 	// 	// }
			
	// 	// }
			
	// }


}
