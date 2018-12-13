#pragma once

//Contains all math related functions in the MathX library.
//(Everything resides in the MathX namespace to not cause issues porting in with other libraries)
//(The only exception to this is if another library has a MathX namespace)
namespace MathX
{
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
	//Return the square root of a passed value.
	double sqrt(double x);
	//Lerp from a start to an end with a given rate.
	float lerp(float start, float end, float amount);

	class Vector2
	{
	public:
		//Input value X.
		float X;
		//Input value Y.
		float Y;

		//Sets the values to 0. (Use the constructor input for a init value)
		void Zero() { X = 0, Y = 0; };
		//Sets the values to 1. (Use the constructor input for a init value)
		void One() { X = 1, Y = 1; };
		//Sets the values to 5. (Use the constructor input for a init value)
		void Five() { X = 5, Y = 5; };
		//Sets the values to 50. (Use the constructor input for a init value)
		void Fifty() { X = 50, Y = 50; };

		//Default constructor.
		Vector2(void);
		//Data input constructor.
		Vector2(float xValue, float yValue);
		//Additional constructor type.
		Vector2(const Vector2 & v);
		//Additional constructor type.
		Vector2(const Vector2 * v);
		//Deconstructor
		~Vector2(void);

		//Setter function.
		void Set(float xValue, float yValue);
		//Get the length of the vector.
		float Length() const;
		//Get the Magnitude of the vector
		float Magnitude() const;
		//Get the length squared of the vector.
		float LengthSquared() const;
		//Get the distance of the vector.
		float Distance(const Vector2 & v) const;
		//Get the distance squared of the vector.
		float DistanceSquared(const Vector2 & v) const;
		//Get the Dot product of the vector.
		float Dot(const Vector2 & v) const;
		//Get the Cross product of the vector.
		float Cross(const Vector2 & v) const;
		//Get the normal of the vector.
		Vector2 & Normal();
		//Normalize the vector.
		Vector2 & Normalize();

		//Vector2 operators:

		//Setter Vector2 input.
		Vector2 & operator = (const Vector2 & v) { X = v.X; Y = v.Y; return *this; };
		//Setter 1 value input.
		Vector2 & operator = (const float & f) { X = f; Y = f; return *this; };
		//Negative operation.
		Vector2 & operator - (void) { X = -X; Y = -Y; return *this; };

		//Checker equals operation.
		bool operator == (const Vector2 & v) const { return (X == v.X) && (Y == v.Y); };
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
	};

	class Vector3
	{
	public:
		//Input value X.
		float X;
		//Input value Y.
		float Y;
		//Input value Z.
		float Z;

		//Sets the values to 0. (Use the constructor input for a init value)
		void Zero() { X = 0, Y = 0; Z = 0; };
		//Sets the values to 1. (Use the constructor input for a init value)
		void One() { X = 1, Y = 1; Z = 1; };
		//Sets the values to 5. (Use the constructor input for a init value)
		void Five() { X = 5, Y = 5; Z = 5; };
		//Sets the values to 50. (Use the constructor input for a init value)
		void Fifty() { X = 50, Y = 50; Z = 50; };

		//Default constructor.
		Vector3(void);
		//Data input constructor.
		Vector3(float xValue, float yValue, float zValue);
		//Additional constructor type.
		Vector3(const Vector3 & v);
		//Additional constructor type.
		Vector3(const Vector3 * v);
		//Deconstructor
		~Vector3(void);

		//Setter function.
		void Set(float xValue, float yValue, float zValue);
		//Get the length of the vector.
		float Length() const;
		//Get the length squared of the vector.
		float LengthSquared() const;
		//Get the Magnitude of the vector
		float Magnitude() const;
		//Get the distance of the vector.
		float Distance(const Vector3 & v) const;
		//Get the distance squared of the vector.
		float DistanceSquared(const Vector3 & v) const;
		//Get the Dot product of the vector.
		float Dot(const Vector3 & v) const;
		//Get the Cross product of the vector.
		float Cross(const Vector3 & v) const;
		//Get the normal of the vector.
		Vector3 & Normal();
		//Normalize the vector.
		Vector3 & Normalize();

		//Vector3 operators:

		//Setter Vector3 input.
		Vector3 & operator = (const Vector3 & v) { X = v.X; Y = v.Y; Z = v.Z; return *this; };
		//Setter 1 value input.
		Vector3 & operator = (const float & f) { X = f; Y = f; Z = f; return *this; };
		//Negative operation.
		Vector3 & operator - (void) { X = -X; Y = -Y; Z = -Z; return *this; };

		//Checker equals operation.
		bool operator == (const Vector3 & v) const { return (X == v.X) && (Y == v.Y) && (Z == v.Z); };
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
		const Vector3 operator + (float v) const { return Vector3(X + v, Y + v, Z  + v); }
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
	};

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

		//Sets the values to 0. (Use the constructor input for a init value)
		void Zero() { X = 0, Y = 0; Z = 0; W = 0; };
		//Sets the values to 1. (Use the constructor input for a init value)
		void One() { X = 1, Y = 1; Z = 1; W = 1; };
		//Sets the values to 5. (Use the constructor input for a init value)
		void Five() { X = 5, Y = 5; Z = 5; W = 5; };
		//Sets the values to 50. (Use the constructor input for a init value)
		void Fifty() { X = 50, Y = 50; Z = 50; W = 50; };

