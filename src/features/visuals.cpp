#include <visuals.h>
#include <playerlist.h>
#include <config.h>
#include <draw.h>
#include <gui.h>
#include <data.h>

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

	if(!playerlist::setupcomplete){
		return;
	}

	// DLOG("Running visuals\n");
	
	// DLOG("viewMatrix: %p\n", playerlist::viewMatrix);
	// DLOG("viewMatrix[0][0]: %f\n", playerlist::viewMatrix.matrix[0][0]);
	
	for (int i = 0; i < 32; i++) {

		DLOG("====================================\n");
		DLOG("Running visuals for player %d\n", i);
		

		DLOG("playerlist::players[i].controller: %p\n", playerlist::players[i].controller);
		DLOG("playerlist::players[i].pawn: %p\n", playerlist::players[i].pawn);

		DLOG("Player %d : %s\n", i, playerlist::players[i].Active() ? "active" : "inactive");
		if (!playerlist::players[i].Active()) {
			continue;
		}


		if(!config::visuals::drawTeam){
			if(playerlist::players[i].controller->m_iTeamNum == playerlist::localPlayer.controller->m_iTeamNum){

				DLOG("Player %d is on the same team\n", i);
				continue;
			} else {
				DLOG("Player %d is on the other team\n", i);
			}
		}



		if(playerlist::players[i].pawn == playerlist::localPlayer.pawn){
			DLOG("Player %d is the LOCAL PLAYER\n", i);
			//continue;
		}

		DLOG("playerlist::players[i].pawn->m_iIDEntIndex: %d\n", playerlist::players[i].pawn->m_iIDEntIndex);

		DLOG("m_pClasstype %d: %p\n", i, playerlist::players[i].pawn->m_pClassType);
		DLOG("m_pClasstype& %d: %p\n", i, &playerlist::players[i].pawn->m_pClassType);

		DLOG("localPlayer.m_pClasstype: %p\n", playerlist::localPlayer.pawn->m_pClassType);
		DLOG("localPlayer.m_pClasstype&: %p\n", &playerlist::localPlayer.pawn->m_pClassType);


		if(playerlist::players[i].pawn->m_pClassType != playerlist::localPlayer.pawn->m_pClassType){
			DLOG("ptr %d is not the same class as the local player\n", i);
			
		} else {
			DLOG("ptr %d is the same class as the local player\n", i);
		}


		if(playerlist::players[i].pawn->m_iHealth <= 0){
			DLOG("Player %d is dead\n", i);
			continue;
		} else {
			DLOG("Player %d is alive : %d\n", i, playerlist::players[i].pawn->m_iHealth);
		}

		


		if(config::visuals::esp::skeleton){
			skeleton_esp(i);
		}

		if(config::visuals::esp::name){
			name_esp(i);
		}

		if(config::visuals::esp::health){
			health_esp(i);
		}

	}

	



}






enum boneids : int {
	HEAD = 6,
	NECK = 5,
	SPINE = 4,
	SPINE_BOTTOM = 2,
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
	bone_connection(boneids::HEAD, boneids::NECK),
	bone_connection(boneids::NECK, boneids::SPINE),
	bone_connection(boneids::SPINE, boneids::SPINE_BOTTOM),
	bone_connection(boneids::SPINE, boneids::LEFT_SHOULDER),
	bone_connection(boneids::SPINE, boneids::RIGHT_SHOULDER),
	bone_connection(boneids::LEFT_SHOULDER, boneids::LEFT_ELBOW),
	bone_connection(boneids::LEFT_ELBOW, boneids::LEFT_HAND),
	bone_connection(boneids::RIGHT_SHOULDER, boneids::RIGHT_ELBOW),
	bone_connection(boneids::RIGHT_ELBOW, boneids::RIGHT_HAND),
	bone_connection(boneids::SPINE_BOTTOM, boneids::LEFT_HIP),
	bone_connection(boneids::LEFT_HIP, boneids::LEFT_KNEE),
	bone_connection(boneids::LEFT_KNEE, boneids::LEFT_FOOT),
	bone_connection(boneids::SPINE_BOTTOM, boneids::RIGHT_HIP),
	bone_connection(boneids::RIGHT_HIP, boneids::RIGHT_KNEE),
	bone_connection(boneids::RIGHT_KNEE, boneids::RIGHT_FOOT)
};

