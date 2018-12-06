#pragma once

namespace MathX
{
	/*#ifdef _utils_h_
	#define _utils_h_
	#endif
	*/
	//Defined as PI or π.
	#define PI 3.14159265358979323846
	//Multiply this with a angle measure expressed in degrees to get its equivalent in radians.
	#define DEG2RAD (PI/180.0f)
	//Multiply this with a angle measure expressed in radians to get its equivalent in degrees.
	#define RAD2DEG (180.0f/PI)
	//Returns the smaller of the two values.
	int min(int a, int b);
	//Returns the larger of the two values.
	int max(int a, int b);
	//Returns if the values are equal.
	bool equal(int a, int b);
	//Returns a value no smaller than min and no larger than max.
	int clamp(int value, int min, int max);
	//Returns the absolute value of val.
	int absVal(int val);
	//Returns base to the power of exp (i.e. basepower).
	bool isPowerOfTwo(int val);
	//Returns the next power of two after the given value.
	int nextPowerOfTwo(int val);
	//Moves the current value towards the target value. The maximum change should not exceed maxDelta.
	float moveTowards(float current, float target, float maxDelta);
	//Return the given value to the power of the input power.
	float power(float val, int power);
	typedef struct Vector2
	{
	public:
		float X;
		float Y;

		void Zero() { X = 0, Y = 0; };
		void One() { X = 1, Y = 1; };
		void Five() { X = 5, Y = 5; };
		void Fifty() { X = 50, Y = 50; };
	private:
		Vector2 & operator+=(const Vector2 &rhs) { Vector2 z = Vector2{ (float)(rhs.X + X), (float)(rhs.Y + Y) }; return z; };
		Vector2& operator-=(const Vector2 &rhs) { Vector2 z = Vector2{ (float)(rhs.X - X), (float)(rhs.Y - Y) }; return z; };
		Vector2& operator*=(const Vector2 &rhs) { Vector2 z = Vector2{ (float)(rhs.X * X), (float)(rhs.Y * Y) }; return z; };
		Vector2& operator/=(const Vector2 &rhs) { Vector2 z = Vector2{ (float)(rhs.X / X), (float)(rhs.Y / Y) }; return z; };

		Vector2& operator+(const Vector2 &rhs) { Vector2 z = Vector2{ (float)(rhs.X + X), (float)(rhs.Y + Y) }; return z; };
		Vector2& operator-(const Vector2 &rhs) { Vector2 z = Vector2{ (float)(rhs.X - X), (float)(rhs.Y - Y) }; return z; };
		Vector2& operator*(const Vector2 &rhs) { Vector2 z = Vector2{ (float)(rhs.X * X), (float)(rhs.Y * Y) }; return z; };
		Vector2& operator/(const Vector2 &rhs) { Vector2 z = Vector2{ (float)(rhs.X / X), (float)(rhs.Y / Y) }; return z; };

		Vector2& operator=(Vector2 &rhs) { Vector2 z = Vector2{ rhs.X = X, rhs.Y = Y }; return z; };

		bool operator==(const Vector2 &rhs) { if ((float)rhs.X == X && (float)rhs.Y == Y) { return true; } return false; };
	};
	typedef struct Vector3
	{
		float X;
		float Y;
		float Z;

		void Zero() { X = 0, Y = 0, Z = 0; };
		void One() { X = 1, Y = 1, Z = 1; };
		void Five() { X = 5, Y = 5, Z = 5; };
		void Fifty() { X = 50, Y = 50, Z = 50; };

		//These don't work yet.
		Vector3& operator+=(const Vector3 q) { Vector3 z = Vector3{ q.X + X, q.Y + Y, q.Z + Z }; return z; };
		Vector3& operator-=(const Vector3 q) { Vector3 z = Vector3{ q.X - X, q.Y - Y, q.Z - Z }; return z; };
		Vector3& operator*=(const Vector3 q) { Vector3 z = Vector3{ q.X * X, q.Y * Y, q.Z * Z }; return z; };
		Vector3& operator/=(const Vector3 q) { Vector3 z = Vector3{ q.X / X, q.Y / Y, q.Z / Z }; return z; };

		Vector3& operator+(const Vector3 q) { Vector3 z = Vector3{ q.X + X, q.Y + Y, q.Z + Z }; return z; };
		Vector3& operator-(const Vector3 q) { Vector3 z = Vector3{ q.X - X, q.Y - Y, q.Z - Z }; return z; };
		Vector3& operator*(const Vector3 q) { Vector3 z = Vector3{ q.X * X, q.Y * Y, q.Z * Z }; return z; };
		Vector3& operator/(const Vector3 q) { Vector3 z = Vector3{ q.X / X, q.Y / Y, q.Z / Z }; return z; };

		Vector3& operator=(Vector3 q) { Vector3 z = Vector3{ q.X = X, q.Y = Y, q.Z = Z }; return z; };
	};
	typedef struct Quaternion
	{
		float X;
		float Y;
		float Z;
		float W;

		void Zero() { X = 0, Y = 0, Z = 0; W = 0; };

		//Currently not working, need `a` type math functions.
		Vector3 QuaternionToEuler(Quaternion q)
		{
			Vector3 result = { 0 };
			float x0 = 2.0f*(q.W*q.X + q.Y*q.Z);
			float x1 = 1.0f - 2.0f*(q.X*q.X + q.Y*q.Y);
			//result.X = atan2f(x0, x1)*RAD2DEG;
			float y0 = 2.0f*(q.W*q.Y - q.Z*q.X);
			y0 = y0 > 1.0f ? 1.0f : y0;
			y0 = y0 < -1.0f ? -1.0f : y0;
			//result.Y = asinf(y0)*RAD2DEG;
			float z0 = 2.0f*(q.W*q.Z + q.X*q.Y);
			float z1 = 1.0f - 2.0f*(q.Y*q.Y + q.Z*q.Z);
			//result.Z = atan2f(z0, z1)*RAD2DEG;

			return result;
		}
	};
	typedef struct Matrix
	{
		float m0, m4, m8, m12;
		float m1, m5, m9, m13;
		float m2, m6, m10, m14;
		float m3, m7, m11, m15;
	};
}