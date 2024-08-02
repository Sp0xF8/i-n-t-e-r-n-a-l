#include <gui.h>
#include <config.h>
#include <menu.h>
#include <defines.h>
#include <visuals.h>
#include <draw.h>

#include <imgui.h>
#include <imgui_impl_dx11.h>
#include <imgui_impl_win32.h>

extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd,
															 UINT msg,
															 WPARAM wParam,
															 LPARAM lParam);

namespace gui {
    bool setupComplete = false;


	int windowWidth = 0;
	int windowHeight = 0;

    HWND pWindow = nullptr;
    WNDPROC oWndProc = nullptr;
    ID3D11Device* pDevice = nullptr;
    ID3D11DeviceContext* pContext = nullptr;
    ID3D11RenderTargetView* pRenderTargetView = nullptr;
    IDXGISwapChain* pSwapChain = nullptr;
    
}

BOOL CALLBACK gui::EnumWindowsCallback(HWND handle, LPARAM lParam) {
    
    const auto focusWindow = [handle]() {
        return GetWindow(handle, GW_OWNER) == nullptr && IsWindowVisible(handle) && handle != GetConsoleWindow();
    };

    DWORD pID = 0;

    GetWindowThreadProcessId(handle, &pID);

    if(GetCurrentProcessId() != pID || !focusWindow())
        return TRUE;
    
    *reinterpret_cast<HWND*>(lParam) = handle;

    return FALSE;

}


LRESULT gui::hkWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    
    if(GetAsyncKeyState(VK_DELETE) & 1) {
        config::menu::isOpen = !config::menu::isOpen;
    }

    if (config::menu::isOpen) {
        ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam);
        return TRUE;
    }

    return CallWindowProc(oWndProc, hWnd, uMsg, wParam, lParam);

}