void visuals::skeleton_esp(int index){

	if(!playerlist::players[index].Active()){
		return;
	}



	


	for (int r = 0; r < sizeof(bone_connections) / sizeof(bone_connection); r++) {

		if(playerlist::players[index].pawn->m_pClassType != playerlist::localPlayer.pawn->m_pClassType){
			continue;
		}


		if(playerlist::players[index].pawn->m_pGameSceneNode->m_pModelState == nullptr){
			continue;
		}

		if(playerlist::players[index].pawn->m_pGameSceneNode->m_pModelState->pBoneMatrix == NULL){
			continue;
		}
		Vector3 bone1 = *(Vector3*)(playerlist::players[index].pawn->m_pGameSceneNode->m_pModelState->pBoneMatrix + bone_connections[r].bone1 * 0x20);
		Vector3 bone2 = *(Vector3*)(playerlist::players[index].pawn->m_pGameSceneNode->m_pModelState->pBoneMatrix + bone_connections[r].bone2 * 0x20);



		Vector2 bone1_wts = WorldToScreen(bone1, playerlist::viewMatrix).to_vector2();
		Vector2 bone2_wts = WorldToScreen(bone2, playerlist::viewMatrix).to_vector2();


		Draw::Line(bone1_wts, bone2_wts, FromFloatToColour(config::visuals::esp::skeletonColour), 2);
	}
}


void visuals::name_esp(int index){

	if(playerlist::players[index].pawn->m_pClassType != playerlist::localPlayer.pawn->m_pClassType){
			return;
		}

	if(playerlist::players[index].controller->m_pClassType != playerlist::localPlayer.controller->m_pClassType){
		return;
	}


	Vector3 feet = (Vector3)(playerlist::players[index].pawn->m_pGameSceneNode->m_vecOrigin);
	Vector2 feet_wts = WorldToScreen(feet, playerlist::viewMatrix).to_vector2();

	Draw::Text(feet_wts, playerlist::players[index].controller->m_sSanitizedPlayerName, FromFloatToColour(config::visuals::esp::nameColour), true);


}

void visuals::health_esp(int index){

	if(playerlist::players[index].pawn->m_pClassType != playerlist::localPlayer.pawn->m_pClassType){
			return;
		}


	Vector3 bottom_of_bar = (Vector3)(playerlist::players[index].pawn->m_pGameSceneNode->m_vecOrigin);


	Vector3 head = *(Vector3*)(playerlist::players[index].pawn->m_pGameSceneNode->m_pModelState->pBoneMatrix + boneids::HEAD * 0x20);

	float height = bottom_of_bar.z - head.z;

	

	Vector3 top_of_bar = bottom_of_bar;
	top_of_bar.z -= (height * ( playerlist::players[index].pawn->m_iHealth / 100.0f));



	Vector2 bottom_of_bar_wts = WorldToScreen(bottom_of_bar, playerlist::viewMatrix).to_vector2();
	Vector2 top_of_bar_wts = WorldToScreen(top_of_bar, playerlist::viewMatrix).to_vector2();


	float radius = (bottom_of_bar_wts.y - top_of_bar_wts.y) / 3.0f;

	bottom_of_bar_wts.x -= radius;
	top_of_bar_wts.x -= radius;

	Colour playerHealthColour = Colour(0.0f, 1.0f, 0.0f, 1.0f);

	if (playerlist::players[index].pawn->m_iHealth < 75) {
		playerHealthColour = Colour(1.0f, 1.0f, 0.0f, 1.0f);
	}
	else if (playerlist::players[index].pawn->m_iHealth < 50) {
		playerHealthColour = Colour(1.0f, 0.5f, 0.0f, 1.0f);
	}
	else if (playerlist::players[index].pawn->m_iHealth < 30) {
		playerHealthColour = Colour(1.0f, 0.0f, 0.0f, 1.0f);
	}

	Draw::Line(bottom_of_bar_wts, top_of_bar_wts, playerHealthColour, 2);

}
