#include <framework.h>
#include <gui.h>
#include <hooks.h>
// #include <data.h>
#include <defines.h>
#include <offsets.h>
#include <string>
#include <GPointers.h>


namespace framework {
	bool exit = false;

}




bool framework::Init() {
    
	// hook inputs from winapi
    gui::HookInput();
	//create device / swapchain
    gui::Init();

	//create hooks pertaining to ingame / rendering functions
    hooks::Init();

	//setup data
	// data::setup();

	gPointers.init();





	//get current build number

	int buildNumber = *(int*)(gPointers.Engine_dll->ptr + offsets::engine2_dll::dwBuildNumber);
	//MessageBoxA(NULL, std::to_string(buildNumber).c_str(), "Build Number", MB_OK);


	gui::windowHeight = *(int*)(gPointers.Engine_dll->ptr + offsets::engine2_dll::dwWindowHeight);
	gui::windowWidth = *(int*)(gPointers.Engine_dll->ptr + offsets::engine2_dll::dwWindowWidth);

	if(buildNumber != offsets::game_info::buildNumber){
		DLOG("=======================================================\n");
		DLOG("                     Build Mismatch\n");
		DLOG("=======================================================\n");
		DLOG("Current Build:				%d\n", buildNumber);
		DLOG("Latest Build: 				%d\n", offsets::game_info::buildNumber);
		DLOG("=======================================================\n");
		MessageBoxA(NULL, "Build Mismatch", "Error", MB_OK);
		return false;
	}

	DBOX("Build Matches", "info");

	DLOG("=======================================================\n");
	DLOG("                     Setup Complete\n");
	DLOG("=======================================================\n");
	DLOG("gPointers.Client_dll:				0x%p\n", gPointers.Client_dll->ptr);
	DLOG("gPointers.Engine_dll:				0x%p\n", gPointers.Engine_dll->ptr);

	DLOG("gui::windowHeight:				%d\n", gui::windowHeight);
	DLOG("gui::windowWidth:					%d\n", gui::windowWidth);
	DLOG("=======================================================\n");


	return true;

}

void framework::Destroy() {

	hooks::Destroy();
	gui::Destroy();
	gui::UnhookInput();


	

}