#pragma once
#include "utils.h"


namespace MathX
{
	class Matrix3;
	class Matrix4;
	class Vector2
	{
	public:
		//Input value X.
		float X;
		//Input value Y.
		float Y;

		//[SETTER] Sets the values to 0. (Use the constructor input for a init value)
		void Zero() { X = 0, Y = 0; };
		//[SETTER] Sets the values to 1. (Use the constructor input for a init value)
		void One() { X = 1, Y = 1; };
		//[SETTER] Sets the values to 5. (Use the constructor input for a init value)
		void Five() { X = 5, Y = 5; };
		//[SETTER] Sets the values to 50. (Use the constructor input for a init value)
		void Fifty() { X = 50, Y = 50; };

		//[SETTER] Default constructor.
		Vector2(void);
		//[SETTER] Data input constructor.
		Vector2(float xValue, float yValue);
		//[SETTER] Additional constructor type.
		Vector2(const Vector2 & v);
		//[SETTER] Additional constructor type.
		Vector2(const Vector2 * v);
		//[SETTER] Deconstructor
		~Vector2(void);

		//[DISPLAYER] Prints to the console the values contained in this vector type.
		void Print() const;
		//[SETTER] Simple setter function.
		void Set(float xValue, float yValue);
		//[GETTER] Get the length of the vector.
		float Length() const;
		//[GETTER] Get the Magnitude of the vector
		float Magnitude() const;
		//[GETTER] Get the length squared of the vector.
		float LengthSquared() const;
		//[GETTER] Get the distance of the vector.
		float Distance(const Vector2 & v) const;
		//[GETTER] Get the distance squared of the vector.
		float DistanceSquared(const Vector2 & v) const;
		//[GETTER] Get the Dot product of the vector.
		float Dot(const Vector2 & v) const;
		//[GETTER] Get the Cross product of the vector.
		float Cross(const Vector2 & v) const;
		//[SETTER] Set the vector to be scaled by a given float value.
		void SetScale(const float scale);
		//[GETTER] Get the scaled version of the vector by a float value given.
		Vector2 GetScale(const float scale);
		//[SETTER] Set the vector to be scaled by a given float value. [Vector2]
		void SetScale(const Vector2 scale);
		//[GETTER] Get the scaled version of the vector by a float value given. [Vector2]
		Vector2 GetScale(const Vector2 scale);
		//[GETTER] Get the angle between this vector and a given vector.
		float AngleBetweenDegrees(const Vector2 other);
		//[GETTER] Get the angle between this vector and a given vector.
		float AngleBetweenRadians(const Vector2 other);
		//[GETTER] Get the perpendicular clockwise of the vector.
		Vector2 PerpendicularClockwise();
		//[GETTER] Get the perpendicular counter clockwise of the vector.
		Vector2 PerpendicularCounterClockwise();
		//[GETTER] Get the normal of the vector.
		Vector2 & Normal();
		//[SETTER] Normalize the vector.
		Vector2 & Normalize();

		#pragma region Operators
		//Vector2 operators:

		//Setter Vector2 input.
		Vector2 & operator = (const Vector2 & v) { X = v.X; Y = v.Y; return *this; };
		//Setter 1 value input.
		Vector2 & operator = (const float & f) { X = f; Y = f; return *this; };
		//Negative operation.
		Vector2 & operator - (void) { X = -X; Y = -Y; return *this; };

		//Checker equals operation.
		bool operator == (const Vector2 & v) const
		{
			bool x = false, y = false;

			//Check X.

			Vector2 temp1 = v;
			Vector2 temp2 = Vector2(X, Y);

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

			return x && y;
		};

		//Checker does not equal operation.
		bool operator != (const Vector2 & v) const { return (X != v.X) || (Y != v.Y); };

		//Simple addition operation.
		const Vector2 operator + (const Vector2 & v) const { Vector2 q; q.X = X + v.X; q.Y = Y + v.Y; return q; };
		//Simple subtraction operation.
		const Vector2 operator - (const Vector2 & v) const { Vector2 q; q.X = X - v.X; q.Y = Y - v.Y; return q; };
		//Simple multiplication operation.
		const Vector2 operator * (const Vector2 & v) const { Vector2 q; q.X = X * v.X; q.Y = Y * v.Y; return q; };
		//Simple division operation.
		const Vector2 operator / (const Vector2 & v) const { Vector2 q; q.X = X / v.X; q.Y = Y / v.Y; return q; };

		//Simple addition operation - simple.
		Vector2 & operator += (const Vector2 & v) { X += v.X; Y += v.Y; return *this; };
		//Simple subtraction operation - simple.
		Vector2 & operator -= (const Vector2 & v) { X -= v.X; Y -= v.Y; return *this; };
		//Simple multiplication operation - simple.
		Vector2 & operator *= (const Vector2 & v) { X *= v.X; Y *= v.Y; return *this; };
		//Simple division operation - simple.
		Vector2 & operator /= (const Vector2 & v) { X /= v.X; Y /= v.Y; return *this; };

		//Simple addition operation - simple one value input.
		Vector2 & operator += (float v) { X += v; Y += v; return *this; };
		//Simple subtraction operation - simple one value input.
		Vector2 & operator -= (float v) { X -= v; Y -= v; return *this; };
		//Simple multiplication operation - simple one value input.
		Vector2 & operator *= (float v) { X *= v; Y *= v; return *this; };
		//Simple division operation - simple one value input.
		Vector2 & operator /= (float v) { X /= v; Y /= v; return *this; };

		//Simple addition to a value operator.
		const Vector2 operator + (float v) const { return Vector2(X + v, Y + v); }
		friend Vector2 operator + (const float lhs, const Vector2 &rhs) { return rhs + lhs; };
		//Simple subtraction to a value operator.
		const Vector2 operator - (float v) const { return Vector2(X - v, Y - v); }
		friend Vector2 operator - (const float lhs, const Vector2 &rhs) { return rhs - lhs; };
		//Simple multiplication to a value operator.
		const Vector2 operator * (float v) const { return Vector2(X * v, Y * v); }
		friend Vector2 operator * (const float lhs, const Vector2 &rhs) { return rhs * lhs; };
		//Simple division to a value operator.
		const Vector2 operator / (float v) const { return Vector2(X / v, Y / v); }
		friend Vector2 operator / (const float lhs, const Vector2 &rhs) { return rhs / lhs; };

		//Simple increment operator.
		Vector2 & operator ++ (int z) { ++X, ++Y; return *this; };
		//Simple decrement operator.
		Vector2 & operator -- (int z) { --X, --Y; return *this; };

		const Vector2 operator = (const Matrix3& rhs);
		const Vector2 operator = (const Matrix4& rhs);

		#pragma endregion Vector2 operations.
	};

	inline std::ostream & operator << (std::ostream& stream, const Vector2& vec2) { vec2.Print(); return stream; }
}