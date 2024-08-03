#pragma once


#include <vectors.h>
#include <imgui.h>




struct Colour {
	float r, g, b, a;

	constexpr Colour(
		const float r = 0.0f,
		const float g = 0.0f,
		const float b = 0.0f,
		const float a = 0.0f) noexcept :
		r(r), g(g), b(b), a(a) { }


	Colour from_float(const float r, const float g, const float b, const float a) const noexcept {
		return Colour(r, g, b, a);
	}

	
	ImU32 to_imu32() const noexcept {
		return IM_COL32(static_cast<int>(r * 255), static_cast<int>(g * 255), static_cast<int>(b * 255), static_cast<int>(a * 255));
	}

};

Colour FromFloatToColour(float colour[4]);


namespace Draw {

	void Line(Vector2 start, Vector2 end, Colour colour, float thickness = 1.0f);

	void Rect(Vector2 position, Vector2 position2, Colour colour, float thickness = 1.0f);
	void RectFilled(Vector2 position, Vector2 position2, Colour colour);

	void Circle(Vector2 position, float radius, Colour colour, float thickness = 1.0f, int segments = 32);

	void Text(Vector2 position, const char* text, Colour colour, bool center = false);
}