void gui::HookInput() {
    while(!pWindow) {
        EnumWindows(gui::EnumWindowsCallback, reinterpret_cast<LPARAM>(&pWindow));
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    gui::pWindow = pWindow;


    gui::oWndProc = reinterpret_cast<WNDPROC>(SetWindowLongPtr(pWindow, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(hkWndProc)));
}

void gui::UnhookInput() {
    if(oWndProc){
        SetWindowLongPtr(pWindow, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(oWndProc));
    }
}

bool gui::CreateDevice() {
    DXGI_SWAP_CHAIN_DESC params = {};
    params.Windowed = TRUE;
    params.BufferCount = 2;
    params.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    params.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    params.OutputWindow = gui::pWindow;
    params.SampleDesc.Count = 1;



    D3D_FEATURE_LEVEL featureLevels[] = { D3D_FEATURE_LEVEL_11_0, D3D_FEATURE_LEVEL_10_0 };

    HRESULT hr = D3D11CreateDeviceAndSwapChain(NULL, D3D_DRIVER_TYPE_NULL, NULL, 0, featureLevels, 2, D3D11_SDK_VERSION, &params, &gui::pSwapChain, &gui::pDevice, nullptr, nullptr); // change final param to null if error

    if(hr != S_OK) {
        MessageBox(nullptr, "Failed to create device and swapchain", "Info", MB_OK);
        return false;
    }
    return true;
}

void gui::DestroyDevice() {
    gui::DestroyRenderTarget();

    if(pSwapChain) {
        pSwapChain->Release();
        pSwapChain = NULL;
    }

    if(pDevice) {
        pDevice->Release();
        pDevice = NULL;
    }

    if(pContext) {
        pContext->Release();
        pContext = NULL;
    }
}

void gui::CreateRenderTarget(IDXGISwapChain* pSwapChain) {
    ID3D11Texture2D* pBackBuffer = nullptr;
    pSwapChain->GetBuffer(0, IID_PPV_ARGS(&pBackBuffer));

    if(pBackBuffer) {
        DXGI_SWAP_CHAIN_DESC swap_params = {};
        pSwapChain->GetDesc(&swap_params);

        D3D11_RENDER_TARGET_VIEW_DESC desc = {};
        
        if(swap_params.BufferDesc.Format == DXGI_FORMAT_R8G8B8A8_UNORM_SRGB) {
            desc.Format = static_cast<DXGI_FORMAT>(DXGI_FORMAT_R8G8B8A8_UNORM);
        } else {
            desc.Format = static_cast<DXGI_FORMAT>(swap_params.BufferDesc.Format);
        }

        desc.ViewDimension = D3D11_RTV_DIMENSION_TEXTURE2DMS;

        if(FAILED(pDevice->CreateRenderTargetView(pBackBuffer, &desc, &pRenderTargetView))) {
            MessageBox(nullptr, "Failed to create render target view", "Info", MB_OK);

            desc.ViewDimension = D3D11_RTV_DIMENSION_TEXTURE2D;
            if(FAILED(pDevice->CreateRenderTargetView(pBackBuffer, &desc, &pRenderTargetView))) {
                MessageBox(nullptr, "Failed to create render target view", "Info", MB_OK);
                if(FAILED(pDevice->CreateRenderTargetView(pBackBuffer, nullptr, &pRenderTargetView))) {
                    MessageBox(nullptr, "Severe Error in create render target", "Info", MB_OK);
                }
            }

        }

        pBackBuffer->Release();
        
    }
}

void gui::DestroyRenderTarget() {
    if(pRenderTargetView) {
        pRenderTargetView->Release();
        pRenderTargetView = NULL;
    }
}

bool gui::Init(){
    if(!gui::CreateDevice()){
        MessageBox(nullptr, "Failed to create device", "Info", MB_OK);
        return false;
    }

	DLOG("\n=======================================================\n");
	DLOG("                    Device Created\n");
	DLOG("=======================================================\n");
	DLOG("gui::pSwapChain:                    0x%p\n", gui::pSwapChain);
	DLOG("gui::pDevice:                       0x%p\n", gui::pDevice);
	DLOG("=======================================================\n \n");


    return true;
}


bool gui::Destroy(){
    
    ImGui_ImplDX11_Shutdown();
    ImGui_ImplWin32_Shutdown();
    ImGui::DestroyContext();

    SetClassLongA(gui::pWindow, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(gui::oWndProc));
    
    gui::DestroyDevice();

    
    return true;
}

void gui::SetupMenu(IDXGISwapChain* pSwapChain){

    if(!ImGui::GetCurrentContext()){
        ImGui::CreateContext();
        ImGui_ImplWin32_Init(gui::pWindow);

    }

    if(!ImGui::GetIO().BackendRendererUserData){
        if(SUCCEEDED(pSwapChain->GetDevice(__uuidof(ID3D11Device), reinterpret_cast<void**>(&gui::pDevice)))){
            gui::pDevice->GetImmediateContext(&gui::pContext);
            ImGui_ImplDX11_Init(gui::pDevice, gui::pContext);


            ImGuiIO& io = ImGui::GetIO();

            ImVector<ImWchar> ranges;
            ImFontGlyphRangesBuilder builder;

            builder.AddRanges(io.Fonts->GetGlyphRangesDefault());
            builder.AddRanges(io.Fonts->GetGlyphRangesCyrillic());
            builder.BuildRanges(&ranges);

            io.Fonts->Build();

        }
    }

    if(!pRenderTargetView){
        gui::CreateRenderTarget(pSwapChain);
    }


    setupComplete = true;
}

void gui::Render(IDXGISwapChain* pSwapChain) {

    ImGui_ImplDX11_NewFrame();
    ImGui_ImplWin32_NewFrame();
    ImGui::NewFrame();


	//Draw::Line(Vector2(0, 0), Vector2(windowWidth, windowHeight), Colour(255, 255, 255, 255), 1.0f);

	
	if(config::menu::isOpen) {
		ImGui::Begin("SPY", &config::menu::isOpen,
							ImGuiWindowFlags_NoCollapse |
							ImGuiWindowFlags_NoResize |
							ImGuiWindowFlags_NoScrollbar |
							ImGuiWindowFlags_NoTitleBar);

		{
			menu::PopTheme();
			{
				menu::DrawMenu();
			}
		}
		
		ImGui::End();
	}
    


	visuals::run();
    
    

    ImGui::Render();
    gui::pContext->OMSetRenderTargets(1, &pRenderTargetView, nullptr);
    ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
}