#pragma once
#include <Windows.h>
#include <gui.h>
#include <MinHook.h>

#include <d3d11.h>
#include <dxgi1_2.h>

namespace hooks {

    void* GetVFunc(void* thisptr, size_t index);

    using presentScene = HRESULT(__stdcall*)(IDXGISwapChain*, UINT, UINT);
    extern presentScene oPresentScene;

    HRESULT __stdcall hkPresentScene(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags);


    using resizeBuffers = HRESULT(__stdcall*)(IDXGISwapChain*, UINT, UINT, UINT, DXGI_FORMAT, UINT);
    extern resizeBuffers oResizeBuffers;

    HRESULT __stdcall hkResizeBuffers(IDXGISwapChain* pSwapChain, UINT BufferCount, UINT Width, UINT Height, DXGI_FORMAT NewFormat, UINT SwapChainFlags);

    //translate this block into the accepted state
    // static CHook<void __fastcall(void*, int)> g_frameStageNotify;
    // static void __fastcall hkFrameStageNotify(void* rcx, int frameStage) {
    // skin_changer::OnFrameStageNotify(frameStage);
    // return g_frameStageNotify(rcx, frameStage);
    // }


    // using frameStageNotify = void(__fastcall*)(void* rcx, int frameStage);
    // extern frameStageNotify oFrameStageNotify;

    // void __fastcall hkFrameStageNotify(void* rcx, int frameStage);





    void Init();
    // void InitGameHooks();
    void Destroy();
}