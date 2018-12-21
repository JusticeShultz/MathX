#include "Vector2.h"
#include "Matrix3.h"
#include "Matrix4.h"

namespace MathX
{
	//Vector2:
	Vector2::Vector2(void) : X(0), Y(0) { }
	Vector2::Vector2(float xValue, float yValue) : X(xValue), Y(yValue) { }
	Vector2::Vector2(const Vector2 & v) : X(v.X), Y(v.Y) { }
	Vector2::Vector2(const Vector2 * v) : X(v->X), Y(v->Y) { }
	Vector2::~Vector2(void) { }

	void Vector2::Print() const { std::cout << "(" << X << ", " << Y << ")"; }
	void Vector2::Set(float xValue, float yValue) { X = xValue; Y = yValue; }
	float Vector2::Magnitude() const { return sqrt(((X * X) + (Y * Y))); }
	float Vector2::Length() const { return sqrt(X * X + Y * Y); }
	float Vector2::LengthSquared() const { return X * X + Y * Y; }
	float Vector2::Distance(const Vector2 & v) const { return sqrt(((X - v.X) * (X - v.X)) + ((Y - v.Y) * (Y - v.Y))); }
	float Vector2::DistanceSquared(const Vector2 & v) const { return ((X - v.X) * (X - v.X)) + ((Y - v.Y) * (Y - v.Y)); }
	float Vector2::Dot(const Vector2 & v) const { return X * v.X + Y * v.Y; }
	float Vector2::Cross(const Vector2 & v) const { return X * v.Y + Y * v.X; }
	void Vector2::SetScale(const float scale) { X *= scale; Y *= scale; };
	Vector2 Vector2::GetScale(const float scale) { return Vector2(X * scale, Y * scale); };
	void Vector2::SetScale(const Vector2 scale) { X *= scale.X; Y *= scale.Y; };
	Vector2 Vector2::GetScale(const Vector2 scale) { return Vector2(X * scale.X, Y * scale.Y); };
	float Vector2::AngleBetweenDegrees(const Vector2 other)
	{
		return AngleBetweenRadians(other) *RAD2DEG;
	}
	float Vector2::AngleBetweenRadians(const Vector2 other)
	{
		Vector2 VectorCalculation = { X - other.X, Y - other.Y };
		float normal = sqrt(VectorCalculation.X * VectorCalculation.X + VectorCalculation.Y * VectorCalculation.Y);
		VectorCalculation.X = VectorCalculation.X / normal;
		VectorCalculation.Y = VectorCalculation.Y / normal;
		return atan2(VectorCalculation.Y, VectorCalculation.X);
	}
	Vector2 Vector2::PerpendicularClockwise() { return Vector2(Y, -X); }
	Vector2 Vector2::PerpendicularCounterClockwise() { return Vector2(-Y, X); }
	Vector2 & Vector2::Normal() { Set(-Y, X); return *this; }
	Vector2 & Vector2::Normalize()
	{
		float len = Length();

		if (len < FLOATMIN)
		{
			X = Y = 0.f;
			return *this;
		}
		else
		{
			float mult = 1 / len;
			X *= mult; Y *= mult;
			return *this;
		}
	}

	//Simple addition to a value operator.
	const Vector2 operator + (const Vector2 & rhs, const Matrix3& lhs) { return Vector2(rhs.X + lhs.m[0], rhs.Y + lhs.m[3]); }
	Vector2 operator+(const Matrix3 & lhs, const Vector2 & rhs) { return rhs + lhs; };
	//Simple subtraction to a value operator.
	const Vector2 operator - (const Vector2 & rhs, const Matrix3& lhs) { return Vector2(rhs.X - lhs.m[0], rhs.Y - lhs.m[3]); }
	Vector2 operator-(const Matrix3 & lhs, const Vector2 & rhs) { return rhs - lhs; };
	//Simple multiplication to a value operator.
	const Vector2 operator * (const Vector2 & rhs, const Matrix3& lhs) { return Vector2(rhs.X * lhs.m[0], rhs.Y * lhs.m[3]); }
	Vector2 operator*(const Matrix3 & lhs, const Vector2 & rhs) { return rhs * lhs; };
	//Simple division to a value operator.
	const Vector2 operator / (const Vector2 & rhs, const Matrix3& lhs) { return Vector2(rhs.X / lhs.m[0], rhs.Y / lhs.m[3]); }
	Vector2 operator/(const Matrix3 & lhs, const Vector2 & rhs) { return rhs / lhs; };

	//Simple addition to a value operator.
	const Vector2 operator + (const Vector2 & rhs, const Matrix4& lhs) { return Vector2(rhs.X + lhs.m[0], rhs.Y + lhs.m[4]); }
	Vector2 operator + (const Matrix4& lhs, const Vector2 &rhs) { return rhs + lhs; };
	//Simple subtraction to a value operator.
	const Vector2 operator - (const Vector2 & rhs, const Matrix4& lhs) { return Vector2(rhs.X - lhs.m[0], rhs.Y - lhs.m[4]); }
	Vector2 operator - (const Matrix4& lhs, const Vector2 &rhs) { return rhs - lhs; };
	//Simple multiplication to a value operator.
	const Vector2 operator * (const Vector2 & rhs, const Matrix4& lhs) { return Vector2(rhs.X * lhs.m[0], rhs.Y * lhs.m[4]); }
	Vector2 operator * (const Matrix4& lhs, const Vector2 &rhs) { return rhs * lhs; };
	//Simple division to a value operator.
	const Vector2 operator / (const Vector2 & rhs, const Matrix4& lhs) { return Vector2(rhs.X / lhs.m[0], rhs.Y / lhs.m[4]); }
	Vector2 operator / (const Matrix4& lhs, const Vector2 &rhs) { return rhs / lhs; };
}