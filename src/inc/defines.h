#pragma once


#include <stdio.h>

#ifdef _DEBUG
	#define DLOG(fmt, ...) printf(fmt, ##__VA_ARGS__)
#else
	#define DLOG(fmt, ...)
#endif



#define ez_cast(type, value) *reinterpret_cast<type**>(value) // pKek macro for casting memory to a type pointer




struct Vector2 {

	constexpr Vector2(
		const float x = 0.0f,
		const float y = 0.0f) noexcept :
		x(x), y(y) { }

	constexpr const Vector2 operator-(const Vector2& other) const noexcept {
		return Vector2(x - other.x, y - other.y);
	}

	constexpr const Vector2 operator+(const Vector2& other) const noexcept {
		return Vector2(x + other.x, y + other.y);
	}

	constexpr const Vector2 operator*(const float other) const noexcept {
		return Vector2(x * other, y * other);
	}

	constexpr const Vector2 operator/(const float other) const noexcept {
		return Vector2(x / other, y / other);
	}

	float x, y;
};




struct Vector3 {
	constexpr Vector3(
		const float x = 0.0f,
		const float y = 0.0f,
		const float z = 0.0f) noexcept :
		x(x), y(y), z(z) { }


	//converts 3d vector to 2d vector
	constexpr Vector2 to_vector2() const noexcept {
		return Vector2(x, y);
	}

	constexpr const Vector3 operator-(const Vector3& other) const noexcept {
		return Vector3(x - other.x, y - other.y, z - other.z);
	}

	constexpr const Vector3 operator+(const Vector3& other) const noexcept {
		return Vector3(x + other.x, y + other.y, z + other.z);
	}

	constexpr const Vector3 operator*(const float other) const noexcept {
		return Vector3(x * other, y * other, z * other);
	}

	constexpr const Vector3 operator/(const float other) const noexcept {
		return Vector3(x / other, y / other, z / other);
	}


	float x, y, z;
};