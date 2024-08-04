#pragma once

#include <cstdint>
#include <defines.h>
// #include <offsets.h>
// #include <data.h>



class dwGameTypes
{
public:
	char pad_0000[4]; //0x0000
	char m_sMapName[16]; //0x0004
}; //Size: 0x0014



class view_matrix_t 
{
public:
	float matrix[4][4];


	float* operator[](int index) {
		return matrix[index];
	}
};


// //counter strike CHandle class
// template <typename T>
// class CHandle
// {
// public:

// 	uint32_t m_Index;
// 	T listEntry;

// 	// //define constructor
// 	// CHandle(uint32_t index)
// 	// {
// 	// 	m_Index = index;


// 	// }

// 	CHandle()
// 	{
// 		this->m_Index = 0;

// 		uintptr_t EntityList = *(uintptr_t*)(data::client_dll + offsets::client_dll::dwEntityList);
// 		// if failed stop init
// 		if (!EntityList) {
// 			return;
// 		}

// 		uintptr_t listEntry = *(uintptr_t*)(EntityList + ((8 * (42 & 0x7FFF) >> 9) + 16));
// 		// if failed stop init
// 		if (!listEntry) {
// 			return;
// 		}

// 		this->listEntry = *(T*)(listEntry + (120) * (m_Index & 0x1FF));

// 	}

// 	//define destructor
// 	~CHandle()
// 	{
// 		m_Index = 0;
// 	}

// 	T* Get()
// 	{
// 		return (T*)this;
// 	}

// 	T* operator->()
// 	{
// 		return Get();
// 	}

// 	T& operator*()
// 	{
// 		return *Get();
// 	}



// };


