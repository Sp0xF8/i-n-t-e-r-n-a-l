#pragma once


#include <thread>

namespace framework {
	extern bool exit;


	extern std::thread legitbot_thread;
	extern std::thread misc_thread;

    bool Init();
    void Destroy();
}