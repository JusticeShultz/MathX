#include "Color.h"

namespace MathX
{
	#pragma region Color
	//Color constructors:

	Color::Color() { R = 0, G = 0, B = 0, A = 0; }
	Color::Color(int v1) { R = v1, G = v1, B = v1, A = v1; }
	Color::Color(int v1, int v2, int v3, int v4) { R = v1, G = v2, B = v3, A = v4; }
	Color::~Color() { }
	#pragma endregion Definitions for color.
	#pragma endregion Predefined Colors.
}