#pragma once
#include "utils.h"


namespace MathX
{
	class Matrix3;
	class Matrix4;
	class Vector3
	{
	public:
		//Input value X.
		float X;
		//Input value Y.
		float Y;
		//Input value Z.
		float Z;

		//[SETTER] Sets the values to 0. (Use the constructor input for a init value)
		void Zero() { X = 0, Y = 0; Z = 0; };
		//[SETTER] Sets the values to 1. (Use the constructor input for a init value)
		void One() { X = 1, Y = 1; Z = 1; };
		//[SETTER] Sets the values to 5. (Use the constructor input for a init value)
		void Five() { X = 5, Y = 5; Z = 5; };
		//[SETTER] Sets the values to 50. (Use the constructor input for a init value)
		void Fifty() { X = 50, Y = 50; Z = 50; };

		//[SETTER] Default constructor.
		Vector3(void);
		//[SETTER] Data input constructor.
		Vector3(float xValue, float yValue, float zValue);
		//[SETTER] Additional constructor type.
		Vector3(const Vector3 & v);
		//[SETTER] Additional constructor type.
		Vector3(const Vector3 * v);
		//[SETTER] Deconstructor
		~Vector3(void);

		//[DISPLAYER] Prints to the console the values contained in this vector type.
		void Print() const;
		//[SETTER] Setter function.
		void Set(float xValue, float yValue, float zValue);
		//[GETTER] Get the length of the vector.
		float Length() const;
		//[GETTER] Get the length squared of the vector.
		float LengthSquared() const;
		//[GETTER] Get the Magnitude of the vector
		float Magnitude() const;
		//[GETTER] Get the distance of the vector.
		float Distance(const Vector3 & v) const;
		//[GETTER] Get the distance squared of the vector.
		float DistanceSquared(const Vector3 & v) const;
		//[GETTER] Get the Dot product of the vector.
		float Dot(const Vector3 & v) const;
		//[GETTER] Get the Cross product of the vector.
		Vector3 Cross(const Vector3 & v) const;
		//[SETTER] Set the vector to be scaled by a given float value.
		void SetScale(const float scale);
		//[GETTER] Get the scaled version of the vector by a float value given.
		Vector3 GetScale(const float scale);
		//[SETTER] Set the vector to be scaled by a given float value. [Vector3]
		void SetScale(const Vector3 scale);
		//[GETTER] Get the scaled version of the vector by a float value given. [Vector3]
		Vector3 GetScale(const Vector3 scale);
		//[GETTER] Get the normal of the vector.
		Vector3 & Normal();
		//[SETTER] Normalize the vector.
		Vector3 & Normalize();

		#pragma region Operators
		//Vector3 operators:

		//Setter Vector3 input.
		Vector3 & operator = (const Vector3 & v) { X = v.X; Y = v.Y; Z = v.Z; return *this; };
		//Setter 1 value input.
		Vector3 & operator = (const float & f) { X = f; Y = f; Z = f; return *this; };
		//Negative operation.
		Vector3 & operator - (void) { X = -X; Y = -Y; Z = -Z; return *this; };

		//Checker equals operation.
		bool operator == (const Vector3 & v) const
		{
			bool x = false, y = false, z = false;

			//Check X.

			Vector3 temp1 = v;
			Vector3 temp2 = Vector3(X, Y, Z);

			//Calculates the difference.
			float diff1 = fabs(v.X - X);
			temp1.X = fabs(temp1.X);
			temp2.X = fabs(X);

			//Finds the largest of the 2 values.
			float largest1 = (temp2.X > temp1.X) ? temp2.X : temp1.X;

			if (diff1 <= largest1 * FLOATMIN)
				x = true;
			else x = false;

			//Check Y.

			//Calculates the difference.
			float diff2 = fabs(v.Y - Y);
			temp1.Y = fabs(temp1.Y);
			temp2.Y = fabs(Y);

			//Finds the largest of the 2 values.
			float largest2 = (temp2.Y > temp1.Y) ? temp2.Y : temp1.Y;

			if (diff2 <= largest2 * FLOATMIN)
				y = true;
			else y = false;

			//Check Z.

			//Calculates the difference.
			float diff3 = fabs(v.Z - Z);
			temp1.Z = fabs(temp1.Z);
			temp2.Z = fabs(Z);

			//Finds the largest of the 2 values.
			float largest3 = (temp2.Z > temp1.Z) ? temp2.Z : temp1.Z;

			if (diff3 <= largest3 * FLOATMIN)
				z = true;
			else z = false;

			return x && y && z;
		};

