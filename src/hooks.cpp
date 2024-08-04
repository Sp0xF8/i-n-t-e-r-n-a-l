#include <hooks.h>
#include <config.h>
#include <defines.h>
#include <data.h>

#include <framework.h>


void* hooks::GetVFunc(void* thisptr, size_t index) {
	return (*static_cast<void***>(thisptr))[index];
}

namespace hooks {
    presentScene oPresentScene = nullptr;
    resizeBuffers oResizeBuffers = nullptr;
}

void hooks::Init(){

    // Init Setup

    if(!gui::pDevice){
        printf("Failed to hook presentScene: pDevice is null\n");
        return;
    }

	DLOG("=======================================================\n");
	DLOG("                       Hooks\n");
	DLOG("=======================================================\n");
	DLOG("gui::pDevice:                       0x%p\n", gui::pDevice);
	DLOG("gui::pSwapChain:                    0x%p\n", gui::pSwapChain);
	DLOG("=======================================================\n");

    if(MH_Initialize() != MH_OK){
        printf("MH_Initialize failed\n");
        return;
    }

    
    IDXGIDevice* pDXGIDevice = nullptr;
    IDXGIAdapter* pDXGIAdapter = nullptr;
    IDXGIFactory* pIDXGIFactory = nullptr;

    gui::pDevice->QueryInterface(__uuidof(IDXGIDevice), reinterpret_cast<void**>(&pDXGIDevice));

    pDXGIDevice->GetAdapter(&pDXGIAdapter);

    pDXGIAdapter->GetParent(__uuidof(IDXGIFactory), reinterpret_cast<void**>(&pIDXGIFactory));

    pIDXGIFactory->Release();
    pDXGIAdapter->Release();
    pDXGIDevice->Release();



    MH_CreateHook(GetVFunc(gui::pSwapChain, 8), (LPVOID)&hkPresentScene, reinterpret_cast<void**>(&oPresentScene));
    MH_CreateHook(GetVFunc(gui::pSwapChain, 13), (LPVOID)&hkResizeBuffers, reinterpret_cast<void**>(&oResizeBuffers));


    
    

    
    MH_EnableHook(MH_ALL_HOOKS);

    #ifdef _DEBUG_ALL                               
        printf("=======================================================\n");
        printf("                    Pre Destruction\n");
        printf("Gui::pSwapChain:                    0x%p\n", gui::pSwapChain);
        printf("Gui::pDevice:                       0x%p\n", gui::pDevice);
        printf("=======================================================\n");
    #endif

    gui::DestroyDevice();

    #ifdef _DEBUG_ALL
        printf("=======================================================\n");
        printf("Post Destruction\n");
        printf("Gui::pSwapChain:                    0x%p\n", gui::pSwapChain);
        printf("Gui::pDevice:                       0x%p\n", gui::pDevice);
        printf("=======================================================\n");
    #endif
}


void hooks::Destroy(){
    // Unhook input

    MH_DisableHook(MH_ALL_HOOKS);
	MH_RemoveHook(MH_ALL_HOOKS);
	MH_Uninitialize();
    
}



HRESULT __stdcall hooks::hkPresentScene(IDXGISwapChain* ppSwapChain, UINT SyncInterval, UINT Flags) { 
	
	if(framework::exit){
		return oPresentScene(ppSwapChain, SyncInterval, Flags);
	}

	DLOG("================Present Scene Debugging================\n");
	DLOG("pDevice:                            0x%p\n", gui::pDevice);
	DLOG("pSwapChain:                         0x%p\n", gui::pSwapChain);
	DLOG("ppSwapChain:                        0x%p\n", ppSwapChain);
	DLOG("Gui::setupComplete:                 0x%d\n", gui::setupComplete);


    if (!gui::setupComplete && ppSwapChain){
		gui::SetupMenu(ppSwapChain);
    } else if (!gui::setupComplete && !ppSwapChain) {
		MessageBoxA(nullptr, "lost Chain along the way", "Info", MB_OK);
		return oPresentScene(ppSwapChain, SyncInterval, Flags);
	}

    gui::Render(ppSwapChain);


    DLOG("================Present Scene Debugging================\n");

    return oPresentScene(ppSwapChain, SyncInterval, Flags);
}

HRESULT __stdcall hooks::hkResizeBuffers(IDXGISwapChain* pSwapChain, UINT BufferCount, UINT Width, UINT Height, DXGI_FORMAT NewFormat, UINT SwapChainFlags) {
    MessageBoxA(nullptr, "hkResizeBuffers", "Info", MB_OK);
    gui::DestroyRenderTarget();
    MessageBoxA(nullptr, "hkResizeBuffers2", "Info", MB_OK);
    return oResizeBuffers(pSwapChain, BufferCount, Width, Height, NewFormat, SwapChainFlags);
}
