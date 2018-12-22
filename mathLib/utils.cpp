#include "utils.h"

#pragma region MathX

namespace MathX
{

	#pragma region [DEPRECATED]
	///List of all deprecated functions - kept for possible future use or reference.
	///float Lerp(float start, float end, float amount) { return start + amount * (end - start); }
	///template <typename T> T Lerp(const T& a, const T& b, float t) { return a * (1 - t) + b * t; }
	///Matrix3::Matrix3(float q[9]) { for (int i = 0; i < 9; i++) m[i] = q[i]; }
	/*Vector4 Matrix3::Transform(const Vector4 &rhs)
	{
	Vector4 temp;
	temp.X = rhs.X * m[0] + rhs.Y * m[3] + rhs.Z * m[6];
	temp.Y = rhs.X * m[1] + rhs.Y * m[4] + rhs.Z * m[7];
	temp.Z = rhs.X * m[2] + rhs.Y * m[5] + rhs.Z * m[8];
	temp.W = rhs.W;
	return temp;
	}
	Vector3 Matrix3::Transform(const Vector3 &rhs)
	{
	Vector3 temp;
	temp.X = rhs.X * m[0] + rhs.Y * m[3] + rhs.Z * m[6];
	temp.Y = rhs.X * m[1] + rhs.Y * m[4] + rhs.Z * m[7];
	temp.Z = rhs.X * m[2] + rhs.Y * m[5] + rhs.Z * m[8];
	return temp;
	}*/
	#pragma endregion
}

#pragma endregion