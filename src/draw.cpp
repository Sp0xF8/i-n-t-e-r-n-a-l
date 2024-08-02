#include <draw.h>
Colour FromFloatToColour(float colour[4])
 {
	return Colour(colour[0], colour[1], colour[2], colour[3]);
 }



void Draw::Line(Vector2 start, Vector2 end, Colour colour, float thickness) {
	

	ImGui::GetBackgroundDrawList()->AddLine(ImVec2(start.x, start.y), ImVec2(end.x, end.y), colour.to_imu32(), thickness);
}


void Draw::Text(Vector2 position, const char* text, Colour colour, bool center) {
	ImGui::GetBackgroundDrawList()->AddText(ImVec2(position.x, position.y), colour.to_imu32(), text);
}


void Draw::Rect(Vector2 position, Vector2 position2, Colour colour, float thickness) {
	ImGui::GetBackgroundDrawList()->AddRect(ImVec2(position.x, position.y), ImVec2(position2.x, position2.y), colour.to_imu32(), 0.0f, 0, thickness);
}

void Draw::RectFilled(Vector2 position, Vector2 position2, Colour colour) {
	ImGui::GetBackgroundDrawList()->AddRectFilled(ImVec2(position.x, position.y), ImVec2(position2.x, position2.y), colour.to_imu32());
}

void Draw::Circle(Vector2 position, float radius, Colour colour, float thickness, int segments) {
	ImGui::GetBackgroundDrawList()->AddCircle(ImVec2(position.x, position.y), radius, colour.to_imu32(), segments, thickness);
}