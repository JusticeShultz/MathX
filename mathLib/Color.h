#pragma once
#include "utils.h"

namespace MathX
{
	class Color
	{
	public:
		int R;
		int G;
		int B;
		int A;

		Color();
		Color(int v1);
		Color(int v1, int v2, int v3, int v4);
		~Color();

		//Color operators:

		//Setter color input.
		Color & operator = (const Color & v) { R = v.R; G = v.G; B = v.B; A = v.A; return *this; };
		//Setter 1 value input.
		Color & operator = (const float & f) { R = f; G = f; B = f; A = f; return *this; };
		//Negative operation.
		Color & operator - (void) { R = -R; G = -G; B = -B; A = -A; return *this; };

		//Checker equals operation.
		bool operator == (const Color & v) const { return (R == v.R) && (G == v.G) && (B == v.B) && (A == v.A); };
		//Checker does not equal operation.
		bool operator != (const Color & v) const { return (R != v.R) || (G != v.G) || (B != v.B) || (A != v.A); };

		//Simple addition operation.
		const Color operator + (const Color & v) const { Color q; q.R = R + v.R; q.G = G + v.G; q.B = B + v.B; q.A = A + v.A; return q; };
		//Simple subtraction operation.
		const Color operator - (const Color & v) const { Color q; q.R = R - v.R; q.G = G - v.G; q.B = B - v.B; q.A = A - v.A; return q; };
		//Simple multiplication operation.
		const Color operator * (const Color & v) const { Color q; q.R = R * v.R; q.G = G * v.G; q.B = B * v.B; q.A = A * v.A; return q; };
		//Simple division operation.
		const Color operator / (const Color & v) const { Color q; q.R = R / v.R; q.G = G / v.G; q.B = B / v.B; q.A = A / v.A; return q; };

		//Simple addition operation - simple.
		Color & operator += (const Color & v) { R += v.R; G += v.G; B += v.B; A += v.A; return *this; };
		//Simple subtraction operation - simple.
		Color & operator -= (const Color & v) { R -= v.R; G -= v.G; B -= v.B; A -= v.A; return *this; };
		//Simple multiplication operation - simple.
		Color & operator *= (const Color & v) { R *= v.R; G *= v.G; B *= v.B; A *= v.A; return *this; };
		//Simple division operation - simple.
		Color & operator /= (const Color & v) { R /= v.R; G /= v.G; B /= v.B; A /= v.A; return *this; };

		//Simple addition operation - simple one value input.
		Color & operator += (float v) { R += v; G += v; B += v; A += v; return *this; };
		//Simple subtraction operation - simple one value input.
		Color & operator -= (float v) { R -= v; G -= v; B -= v; A -= v; return *this; };
		//Simple multiplication operation - simple one value input.
		Color & operator *= (float v) { R *= v; G *= v; B *= v; A *= v; return *this; };
		//Simple division operation - simple one value input.
		Color & operator /= (float v) { R /= v; G /= v; B /= v; A /= v; return *this; };

		//Simple addition to a value operator.
		const Color operator + (float v) const { return Color(R + v, G + v, B + v, A + v); }
		friend Color operator + (const float lhs, const Color &rhs) { return rhs + lhs; };
		//Simple subtraction to a value operator.
		const Color operator - (float v) const { return Color(R - v, G - v, B - v, A - v); }
		friend Color operator - (const float lhs, const Color &rhs) { return rhs - lhs; };
		//Simple multiplication to a value operator.
		const Color operator * (float v) const { return Color(R * v, G * v, B * v, A * v); }
		friend Color operator * (const float lhs, const Color &rhs) { return rhs * lhs; };
		//Simple division to a value operator.
		const Color operator / (float v) const { return Color(R / v, G / v, B / v, A / v); }
		friend Color operator / (const float lhs, const Color &rhs) { return rhs / lhs; };

		//Simple increment operator.
		Color & operator ++ (int z) { ++R, ++G, ++B, ++A; return *this; };
		//Simple decrement operator.
		Color & operator -- (int z) { --R, --G, --B, --A; return *this; };
	};

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
}