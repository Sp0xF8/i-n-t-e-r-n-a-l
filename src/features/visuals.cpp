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


Vector2 WorldToScreen(const Vector3 vecOrigin, view_matrix_t matrix)
{
    
    float _w = matrix.matrix[3][0] * vecOrigin.x + matrix.matrix[3][1] * vecOrigin.y + matrix.matrix[3][2] * vecOrigin.z + matrix.matrix[3][3];

	if (_w < 0.01f)
		return { -1, -1};

	float _x = matrix.matrix[0][0] * vecOrigin.x + matrix.matrix[0][1] * vecOrigin.y + matrix.matrix[0][2] * vecOrigin.z + matrix.matrix[0][3];
	float _y = matrix.matrix[1][0] * vecOrigin.x + matrix.matrix[1][1] * vecOrigin.y + matrix.matrix[1][2] * vecOrigin.z + matrix.matrix[1][3];


	_x = (gui::windowWidth / 2) * (1 + _x / _w);
	_y = (gui::windowHeight / 2) * (1 - _y / _w);

		

    return Vector2(_x, _y);
}


enum boneids : int {
	HEAD = 6,
	SPINE = 5,
	SPINE_MIDDLE = 1,
	SPINE_BOTTOM = 0,
	LEFT_SHOULDER = 8,
	LEFT_ELBOW = 9,
	LEFT_HAND = 11,
	RIGHT_SHOULDER = 13,
	RIGHT_ELBOW = 14,
	RIGHT_HAND = 16,
	LEFT_HIP = 22,
	LEFT_KNEE = 23,
	LEFT_FOOT = 24,
	RIGHT_HIP = 25,
	RIGHT_KNEE = 26,
	RIGHT_FOOT = 27
};

struct bone_connection {
	int bone1;
	int bone2;

	bone_connection(int bone1, int bone2) : bone1(bone1), bone2(bone2) { }
};

bone_connection bone_connections[] = {
	bone_connection(boneids::HEAD, boneids::SPINE),
	bone_connection(boneids::SPINE, boneids::LEFT_SHOULDER),
	bone_connection(boneids::LEFT_SHOULDER, boneids::LEFT_ELBOW),
	bone_connection(boneids::LEFT_ELBOW, boneids::LEFT_HAND),
	bone_connection(boneids::LEFT_SHOULDER, boneids::LEFT_HIP),
	bone_connection(boneids::SPINE, boneids::RIGHT_SHOULDER),
	bone_connection(boneids::RIGHT_SHOULDER, boneids::RIGHT_ELBOW),
	bone_connection(boneids::RIGHT_ELBOW, boneids::RIGHT_HAND),
	bone_connection(boneids::RIGHT_SHOULDER,boneids::RIGHT_HIP),
	bone_connection(boneids::LEFT_HIP, boneids::LEFT_KNEE),
	bone_connection(boneids::LEFT_KNEE, boneids::LEFT_FOOT),
	bone_connection(boneids::RIGHT_HIP, boneids::RIGHT_KNEE),
	bone_connection(boneids::RIGHT_KNEE, boneids::RIGHT_FOOT),
	bone_connection(boneids::LEFT_HIP, boneids::RIGHT_HIP)
};



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

		if (config::visuals::drawSeen) {
			if (!playerPawn.bSpotted()){
				continue;
			}
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

		playerPawn.setSkeleton();

		Vector3 playerPos = playerPawn.getPosition();
		Vector2 screenPos = WorldToScreen(playerPos, viewMatrix);

		// DLOG("Player Controller %d @ %p \n",i, entity.getAddress());
		// DLOG("EntityHandle: %d\n", pawn);
		// DLOG("Player Pawn %d @ %p\n",i, playerPawn.getAddress());

		Vector3 headpos = playerPawn.jointPos(boneids::HEAD);
		Vector2 headScreen = WorldToScreen(headpos, viewMatrix);

		//height 

		int height = screenPos.y - headScreen.y;
		//add dot to draw list

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
			

			float health_perc = (float)playerHealth / 100.0f;

			DLOG("Health Perc %f", health_perc);
			Colour healthColour;
			if(health_perc > 0.75) {
				healthColour = {0.0700, 1.00, 0.256, 1.0};
			} else if (health_perc > 0.25) {
				healthColour = {0.920, 0.665, 0.156, 1.0 };
			} else {
				healthColour = {0.820, 0.303, 0.321, 1.0};
			}
			

			int barSize = height/2;
			int helthBar = barSize * health_perc;

			DLOG("BAR SIZE: %d\n", barSize);
			DLOG("Health Size %d\n", helthBar);

			Draw::RectFilled(Vector2(screenPos.x - barSize/2, screenPos.y + 8), Vector2(screenPos.x + barSize/2, screenPos.y + 17), {0.0f, 0.0f, 0.0f, 1.0f});
			Draw::RectFilled(Vector2(screenPos.x - helthBar/2, screenPos.y + 10), Vector2(screenPos.x + helthBar/2, screenPos.y + 15), healthColour);
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


		if (config::visuals::esp::skeleton){

			


			// for (int r=0; r < 32; r++){

			// 	//convert r to string
			// 	char buffer[4];
			// 	sprintf(buffer, "%d", r);
			// 	Vector3 joint = playerPawn.jointPos(r);
			// 	Vector3 jointScreen = WorldToScreen(joint, viewMatrix);
			// 	if(jointScreen.x != -1 && jointScreen.y != -1){
			// 		Draw::Text({jointScreen.x, jointScreen.y}, buffer, FromFloatToColour(config::visuals::esp::skeletonColour));
			// 	}
			// }

			//for each connection in bone connnections
			for (int i = 0; i < sizeof(bone_connections)/sizeof(bone_connection); i++){
				bone_connection connection = bone_connections[i];
				// Vector3 joint1 = playerPawn.jointPos(connection.bone1);
				// Vector3 joint2 = playerPawn.jointPos(connection.bone2);

				Vector2 joint1Screen = WorldToScreen(playerPawn.jointPos(connection.bone1), viewMatrix);
				Vector2 joint2Screen = WorldToScreen(playerPawn.jointPos(connection.bone2), viewMatrix);

				if(joint1Screen.x != -1 && joint1Screen.y != -1 && joint2Screen.x != -1 && joint2Screen.y != -1){
					Draw::Line(joint1Screen, joint2Screen, FromFloatToColour(config::visuals::esp::skeletonColour));
				}
			}
		}

	}

}

