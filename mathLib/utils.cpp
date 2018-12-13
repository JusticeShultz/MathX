#include "utils.h"

namespace MathX
{
	//Returns the smaller of the two values.
	int min(int a, int b) { return a < b ? a : b; }
	//Returns the larger of the two values.
	int max(int a, int b) { return a > b ? a : b; }
	//Returns if the values are equal.
	bool equal(int a, int b) { return a == b; }
	//Returns a value no smaller than min and no larger than max.
	int clamp(int value, int min, int max)
	{
		if (value > max) value = max;
		if (value < min) value = min;
		return value;
	}
	//Returns the absolute value of val.
	int absVal(int val) { if (val < 0) val *= -1; return val; }
	//Returns base to the power of exp (i.e. basepower).
	bool isPowerOfTwo(int val) { return (val & (val - 1)) == 0; }
	//Returns the next power of two after the given value.
	int nextPowerOfTwo(int val) { if ((val & (val - 1)) == 0) ++val; return val; }
	//Moves the current value towards the target value. The maximum change should not exceed maxDelta. Might as well be named lerp.
	float moveTowards(float current, float target, float maxDelta)
	{
		if (current < target && current + maxDelta < target) current += maxDelta;
		if (current > target && current - maxDelta > target) current -= maxDelta;
		return current;
	}
	//Return the given value to the power of the input power.
	float power(float val, int power) { for (int i = 1; i < power; ++i) val *= val; return val; }
	double sqrt(double number)
	{
		if (number == 0) return (double)0.000000;

		double error = 0.00001;
		double s = number;

		while ((s - number / s) > error)
		{
			s = (s + number / s) / 2;
		}
		return s;
	}

	//Vector2:
	Vector2::Vector2(void) : X(0), Y(0) { }
	Vector2::Vector2(float xValue, float yValue) : X(xValue), Y(yValue) { }
	Vector2::Vector2(const Vector2 & v) : X(v.X), Y(v.Y) { }
	Vector2::Vector2(const Vector2 * v) : X(v->X), Y(v->Y) { }
	Vector2::~Vector2(void) { }
	void Vector2::Set(float xValue, float yValue) { X = xValue; Y = yValue; }
	float Vector2::Magnitude() const { return sqrt(((X * X) + (Y * Y))); }
	float Vector2::Length() const { return sqrt(X * X + Y * Y); }
	float Vector2::LengthSquared() const { return X * X + Y * Y; }
	float Vector2::Distance(const Vector2 & v) const { return sqrt(((X - v.X) * (X - v.X)) + ((Y - v.Y) * (Y - v.Y))); }
	float Vector2::DistanceSquared(const Vector2 & v) const { return ((X - v.X) * (X - v.X)) + ((Y - v.Y) * (Y - v.Y)); }
	float Vector2::Dot(const Vector2 & v) const { return X * v.X + Y * v.Y; }
	float Vector2::Cross(const Vector2 & v) const { return X * v.Y + Y * v.X; }
	Vector2 & Vector2::Normal() { Set(-Y, X); return *this; }
	Vector2 & Vector2::Normalize()
	{
		if (Length() != 0)
		{
			float length = LengthSquared();
			X /= length;
			Y /= length;
			return *this;
		}

		X = Y = 0;
		return *this;
	}

	//Vector 3:
	Vector3::Vector3(void) : X(0), Y(0), Z(0) { }
	Vector3::Vector3(float xValue, float yValue, float zValue) : X(xValue), Y(yValue), Z(zValue) { }
	Vector3::Vector3(const Vector3 & v) : X(v.X), Y(v.Y), Z(v.Z) { }
	Vector3::Vector3(const Vector3 * v) : X(v->X), Y(v->Y), Z(v->Z) { }
	Vector3::~Vector3(void) { }
	void Vector3::Set(float xValue, float yValue, float zValue) { X = xValue; Y = yValue; Z = zValue; }
	float Vector3::Magnitude() const { return sqrt(((X * X) + (Y * Y) + (Z * Z))); }
	float Vector3::Length() const { return sqrt(X * X + Y * Y + Z * Z); }
	float Vector3::LengthSquared() const { return X * X + Y * Y + Z * Z; }
	float Vector3::Distance(const Vector3 & v) const { return sqrt(((X - v.X) * (X - v.X)) + ((Y - v.Y) * (Y - v.Y)) + ((Z - v.Z) * (Z - v.Z))); }
	float Vector3::DistanceSquared(const Vector3 & v) const { return ((X - v.X) * (X - v.X)) + ((Y - v.Y) * (Y - v.Y)) + ((Z - v.Z) * (Z - v.Z)); }
	float Vector3::Dot(const Vector3 & v) const { return X * v.X + Y * v.Y + Z * v.Z; }
	float Vector3::Cross(const Vector3 & v) const { return X * v.Y + Y * v.X + Z * v.X; }
	Vector3 & Vector3::Normal() { Set(-Y, X, Z); return *this; }
	Vector3 & Vector3::Normalize()
	{
		if (Length() != 0)
		{
			float length = LengthSquared();
			X /= length;
			Y /= length;
			Z /= length;
			return *this;
		}

		X = Y = Z = 0;
		return *this;
	}

