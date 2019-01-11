#include "Vector4.h"

#include "Vector3.h"
#include "Matrix3.h"
#include "Matrix4.h"

namespace MathX
{
	//Vector 4:
	Vector4::Vector4(void) : X(0), Y(0), Z(0), W(0) { }
	Vector4::Vector4(float xValue, float yValue, float zValue, float wValue) : X(xValue), Y(yValue), Z(zValue), W(wValue) { }
	Vector4::Vector4(const Vector4 & v) : X(v.X), Y(v.Y), Z(v.Z), W(v.W) { }
	Vector4::Vector4(const Vector4 * v) : X(v->X), Y(v->Y), Z(v->Z), W(v->W) { }
	Vector4::~Vector4(void) { }

	void Vector4::Print() const { std::cout << "(" << X << ", " << Y << ", " << Z << ", " << W << ")"; }
	void Vector4::Set(float xValue, float yValue, float zValue, float wValue) { X = xValue; Y = yValue; Z = zValue; W = wValue; }
	float Vector4::Magnitude() const { return sqrt(((X * X) + (Y * Y) + (Z * Z) + (W * W))); }
	float Vector4::Length() const { return sqrt(X * X + Y * Y + Z * Z + W * W); }
	float Vector4::LengthSquared() const { return X * X + Y * Y + Z * Z + W * W; }
	float Vector4::Distance(const Vector4 & v) const { return sqrt(((X - v.X) * (X - v.X)) + ((Y - v.Y) * (Y - v.Y)) + ((Z - v.Z) * (Z - v.Z)) + ((W - v.W) * (W - v.W))); }
	float Vector4::DistanceSquared(const Vector4 & v) const { return ((X - v.X) * (X - v.X)) + ((Y - v.Y) * (Y - v.Y)) + ((Z - v.Z) * (Z - v.Z)) + ((W - v.W) * (W - v.W)); }
	float Vector4::Dot(const Vector4 & v) const { return X * v.X + Y * v.Y + Z * v.Z + W * v.W; }
	Vector4 Vector4::Cross(const Vector4 & v) const
	{
		Vector3 temp1(X, Y, Z);
		Vector3 temp2(v.X, v.Y, v.Z);
		temp1 = temp1.Cross(temp2);
		return Vector4(temp1.X, temp1.Y, temp1.Z, 0);
	}
	void Vector4::SetScale(const float scale) { X *= scale; Y *= scale; Z *= scale; W *= scale; };
	Vector4 Vector4::GetScale(const float scale) { return Vector4(X * scale, Y * scale, Z * scale, W * scale); };
	void Vector4::SetScale(const Vector4 scale) { X *= scale.X; Y *= scale.Y; Z *= scale.Z; W *= scale.W; };
	Vector4 Vector4::GetScale(const Vector4 scale) { return Vector4(X * scale.X, Y * scale.Y, Z * scale.Z, W * scale.W); };
	Vector4 & Vector4::Normal() 
	{
		Vector4 temp = (*this);
		Vector4 Empty = Vector4(0, 0, 0, 0);
		if (Magnitude() == 0.0f) return Empty;
		temp /= Magnitude();
		return temp;
	}
	Vector4 & Vector4::Normalize()
	{
		float len = Length();

		if (len < FLOATMIN)
		{
			X = Y = Z = W = 0.f;
			return *this;
		}
		else
		{
			float mult = 1 / len;
			X *= mult; Y *= mult; Z *= mult; W *= mult;
			return *this;
		}
	}

	//Simple addition to a value operator.
	const Vector4 operator + (const Vector4& lhs, const Matrix3 &rhs) { return Vector4(lhs.X + rhs.m[0], lhs.Y + rhs.m[3], lhs.Z + rhs.m[6], lhs.W); }
	Vector4 operator + (const Matrix3& lhs, const Vector4 &rhs) { return rhs + lhs; };
	//Simple subtraction to a value operator.
	const Vector4 operator - (const Vector4& lhs, const Matrix3 &rhs) { return Vector4(lhs.X - rhs.m[0], lhs.Y - rhs.m[3], lhs.Z - rhs.m[6], lhs.W); }
	Vector4 operator - (const Matrix3& lhs, const Vector4 &rhs) { return rhs - lhs; };
	//Simple multiplication to a value operator.
	const Vector4 operator * (const Vector4& lhs, const Matrix3 &rhs) { return Vector4(lhs.X * rhs.m[0], lhs.Y * rhs.m[3], lhs.Z * rhs.m[6], lhs.W); }
	Vector4 operator * (const Matrix3& lhs, const Vector4 &rhs) { return rhs * lhs; };
	//Simple division to a value operator.
	const Vector4 operator / (const Vector4& lhs, const Matrix3 &rhs) { return Vector4(lhs.X / rhs.m[0], lhs.Y / rhs.m[3], lhs.Z / rhs.m[6], lhs.W); }
	Vector4 operator / (const Matrix3& lhs, const Vector4 &rhs) { return rhs / lhs; };

	//Simple addition to a value operator.
	const Vector4 operator + (const Vector4& lhs, const Matrix4 &rhs) { return Vector4(lhs.X + rhs.m[0], lhs.Y + rhs.m[4], lhs.Z + rhs.m[8], lhs.W + rhs.m[12]); }
	Vector4 operator + (const Matrix4& lhs, const Vector4 &rhs) { return rhs + lhs; };
	//Simple subtraction to a value operator.
	const Vector4 operator - (const Vector4& lhs, const Matrix4 &rhs) { return Vector4(lhs.X - rhs.m[0], lhs.Y - rhs.m[4], lhs.Z - rhs.m[8], lhs.W - rhs.m[12]); }
	Vector4 operator - (const Matrix4& lhs, const Vector4 &rhs) { return rhs - lhs; };
	//Simple multiplication to a value operator.
	const Vector4 operator * (const Vector4& lhs, const Matrix4 &rhs) { return Vector4(lhs.X * rhs.m[0], lhs.Y * rhs.m[4], lhs.Z * rhs.m[8], lhs.W * rhs.m[12]); }
	Vector4 operator * (const Matrix4& lhs, const Vector4 &rhs) { return rhs * lhs; };
	//Simple division to a value operator.
	const Vector4 operator / (const Vector4& lhs, const Matrix4 &rhs) { return Vector4(lhs.X / rhs.m[0], lhs.Y / rhs.m[4], lhs.Z / rhs.m[8], lhs.W / rhs.m[12]); }
	Vector4 operator / (const Matrix4& lhs, const Vector4 &rhs) { return rhs / lhs; };

	std::ostream & operator << (std::ostream& stream, const Vector4& vec4) { vec4.Print(); return stream; }

	const Vector4 Vector4::operator = (const Matrix3& rhs) { return Vector4(rhs.m[0], rhs.m[3], rhs.m[6], 0); }
	const Vector4 Vector4::operator = (const Matrix4& rhs) { return Vector4(rhs.m[0], rhs.m[4], rhs.m[8], rhs.m[12]); }
}