		//Checker does not equal operation.
		bool operator != (const Vector3 & v) const { return (X != v.X) || (Y != v.Y) || (Z != v.Z); };

		//Simple addition operation.
		const Vector3 operator + (const Vector3 & v) const { Vector3 q; q.X = X + v.X; q.Y = Y + v.Y; q.Z = Z + v.Z; return q; };
		//Simple subtraction operation.
		const Vector3 operator - (const Vector3 & v) const { Vector3 q; q.X = X - v.X; q.Y = Y - v.Y; q.Z = Z - v.Z; return q; };
		//Simple multiplication operation.
		const Vector3 operator * (const Vector3 & v) const { Vector3 q; q.X = X * v.X; q.Y = Y * v.Y; q.Z = Z * v.Z; return q; };
		//Simple division operation.
		const Vector3 operator / (const Vector3 & v) const { Vector3 q; q.X = X / v.X; q.Y = Y / v.Y; q.Z = Z / v.Z; return q; };

		//Simple addition operation - simple.
		Vector3 & operator += (const Vector3 & v) { X += v.X; Y += v.Y; Z += v.Z; return *this; };
		//Simple subtraction operation - simple.
		Vector3 & operator -= (const Vector3 & v) { X -= v.X; Y -= v.Y; Z -= v.Z; return *this; };
		//Simple multiplication operation - simple.
		Vector3 & operator *= (const Vector3 & v) { X *= v.X; Y *= v.Y; Z *= v.Z; return *this; };
		//Simple division operation - simple.
		Vector3 & operator /= (const Vector3 & v) { X /= v.X; Y /= v.Y; Z /= v.Z; return *this; };

		//Simple addition operation - simple one value input.
		Vector3 & operator += (float v) { X += v; Y += v; Z += v; return *this; };
		//Simple subtraction operation - simple one value input.
		Vector3 & operator -= (float v) { X -= v; Y -= v; Z -= v; return *this; };
		//Simple multiplication operation - simple one value input.
		Vector3 & operator *= (float v) { X *= v; Y *= v; Z *= v; return *this; };
		//Simple division operation - simple one value input.
		Vector3 & operator /= (float v) { X /= v; Y /= v; Z /= v; return *this; };

		//Simple addition to a value operator.
		const Vector3 operator + (float v) const { return Vector3(X + v, Y + v, Z + v); }
		friend Vector3 operator + (const float lhs, const Vector3 &rhs) { return rhs + lhs; };
		//Simple subtraction to a value operator.
		const Vector3 operator - (float v) const { return Vector3(X - v, Y - v, Z - v); }
		friend Vector3 operator - (const float lhs, const Vector3 &rhs) { return rhs - lhs; };
		//Simple multiplication to a value operator.
		const Vector3 operator * (float v) const { return Vector3(X * v, Y * v, Z * v); }
		friend Vector3 operator * (const float lhs, const Vector3 &rhs) { return rhs * lhs; };
		//Simple division to a value operator.
		const Vector3 operator / (float v) const { return Vector3(X / v, Y / v, Z / v); }
		friend Vector3 operator / (const float lhs, const Vector3 &rhs) { return rhs / lhs; };

		//Simple increment operator.
		Vector3 & operator ++ (int z) { ++X, ++Y, ++Z; return *this; };
		//Simple decrement operator.
		Vector3 & operator -- (int z) { --X, --Y, --Z; return *this; };

		const Vector3 operator = (const Matrix3& rhs);
		const Vector3 operator = (const Matrix4& rhs);

		#pragma endregion Vector3 operations.
	};

	std::ostream & operator << (std::ostream& stream, const Vector3& vec3);
}