	//Vector 4:
	Vector4::Vector4(void) : X(0), Y(0), Z(0), W(0) { }
	Vector4::Vector4(float xValue, float yValue, float zValue, float wValue) : X(xValue), Y(yValue), Z(zValue), W(wValue) { }
	Vector4::Vector4(const Vector4 & v) : X(v.X), Y(v.Y), Z(v.Z), W(v.W) { }
	Vector4::Vector4(const Vector4 * v) : X(v->X), Y(v->Y), Z(v->Z), W(v->W) { }
	Vector4::~Vector4(void) { }
	void Vector4::Set(float xValue, float yValue, float zValue, float wValue) { X = xValue; Y = yValue; Z = zValue; W = wValue; }
	float Vector4::Magnitude() const { return sqrt(((X * X) + (Y * Y) + (Z * Z) + (W * W))); }
	float Vector4::Length() const { return sqrt(X * X + Y * Y + Z * Z + W * W); }
	float Vector4::LengthSquared() const { return X * X + Y * Y + Z * Z + W * W; }
	float Vector4::Distance(const Vector4 & v) const { return sqrt(((X - v.X) * (X - v.X)) + ((Y - v.Y) * (Y - v.Y)) + ((Z - v.Z) * (Z - v.Z)) + ((W - v.W) * (W - v.W))); }
	float Vector4::DistanceSquared(const Vector4 & v) const { return ((X - v.X) * (X - v.X)) + ((Y - v.Y) * (Y - v.Y)) + ((Z - v.Z) * (Z - v.Z)) + ((W - v.W) * (W - v.W)); }
	float Vector4::Dot(const Vector4 & v) const { return X * v.X + Y * v.Y + Z * v.Z + W * v.W; }
	float Vector4::Cross(const Vector4 & v) const { return X * v.Y + Y * v.X + Z * v.W + W * v.Z; }
	Vector4 & Vector4::Normal() { Set(-Y, X, Z, W); return *this; }
	Vector4 & Vector4::Normalize()
	{
		if (Length() != 0)
		{
			float length = LengthSquared();
			X /= length;
			Y /= length;
			Z /= length;
			W /= length;
			return *this;
		}

		X = Y = Z = W = 0;
		return *this;
	}

	//Empty constructor(All default to 0).
	Matrix2::Matrix2()
	{
		for (int i = 0; i < 4; ++i) Row[i] = 0;
	}
	//Single fill constructor.
	Matrix2::Matrix2(int a)
	{
		for (int i = 0; i < 4; ++i) Row[i] = a;
	}
	//2 row constructor.
	Matrix2::Matrix2(int a, int b)
	{
		Row[0] = a, Row[1] = a,
		Row[2] = b, Row[3] = b;
	}
	//4 integral constructor.
	Matrix2::Matrix2(int a, int b, int c, int d)
	{
		Row[0] = a, Row[1] = b,
		Row[2] = c, Row[3] = d;
	}
	//Common deconstructor.
	Matrix2::~Matrix2() { delete Row; }
	
	//Empty constructor(All default to 0).
	Matrix3::Matrix3()
	{
		for (int i = 0; i < 9; ++i) Row[i] = 0;
	}
	//Single fill constructor.
	Matrix3::Matrix3(int a)
	{
		for (int i = 0; i < 9; ++i) Row[i] = a;
	}
	//3 row constructor.
	Matrix3::Matrix3(int a, int b, int c)
	{
		Row[0] = a, Row[1] = a, Row[2] = a,
		Row[3] = b, Row[4] = b, Row[5] = b,
		Row[6] = c, Row[7] = c, Row[8] = c;
	}
	//9 integral constructor.
	Matrix3::Matrix3(int a, int b, int c, int d, int e, int f, int g, int h, int i)
	{
		Row[0] = a, Row[1] = b, Row[2] = c,
		Row[3] = d, Row[4] = e, Row[5] = f,
		Row[6] = g, Row[7] = h, Row[8] = i;
	}
	//Common deconstructor.
	Matrix3::~Matrix3() { delete Row; }

	//Empty constructor(All default to 0).
	Matrix4::Matrix4()
	{
		for (int i = 0; i < 16; ++i) Row[i] = 0;
	}
	//Single fill constructor.
	Matrix4::Matrix4(int a)
	{
		for (int i = 0; i < 16; ++i) Row[i] = a;
	}
	//4 row constructor.
	Matrix4::Matrix4(int a, int b, int c, int d)
	{
		Row[0] = a, Row[1] = b, Row[2] = c, Row[3] = d,
		Row[4] = a, Row[5] = b, Row[6] = c, Row[7] = d,
		Row[8] = a, Row[9] = b, Row[10] = c, Row[11] = d,
		Row[12] = a, Row[13] = b, Row[14] = c, Row[15] = d;
	}
	//16 integral constructor.
	Matrix4::Matrix4(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n, int o, int p)
	{
		Row[0] = a, Row[1] = b, Row[2] = c, Row[3] = d,
		Row[4] = e, Row[5] = f, Row[6] = g, Row[7] = h,
		Row[8] = i, Row[9] = j, Row[10] = k, Row[11] = l,
		Row[12] = m, Row[13] = n, Row[14] = o, Row[15] = p;
	}
	//Common deconstructor.
	Matrix4::~Matrix4() { delete Row; }

	Color::Color() { r = 0, g = 0, b = 0, a = 0; }
	Color::Color(char v1) { r = v1, g = v1, b = v1, a = v1; }
	Color::Color(char v1, char v2, char v3, char v4) { r = v1, g = v2, b = v3, a = v4; }
	Color::~Color() { }
}