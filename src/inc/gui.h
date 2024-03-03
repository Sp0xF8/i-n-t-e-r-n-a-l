#pragma once

#include <Windows.h>

#include <thread>

#include <d3d11.h>

namespace gui {
    extern bool setupComplete;
	extern bool isOpen;

	extern int windowWidth;
	extern int windowHeight;


    extern HWND pWindow;
    extern WNDPROC oWndProc;
    extern ID3D11Device* pDevice;
    extern ID3D11DeviceContext* pContext;
    extern ID3D11RenderTargetView* pRenderTargetView;
    extern IDXGISwapChain* pSwapChain;

    // Hook input
    BOOL CALLBACK EnumWindowsCallback(HWND handle, LPARAM lParam);
    LRESULT hkWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

    void HookInput();
    void UnhookInput();

    // Setup DirectX

    bool CreateDevice();
    void DestroyDevice();

    void CreateRenderTarget(IDXGISwapChain* pSwapChain);
    void DestroyRenderTarget();

    bool Init();
    
    void SetupMenu(IDXGISwapChain* pSwapChain);

    void Render(IDXGISwapChain* pSwapChain);

    bool Destroy();

}