		//Default constructor.
		Vector4(void);
		//Data input constructor.
		Vector4(float xValue, float yValue, float zValue, float wValue);
		//Additional constructor type.
		Vector4(const Vector4 & v);
		//Additional constructor type.
		Vector4(const Vector4 * v);
		//Deconstructor
		~Vector4(void);

		//Setter function.
		void Set(float xValue, float yValue, float zValue, float wValue);
		//Get the length of the vector.
		float Length() const;
		//Get the length squared of the vector.
		float LengthSquared() const;
		//Get the distance of the vector.
		float Distance(const Vector4 & v) const;
		//Get the distance squared of the vector.
		float DistanceSquared(const Vector4 & v) const;
		//Get the Magnitude of the vector
		float Magnitude() const;
		//Get the Dot product of the vector.
		float Dot(const Vector4 & v) const;
		//Get the Cross product of the vector.
		float Cross(const Vector4 & v) const;
		//Get the normal of the vector.
		Vector4 & Normal();
		//Normalize the vector.
		Vector4 & Normalize();

		//Vector4 operators:

		//Setter Vector4 input.
		Vector4 & operator = (const Vector4 & v) { X = v.X; Y = v.Y; Z = v.Z; W = v.W; return *this; };
		//Setter 1 value input.
		Vector4 & operator = (const float & f) { X = f; Y = f; Z = f; W = f; return *this; };
		//Negative operation.
		Vector4 & operator - (void) { X = -X; Y = -Y; Z = -Z; W = -W; return *this; };

