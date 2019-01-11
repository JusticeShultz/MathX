#include "Vector3.h"

#include "Matrix3.h"
#include "Matrix4.h"

namespace MathX
{
	//Vector 3:
	Vector3::Vector3(void) : X(0), Y(0), Z(0) { }
	Vector3::Vector3(float xValue, float yValue, float zValue) : X(xValue), Y(yValue), Z(zValue) { }
	Vector3::Vector3(const Vector3 & v) : X(v.X), Y(v.Y), Z(v.Z) { }
	Vector3::Vector3(const Vector3 * v) : X(v->X), Y(v->Y), Z(v->Z) { }
	Vector3::~Vector3(void) { }

	void Vector3::Print() const { std::cout << "(" << X << ", " << Y << ", " << Z << ")"; }
	void Vector3::Set(float xValue, float yValue, float zValue) { X = xValue; Y = yValue; Z = zValue; }
	float Vector3::Magnitude() const { return sqrt(((X * X) + (Y * Y) + (Z * Z))); }
	float Vector3::Length() const { return sqrt(X * X + Y * Y + Z * Z); }
	float Vector3::LengthSquared() const { return X * X + Y * Y + Z * Z; }
	float Vector3::Distance(const Vector3 & v) const { return sqrt(((X - v.X) * (X - v.X)) + ((Y - v.Y) * (Y - v.Y)) + ((Z - v.Z) * (Z - v.Z))); }
	float Vector3::DistanceSquared(const Vector3 & v) const { return ((X - v.X) * (X - v.X)) + ((Y - v.Y) * (Y - v.Y)) + ((Z - v.Z) * (Z - v.Z)); }
	float Vector3::Dot(const Vector3 & v) const { return X * v.X + Y * v.Y + Z * v.Z; }
	Vector3 Vector3::Cross(const Vector3 & right) const
	{
		Vector3 returnValue;
		returnValue.X = Y * right.Z - Z * right.Y;
		returnValue.Y = Z * right.X - X * right.Z;
		returnValue.Z = X * right.Y - Y * right.X;

		return returnValue;
	}
	void Vector3::SetScale(const float scale) { X *= scale; Y *= scale; Z *= scale; };
	Vector3 Vector3::GetScale(const float scale) { return Vector3(X * scale, Y * scale, Z * scale); };
	void Vector3::SetScale(const Vector3 scale) { X *= scale.X; Y *= scale.Y; Z *= scale.Z; };
	Vector3 Vector3::GetScale(const Vector3 scale) { return Vector3(X * scale.X, Y * scale.Y, Z * scale.Z); };
	Vector3 & Vector3::Normal() 
	{
		Vector3 temp = (*this);
		float fMagnitude = Magnitude();
		temp /= fMagnitude;
		return temp;
	}
	Vector3 & Vector3::Normalize()
	{
		float len = Length();

		if (len < FLOATMIN)
		{
			X = Y = Z = 0.f;
			return *this;
		}
		else
		{
			float mult = 1 / len;
			X *= mult; Y *= mult; Z *= mult;
			return *this;
		}
	}

	//Simple addition to a value operator.
	const Vector3 operator + (const Vector3& lhs, const Matrix3 &rhs) { return Vector3(lhs.X + rhs.m[0], lhs.Y + rhs.m[3], lhs.Z + rhs.m[6]); }
	Vector3 operator + (const Matrix3& lhs, const Vector3 &rhs) { return rhs + lhs; };
	//Simple subtraction to a value operator.
	const Vector3 operator - (const Vector3& lhs, const Matrix3 &rhs) { return Vector3(lhs.X - rhs.m[0], lhs.Y - rhs.m[3], lhs.Z - rhs.m[6]); }
	Vector3 operator - (const Matrix3& lhs, const Vector3 &rhs) { return rhs - lhs; };
	//Simple multiplication to a value operator.
	const Vector3 operator * (const Vector3& lhs, const Matrix3 &rhs) { return Vector3(lhs.X * rhs.m[0], lhs.Y * rhs.m[3], lhs.Z * rhs.m[6]); }
	Vector3 operator * (const Matrix3& lhs, const Vector3 &rhs) { return rhs * lhs; };
	//Simple division to a value operator.
	const Vector3 operator / (const Vector3& lhs, const Matrix3 &rhs) { return Vector3(lhs.X / rhs.m[0], lhs.Y / rhs.m[3], lhs.Z / rhs.m[6]); }
	Vector3 operator / (const Matrix3& lhs, const Vector3 &rhs) { return rhs / lhs; };

	//Simple addition to a value operator.
	const Vector3 operator + (const Vector3& lhs, const Matrix4 &rhs) { return Vector3(lhs.X + rhs.m[0], lhs.Y + rhs.m[4], lhs.Z + rhs.m[8]); }
	Vector3 operator + (const Matrix4& lhs, const Vector3 &rhs) { return rhs + lhs; };
	//Simple subtraction to a value operator.
	const Vector3 operator - (const Vector3& lhs, const Matrix4 &rhs) { return Vector3(lhs.X - rhs.m[0], lhs.Y - rhs.m[4], lhs.Z - rhs.m[8]); }
	Vector3 operator - (const Matrix4& lhs, const Vector3 &rhs) { return rhs - lhs; };
	//Simple multiplication to a value operator.
	const Vector3 operator * (const Vector3& lhs, const Matrix4 &rhs) { return Vector3(lhs.X * rhs.m[0], lhs.Y * rhs.m[4], lhs.Z * rhs.m[8]); }
	Vector3 operator * (const Matrix4& lhs, const Vector3 &rhs) { return rhs * lhs; };
	//Simple division to a value operator.
	const Vector3 operator / (const Vector3& lhs, const Matrix4 &rhs) { return Vector3(lhs.X / rhs.m[0], lhs.Y / rhs.m[4], lhs.Z / rhs.m[8]); }
	Vector3 operator / (const Matrix4& lhs, const Vector3 &rhs) { return rhs / lhs; };

	const Vector3 Vector3::operator = (const Matrix3& rhs) { return Vector3(rhs.m[0], rhs.m[3], rhs.m[6]); }
	const Vector3 Vector3::operator = (const Matrix4& rhs) { return Vector3(rhs.m[0], rhs.m[4], rhs.m[8]); }

	std::ostream & operator << (std::ostream& stream, const Vector3& vec3) { vec3.Print(); return stream; }
}