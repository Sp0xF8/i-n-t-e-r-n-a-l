#include <framework.h>
#include <gui.h>
#include <hooks.h>
#include <data.h>
#include <defines.h>
#include <offsets.h>
#include <string>
#include <legitbot.h>



namespace framework {
	bool exit = false;

	std::thread legitbot_thread;

}




bool framework::Init() {
    
    gui::HookInput();
    gui::Init();

    hooks::Init();


	data::setup();





	//get current build number

	int buildNumber = *(int*)(data::engine2_dll + offsets::engine2_dll::dwBuildNumber);
	//MessageBoxA(NULL, std::to_string(buildNumber).c_str(), "Build Number", MB_OK);


	gui::windowHeight = *(int*)(data::engine2_dll + offsets::engine2_dll::dwWindowHeight);
	gui::windowWidth = *(int*)(data::engine2_dll + offsets::engine2_dll::dwWindowWidth);

	if(buildNumber != data::latestBuildNumber){
		DLOG("=======================================================\n");
		DLOG("                     Build Mismatch\n");
		DLOG("=======================================================\n");
		DLOG("Current Build: %p\n", buildNumber);
		DLOG("Latest Build: %d\n", data::latestBuildNumber);
		DLOG("=======================================================\n");
		//MessageBoxA(NULL, "Build Mismatch", "Error", MB_OK);
		return false;
	}

	DLOG("=======================================================\n");
	DLOG("                     Setup Complete\n");
	DLOG("=======================================================\n");
	DLOG("data::client_dll:                   0x%p\n", data::client_dll);
	DLOG("data::engine2_dll:                  0x%p\n", data::engine2_dll);

	DLOG("gui::windowHeight:                  %d\n", gui::windowHeight);
	DLOG("gui::windowWidth:                   %d\n", gui::windowWidth);
	DLOG("=======================================================\n");


	legitbot_thread = std::thread(legitbot::run);

	

	return true;

}

void framework::Destroy() {

	legitbot_thread.join();

	hooks::Destroy();
	gui::Destroy();
	gui::UnhookInput();


	

}