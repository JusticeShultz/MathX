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
	
	#pragma region Colors
	//Predefined light gray.
	#define Light_Gray Color{ 200, 200, 200, 255 }
	//Predefined gray.
	#define Gray Color{ 130, 130, 130, 255 }
	//Predefined dark gray.
	#define Dark_Gray Color{ 80, 80, 80, 255 }
	//Predefined yellow.
	#define Yellow Color{ 253, 249, 0, 255 } 
	//Predefined gold.
	#define Gold Color{ 255, 203, 0, 255 } 
	//Predefined orange.
	#define Orange Color{ 255, 161, 0, 255 } 
	//Predefined pink.
	#define Pink Color{ 255, 109, 194, 255 } 
	//Predefined red.
	#define Red Color{ 230, 41, 55, 255 } 
	//Predefined maroon.
	#define Maroon Color{ 190, 33, 55, 255 } 
	//Predefined green.
	#define Green Color{ 0, 228, 48, 255 } 
	//Predefined light green.
	#define Light_Green Color{ 0, 250, 35, 255 } 
	//Predefined dark green.
	#define Dark_Green Color{ 0, 117, 44, 255 } 
	//Predefined sky blue.
	#define Sky_Blue Color{ 102, 191, 255, 255 } 
	//Predefined blue.
	#define Blue Color{ 0, 121, 241, 255 } 
	//Predefined dark blue.
	#define Dark_Blue Color{ 0, 82, 172, 255 } 
	//Predefined purple.
	#define Purple Color{ 200, 122, 255, 255 } 
	//Predefined violet.
	#define Violet Color{ 135, 60, 190, 255 } 
	//Predefined dark purple.
	#define Dark_Purple Color{ 112, 31, 126, 255 } 
	//Predefined beige.
	#define Beige Color{ 211, 176, 131, 255 } 
	//Predefined brown.
	#define Brown Color{ 127, 106, 79, 255 } 
	//Predefined dark brown.
	#define Dark_Brown Color{ 76, 63, 47, 255 } 
	//Predefined white.
	#define White Color{ 255, 255, 255, 255 } 
	//Predefined black.
	#define Black Color{ 0, 0, 0, 255 } 
	//Predefined blank color.
	#define Blank Color{ 0, 0, 0, 0 } 
	//Predefined empty color.
	#define Empty_Color Color{ 0, 0, 0, 0 } 
	//Predefined magenta.
	#define Magenta Color{ 255, 0, 255, 255 } 
	//Predefined webpage white.
	#define Webpage_White Color{ 245, 245, 245, 255 }
	#pragma endregion Predefined Colors.
}