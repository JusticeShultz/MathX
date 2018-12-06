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

	//Matrices: (INCOMPLETE)
	Matrix::Matrix(int var_m, int var_n) {
		m = var_m;
		n = var_n;
		array = new int*[n];
		for (int i = 0; i < n; i++)
			array[i] = new int[m];
	}
	Matrix* Matrix::add(Matrix* m1, Matrix* m2) 
	{

		if (m1->m != m2->m or m1->n != m2->n)
			throw;

		Matrix* result = new Matrix(m1->m, m1->n);

		for (int i = 0; i < result->m; i++)
			for (int j = 0; j < result->n; j++) result->array[i][j] = m1->array[i][j] + m2->array[i][j];

		return result;
	}
	int Matrix::get(int i, int j) { return array[i][j]; }
	void Matrix::set(int i, int j, int e)  { array[i][j] = e; }
	Matrix::~Matrix() 
	{
		for (int row = 0; row < n; row++)
			delete[] array[row];
		delete[] array;
	}
}