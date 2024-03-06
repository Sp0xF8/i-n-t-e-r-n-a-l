#include <misc.h>
#include <config.h>
#include <framework.h>
#include <playerlist.h>

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

	
	DLOG("Running bunnyhop\n");
	DLOG("LocalPlayer: %d\n", playerlist::localPlayer.pawn->m_iHealth);
	

}