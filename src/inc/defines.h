#pragma once


#ifdef _DEBUG
	#define DLOG(fmt, ...) printf(fmt, ##__VA_ARGS__)
#else
	#define DLOG(fmt, ...)
#endif