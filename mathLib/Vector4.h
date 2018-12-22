#pragma once
#include "utils.h"

namespace MathX
{
	class Matrix3;
	class Matrix4;
	class Vector4
	{
	public:
		//Input value X.
		float X;
		//Input value Y.
		float Y;
		//Input value Z.
		float Z;
		//Input value W.
		float W;

		//[SETTER] Sets the values to 0. (Use the constructor input for a init value)
		void Zero() { X = 0, Y = 0; Z = 0; W = 0; };
		//[SETTER] Sets the values to 1. (Use the constructor input for a init value)
		void One() { X = 1, Y = 1; Z = 1; W = 1; };
		//[SETTER] Sets the values to 5. (Use the constructor input for a init value)
		void Five() { X = 5, Y = 5; Z = 5; W = 5; };
		//[SETTER] Sets the values to 50. (Use the constructor input for a init value)
		void Fifty() { X = 50, Y = 50; Z = 50; W = 50; };

		//[SETTER] Empty default constructor.
		Vector4(void);
		//[SETTER] Data input constructor.
		Vector4(float xValue, float yValue, float zValue, float wValue);
		//[SETTER] Additional constructor type.
		Vector4(const Vector4 & v);
		//[SETTER] Additional constructor type.
		Vector4(const Vector4 * v);
		//[DECONSTRUCTOR]
		~Vector4(void);

		//[DISPLAYER] Prints to the console the values contained in this vector type.
		void Print() const;
		//[SETTER] Setter function.
		void Set(float xValue, float yValue, float zValue, float wValue);
		//[GETTER] Get the length of the vector.
		float Length() const;
		//[GETTER] Get the length squared of the vector.
		float LengthSquared() const;
		//[GETTER] Get the distance of the vector.
		float Distance(const Vector4 & v) const;
		//[GETTER] Get the distance squared of the vector.
		float DistanceSquared(const Vector4 & v) const;
		//[GETTER] Get the Magnitude of the vector
		float Magnitude() const;
		//[GETTER] Get the Dot product of the vector.
		float Dot(const Vector4 & v) const;
		//[GETTER] Get the Cross product of the vector.
		Vector4 Cross(const Vector4 & v) const;
		//[SETTER] Set the vector to be scaled by a given float value. [Float]
		void SetScale(const float scale);
		//[GETTER] Get the scaled version of the vector by a float value given. [Float]
		Vector4 GetScale(const float scale);
		//[SETTER] Set the vector to be scaled by a given float value. [Vector4]
		void SetScale(const Vector4 scale);
		//[GETTER] Get the scaled version of the vector by a float value given. [Vector4]
		Vector4 GetScale(const Vector4 scale);
		//[GETTER] Get the normal of the vector.
		Vector4 & Normal();
		//[SETTER] Normalize the vector.
		Vector4 & Normalize();

		#pragma region Operators
		//Vector4 operators:

		//Setter Vector4 input.
		Vector4 & operator = (const Vector4 & v) { X = v.X; Y = v.Y; Z = v.Z; W = v.W; return *this; };
		//Setter 1 value input.
		Vector4 & operator = (const float & f) { X = f; Y = f; Z = f; W = f; return *this; };
		//Negative operation.
		Vector4 & operator - (void) { X = -X; Y = -Y; Z = -Z; W = -W; return *this; };

		//Checker equals operation.
		bool operator == (const Vector4 & v) const
		{
			bool x = false, y = false, z = false, w = false;

			//Check X.

			Vector4 temp1 = v;
			Vector4 temp2 = Vector4(X, Y, Z, W);

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

			//Check W.

			//Calculates the difference.
			float diff4 = fabs(v.W - W);
			temp1.W = fabs(temp1.W);
			temp2.W = fabs(W);

			//Finds the largest of the 2 values.
			float largest4 = (temp2.W > temp1.W) ? temp2.W : temp1.W;

			if (diff4 <= largest4 * FLOATMIN)
				w = true;
			else w = false;

			return x && y && z && w;
		};

