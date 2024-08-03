#pragma once
#pragma warning(disable : 4477)


#include <stdio.h>

#ifdef _DEBUG
	#define DLOG(fmt, ...) printf(fmt, ##__VA_ARGS__)
#else
	#define DLOG(fmt, ...)
#endif


#ifdef _DEBUG
	#define DBOX(message, type) MessageBoxA(nullptr, message, type, MB_OK)
#else
	#define DBOX(message, type)
#endif


#define ez_cast(type, value) *reinterpret_cast<type**>(value) // pKek macro for casting memory to a type pointer


