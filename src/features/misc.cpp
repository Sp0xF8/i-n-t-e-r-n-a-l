#include <misc.h>
#include <config.h>
#include <framework.h>
#include <playerlist.h>
#include <data.h>

#include <windows.h>

void misc::run(){


	while (!framework::exit){
		

		if(!config::misc::enabled){
			continue;
		}

		if(!playerlist::setupcomplete){
			continue;
		}

		if(config::misc::bunnyhop){
			bunnyhop();
		}

	}
}


void misc::bunnyhop(){

	
	if(GetAsyncKeyState(VK_SPACE) && playerlist::localPlayer.pawn->m_fFlags == 65665){

		std::this_thread::sleep_for(std::chrono::milliseconds(1));

		*data::dwForceJump = 65537;

		std::this_thread::sleep_for(std::chrono::milliseconds(10));

		*data::dwForceJump = 256;
	}
	

}