		//Checker equals operation.
		bool operator == (const Vector4 & v) const { return (X == v.X) && (Y == v.Y) && (Z == v.Z) && (W == v.W); };
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
	};

	typedef struct Quaternion
	{
		float X;
		float Y;
		float Z;
		float W;

		void Zero() { X = 0, Y = 0, Z = 0; W = 0; };

		//Currently not working, need `a` type math functions to make this actually work(include cmath and uncomment to work properly).
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

	//32bit float type.
	typedef float float32;
	//Simple Vector1 definition.
	typedef float Vector1;

	class Color
	{
	public:
		char R;
		char G;
		char B;
		char A;

		Color();
		Color(char v1);
		Color(char v1, char v2, char v3, char v4);
		~Color();

		//Color operators:

		//Setter color input.
		Color & operator = (const Color & v) { R = v.R; G = v.G; B = v.B; A = v.A; return *this; };
		//Setter 1 value input.
		Color & operator = (const float & f) { R = f; G = f; B = f; A = f; return *this; };
		//Negative operation.
		Color & operator - (void) { R = -R; G = -G; B = -B; A = -A; return *this; };

		//Checker equals operation.
		bool operator == (const Color & v) const { return (R == v.R) && (G == v.G) && (B == v.B) && (A == v.A); };
		//Checker does not equal operation.
		bool operator != (const Color & v) const { return (R != v.R) || (G != v.G) || (B != v.B) || (A != v.A); };

		//Simple addition operation.
		const Color operator + (const Color & v) const { Color q; q.R = R + v.R; q.G = G + v.G; q.B = B + v.B; q.A = A + v.A; return q; };
		//Simple subtraction operation.
		const Color operator - (const Color & v) const { Color q; q.R = R - v.R; q.G = G - v.G; q.B = B - v.B; q.A = A - v.A; return q; };
		//Simple multiplication operation.
		const Color operator * (const Color & v) const { Color q; q.R = R * v.R; q.G = G * v.G; q.B = B * v.B; q.A = A * v.A; return q; };
		//Simple division operation.
		const Color operator / (const Color & v) const { Color q; q.R = R / v.R; q.G = G / v.G; q.B = B / v.B; q.A = A / v.A; return q; };

		//Simple addition operation - simple.
		Color & operator += (const Color & v) { R += v.R; G += v.G; B += v.B; A += v.A; return *this; };
		//Simple subtraction operation - simple.
		Color & operator -= (const Color & v) { R -= v.R; G -= v.G; B -= v.B; A -= v.A; return *this; };
		//Simple multiplication operation - simple.
		Color & operator *= (const Color & v) { R *= v.R; G *= v.G; B *= v.B; A *= v.A; return *this; };
		//Simple division operation - simple.
		Color & operator /= (const Color & v) { R /= v.R; G /= v.G; B /= v.B; A /= v.A; return *this; };

		//Simple addition operation - simple one value input.
		Color & operator += (float v) { R += v; G += v; B += v; A += v; return *this; };
		//Simple subtraction operation - simple one value input.
		Color & operator -= (float v) { R -= v; G -= v; B -= v; A -= v; return *this; };
		//Simple multiplication operation - simple one value input.
		Color & operator *= (float v) { R *= v; G *= v; B *= v; A *= v; return *this; };
		//Simple division operation - simple one value input.
		Color & operator /= (float v) { R /= v; G /= v; B /= v; A /= v; return *this; };

		//Simple addition to a value operator.
		const Color operator + (float v) const { return Color(R + v, G + v, B + v, A + v); }
			friend Color operator + (const float lhs, const Color &rhs) { return rhs + lhs; };
		//Simple subtraction to a value operator.
		const Color operator - (float v) const { return Color(R - v, G - v, B - v, A - v); }
			friend Color operator - (const float lhs, const Color &rhs) { return rhs - lhs; };
		//Simple multiplication to a value operator.
		const Color operator * (float v) const { return Color(R * v, G * v, B * v, A * v); }
			friend Color operator * (const float lhs, const Color &rhs) { return rhs * lhs; };
		//Simple division to a value operator.
		const Color operator / (float v) const { return Color(R / v, G / v, B / v, A / v); }
			friend Color operator / (const float lhs, const Color &rhs) { return rhs / lhs; };

		//Simple increment operator.
		Color & operator ++ (int z) { ++R, ++G, ++B, ++A; return *this; };
		//Simple decrement operator.
		Color & operator -- (int z) { --R, --G, --B, --A; return *this; };
	};

	//Predefined light gray.
	#define Light_Gray Color{ 200, 200, 200, 255 }
	//Predefined gray.
	#define Gray Color{ 130, 130, 130, 255 }
	//Predefined dark gray.
	#define Dark_Gray Color{ 80, 80, 80, 255 }
	//Predefined yellow.
	#define Yellow Color{ 253, 249, 0, 255 } 
	//Predefined gold.
	#define Gold Color{ 255, 203, 0, 255 } 
	//Predefined orange.
	#define Orange Color{ 255, 161, 0, 255 } 
	//Predefined pink.
	#define Pink Color{ 255, 109, 194, 255 } 
	//Predefined red.
	#define Red Color{ 230, 41, 55, 255 } 
	//Predefined maroon.
	#define Maroon Color{ 190, 33, 55, 255 } 
	//Predefined green.
	#define Green Color{ 0, 228, 48, 255 } 
	//Predefined dark green.
	#define Dark_Green Color{ 0, 117, 44, 255 } 
	//Predefined sky blue.
	#define Sky_Blue Color{ 102, 191, 255, 255 } 
	//Predefined blue.
	#define Blue Color{ 0, 121, 241, 255 } 
	//Predefined dark blue.
	#define Dark_Blue Color{ 0, 82, 172, 255 } 
	//Predefined purple.
	#define Purple Color{ 200, 122, 255, 255 } 
	//Predefined violet.
	#define Violet Color{ 135, 60, 190, 255 } 
	//Predefined dark purple.
	#define Dark_Purple Color{ 112, 31, 126, 255 } 
	//Predefined beige.
	#define Beige Color{ 211, 176, 131, 255 } 
	//Predefined brown.
	#define Brown Color{ 127, 106, 79, 255 } 
	//Predefined dark brown.
	#define Dark_Brown Color{ 76, 63, 47, 255 } 
	//Predefined white.
	#define White Color{ 255, 255, 255, 255 } 
	//Predefined black.
	#define Black Color{ 0, 0, 0, 255 } 
	//Predefined blank color.
	#define Blank Color{ 0, 0, 0, 0 } 
	//Predefined empty color.
	#define Empty_Color Color{ 0, 0, 0, 0 } 
	//Predefined magenta.
	#define Magenta Color{ 255, 0, 255, 255 } 
	//Predefined webpage white.
	#define Webpage_White Color{ 245, 245, 245, 255 }

	//NOTE: Matrices are not completed due to lack of documentation on the handbook(cough, cough Terry)
	class Matrix2
	{
	public:
		//Matrix array(4)
		int Row[4];

		//Empty constructor(All default to 0).
		Matrix2();

		//Single fill constructor.
		Matrix2(int a);

		//2 row constructor.
		Matrix2
		(
			int a, int b
		);

		//4 integral constructor.
		Matrix2
		(
			int a, int b,
			int c, int d
		);

		//Common deconstructor.
		~Matrix2();
	};

	class Matrix3
	{
	public:
		//Matrix array(9)
		int Row[9];

		//Empty constructor(All default to 0).
		Matrix3();

		//Single fill constructor.
		Matrix3(int a);

		//3 row constructor.
		Matrix3
		(
			int a, int b, int c
		);

		//9 integral constructor.
		Matrix3
		(
			int a, int b, int c,
			int d, int e, int f,
			int g, int h, int i
		);

		//Common deconstructor.
		~Matrix3();
	};

	class Matrix4
	{
	public:
		//Matrix array(16)
		int Row[16];

		//Empty constructor(All default to 0).
		Matrix4();

		//Single fill constructor.
		Matrix4(int a);

		//4 row constructor.
		Matrix4
		(
			int a, int b, int c, int d
		);

		//16 integral constructor.
		Matrix4
		(
			int a, int b, int c, int d,
			int e, int f, int g, int h,
			int i, int j, int k, int l,
			int m, int n, int o, int p
		);

		//Common deconstructor.
		~Matrix4();
	};
}