		//Checker does not equal operation.
		bool operator != (const Vector4 & v) const { return (X != v.X) || (Y != v.Y) || (Z != v.Z) || (W != v.W); };

		//Simple addition operation.
		const Vector4 operator + (const Vector4 & v) const { Vector4 q; q.X = X + v.X; q.Y = Y + v.Y; q.Z = Z + v.Z; q.W = W + v.W; return q; };
		//Simple subtraction operation.
		const Vector4 operator - (const Vector4 & v) const { Vector4 q; q.X = X - v.X; q.Y = Y - v.Y; q.Z = Z - v.Z; q.W = W - v.W; return q; };
		//Simple multiplication operation.
		const Vector4 operator * (const Vector4 & v) const { Vector4 q; q.X = X * v.X; q.Y = Y * v.Y; q.Z = Z * v.Z; q.W = W * v.W; return q; };
		//Simple division operation.
		const Vector4 operator / (const Vector4 & v) const { Vector4 q; q.X = X / v.X; q.Y = Y / v.Y; q.Z = Z / v.Z; q.W = W / v.W; return q; };

		//Simple addition operation - simple.
		Vector4 & operator += (const Vector4 & v) { X += v.X; Y += v.Y; Z += v.Z; W += v.W; return *this; };
		//Simple subtraction operation - simple.
		Vector4 & operator -= (const Vector4 & v) { X -= v.X; Y -= v.Y; Z -= v.Z; W -= v.W; return *this; };
		//Simple multiplication operation - simple.
		Vector4 & operator *= (const Vector4 & v) { X *= v.X; Y *= v.Y; Z *= v.Z; W *= v.W; return *this; };
		//Simple division operation - simple.
		Vector4 & operator /= (const Vector4 & v) { X /= v.X; Y /= v.Y; Z /= v.Z; W /= v.W; return *this; };

		//Simple addition operation - simple one value input.
		Vector4 & operator += (float v) { X += v; Y += v; Z += v; W += v; return *this; };
		//Simple subtraction operation - simple one value input.
		Vector4 & operator -= (float v) { X -= v; Y -= v; Z -= v; W -= v; return *this; };
		//Simple multiplication operation - simple one value input.
		Vector4 & operator *= (float v) { X *= v; Y *= v; Z *= v; W *= v; return *this; };
		//Simple division operation - simple one value input.
		Vector4 & operator /= (float v) { X /= v; Y /= v; Z /= v; W /= v; return *this; };

		//Simple addition to a value operator.
		const Vector4 operator + (float v) const { return Vector4(X + v, Y + v, Z + v, W + v); }
		friend Vector4 operator + (const float lhs, const Vector4 &rhs) { return rhs + lhs; };
		//Simple subtraction to a value operator.
		const Vector4 operator - (float v) const { return Vector4(X - v, Y - v, Z - v, W - v); }
		friend Vector4 operator - (const float lhs, const Vector4 &rhs) { return rhs - lhs; };
		//Simple multiplication to a value operator.
		const Vector4 operator * (float v) const { return Vector4(X * v, Y * v, Z * v, W * v); }
		friend Vector4 operator * (const float lhs, const Vector4 &rhs) { return rhs * lhs; };
		//Simple division to a value operator.
		const Vector4 operator / (float v) const { return Vector4(X / v, Y / v, Z / v, W / v); }
		friend Vector4 operator / (const float lhs, const Vector4 &rhs) { return rhs / lhs; };

		//Simple increment operator.
		Vector4 & operator ++ (int z) { ++X, ++Y, ++Z, ++W; return *this; };
		//Simple decrement operator.
		Vector4 & operator -- (int z) { --X, --Y, --Z, --W; return *this; };

		const Vector4 operator = (const Matrix3& rhs);
		const Vector4 operator = (const Matrix4& rhs);

		#pragma endregion Vector4 operations.
	};

	std::ostream & operator << (std::ostream& stream, const Vector4& vec4);
}