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
}