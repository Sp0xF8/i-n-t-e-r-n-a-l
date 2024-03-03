#include <Windows.h>
#include <framework.h>
#include <defines.h>

#include <data.h>

#ifdef _DEBUG
    #include <stdio.h>
#endif

void Unload(){

    

	DLOG("=======================================================\n");
	DLOG("                     Unloading\n");
	DLOG("=======================================================\n");


	framework::Destroy();

	DLOG("=======================================================\n");
	DLOG("                     Unloaded\n");
	DLOG("=======================================================\n");



	
}


void MainThread(const HMODULE dllHandle){

	 #ifdef _DEBUG
		AllocConsole();
		freopen("CONOUT$", "w", stdout);
	#endif
			
	DLOG("=======================================================\n");
	DLOG("                     DLL Injected\n");
	DLOG("=======================================================\n");


	DLOG("=======================================================\n");
	DLOG("                     Main Thread\n");
	DLOG("=======================================================\n");


	bool cont_op = true;

	if(!framework::Init()){
		DLOG("Error: MainThread() - framework::init() failed\n");
		Unload();
		cont_op = false;
	}


	

    

	while (cont_op){





		if (GetAsyncKeyState(VK_INSERT) & 1){
			Unload();
			cont_op = false;
		}
		Sleep(100);
	}

	

	#ifdef _DEBUG

		DLOG("+FREE CONSOLE\n");
		FreeConsole();
	#endif


	FreeLibraryAndExitThread(dllHandle, 0);
    MessageBox(nullptr, "Unloaded", "Info", MB_OK);
    
}


BOOL WINAPI DllMain(HMODULE hModule, DWORD dwReason, LPVOID lpReserved){

    if (dwReason == DLL_PROCESS_ATTACH){
       
        
        
        DisableThreadLibraryCalls(hModule);

        HANDLE hThread = CreateThread(
                                NULL, 0,
                                reinterpret_cast<LPTHREAD_START_ROUTINE>(MainThread),
                                hModule, 0, NULL
                            );

        if (!hThread){
            CloseHandle(hThread);
        }
    }
}



