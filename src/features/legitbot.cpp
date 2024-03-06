#include <legitbot.h>
#include <config.h>
#include <playerlist.h>
#include <framework.h>
#include <windows.h>
#include <data.h>

#include <string>


void legitbot::run(){


	

	while (!framework::exit){

		if(!config::legitbot::enabled){
			continue;
		}



		if(config::legitbot::triggerbot::enabled){
			triggerbot();
		}	
	}
	
}


void legitbot::triggerbot(){


	if(!playerlist::setupcomplete){
		return;
	}

	C_CSPlayerPawn* localPlayer = ez_cast(C_CSPlayerPawn, data::client_dll + offsets::client_dll::dwLocalPlayerPawn);

	uintptr_t local_playerptr = *reinterpret_cast<uintptr_t*>(data::client_dll + offsets::client_dll::dwLocalPlayerPawn);

	if(localPlayer == nullptr){
		return;
	}




	if(localPlayer->m_iHealth <= 0){
		return;
	}

	if(localPlayer->m_bHasMovedSinceSpawn == false){
		return;
	}

	if(GetAsyncKeyState(config::legitbot::triggerbot::key)){

		if(localPlayer->m_iIDEntIndex != -1){

			uintptr_t Entity = *reinterpret_cast<uintptr_t*>(data::client_dll + offsets::client_dll::dwEntityList);

			uintptr_t listEntity = *reinterpret_cast<uintptr_t*>(Entity + (0x8 * ((localPlayer->m_iIDEntIndex & 0x7FFF) >> 9) + 16));
			if (listEntity == 0)
				return;


			C_CSPlayerPawn* entityPawn = ez_cast(C_CSPlayerPawn,(listEntity + (120) * (localPlayer->m_iIDEntIndex & 0x1FF)));
			if (entityPawn == 0)
				return;


			if (entityPawn->m_pClassType != localPlayer->m_pClassType) {	
				DLOG("ptr %d is not the same class as the local player\n", localPlayer->m_iIDEntIndex);
				return;
			}


			if(config::legitbot::triggerbot::friendlyFire == false){
				if(entityPawn->m_iTeamNum == localPlayer->m_iTeamNum){

					DLOG("Player %d is on the same team\n", localPlayer->m_iIDEntIndex);
					return;
				}
			}

			if(config::legitbot::triggerbot::scopedOnly){
				if(localPlayer->m_bIsScoped == false){
					DLOG("Local Player is not scoped\n");
					return;
				}
			}

			// if(config::legitbot::triggerbot::ignoreJump){  figure this out sometime- not really important for now
			// 	if(playerlist::localPlayer.controller->m_b){
			// 		return;
			// 	}
			// }

			if(config::legitbot::triggerbot::ignoreFlash){
				if(localPlayer->m_flFlashMaxAlpha >= config::legitbot::triggerbot::flashAlpha){
					DLOG("Local Player is flashed\n");
					return;
				}
			}


			//figure out ignore smoke sometime
			// if(config::legitbot::triggerbot::ignoreSmoke){
			// 	//if(smoke)
			// 	return
			// }


			if(config::legitbot::triggerbot::delayShot){
				std::this_thread::sleep_for(std::chrono::milliseconds(config::legitbot::triggerbot::delay));
			}


			*data::dwForceAttack = 65537;

			std::this_thread::sleep_for(std::chrono::milliseconds(2));

			*data::dwForceAttack = 256;


		}


	}

	
}