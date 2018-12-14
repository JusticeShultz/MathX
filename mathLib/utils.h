#pragma once
#pragma region Includes
//CMath was included to allow use of sin, cos & tan functions.
#include <cmath>
//String to parse when seeding randoms.
#include <string>
//Time to generate a "random" seed.
#include <time.h>
#pragma endregion
#pragma region MathX
//Contains all math related functions in the MathX library.
//(Everything resides in the MathX namespace to not cause issues porting in with other libraries)
//(The only exception to this is if another library has a MathX namespace)
namespace MathX
{
	#pragma region Definitions
	//Full circle in degrees.
	#define FULLCIRCLE 360
	//Half circle in degrees.
	#define HALFCIRCLE 180
	//Quarter circle in degrees.
	#define QUARTERCIRCLE 90
	//Eighth of a circle in degrees.
	#define EIGHTHCIRCLE 45

	//Defined as PI or π.
	#define PI 3.14159265358979323846
	//Defined as half of PI or (π/2).
	#define HALF_PI (3.14159265358979323846/2)
	//Defined as a fourth of PI or (π/4).
	#define FOURTH_PI (3.14159265358979323846/4)

	//Multiply this with a angle measure expressed in degrees to get its equivalent in radians.
	#define DEG2RAD (PI/180.0f)
	//Multiply this with a angle measure expressed in radians to get its equivalent in degrees.
	#define RAD2DEG (180.0f/PI)
	#pragma endregion Definitions for things such as PI or Degree to Radians.

	#pragma region MathFunctions
	//Returns the smaller of the two values.
	template <typename T> T  Min(T a, T b) { return a < b ? a : b; }
	//Returns the larger of the two values.
	template <typename T> T  Max(T a, T b) { return a > b ? a : b; }
	//Returns a value no smaller than min and no larger than max.
	template <typename T> T Clamp(T value, T min, T max)
	{
		if (value > max) value = max;
		if (value < min) value = min;
		return value;
	}
	//Returns the absolute value of val.
	template <typename T> T  AbsVal(T val) { if (val < 0) val *= -1; return val; }
	//Returns if the values are equal.
	template <typename T> bool Equal(T a, T b) { return a == b; }
	//Returns base to the power of exp (i.e. basepower).
	template <typename T> bool IsPowerOfTwo(T val) { return (val & (val - 1)) == 0; }
	//Returns the next power of two after the given value.
	template <typename T> T  NextPowerOfTwo(T val) { if ((val & (val - 1)) == 0) ++val; return val; }
	//Moves the current value towards the target value. The maximum change should not exceed maxDelta. Might as well be named Lerp.
	template <typename T> T  MoveTowards(T current, T target, T maxDelta)
	{
		if (current < target && current + maxDelta < target) current += maxDelta;
		if (current > target && current - maxDelta > target) current -= maxDelta;
		return current;
	}
	//Return the given value to the power of the input power.
	template <typename T> T  Power(T val, T power) { for (int i = 1; i < power; ++i) val *= val; return val; }
	//Take the square root of a value.
	template <typename T> T Sqrt(T number)
	{
		if (number == 0) return (T)0.000000;

		double error = 0.00001;
		double s = number;

		while ((s - number / s) > error)
		{
			s = (s + number / s) / 2;
		}
		return s;
	}
	
	//Simple action sequence to ease in using a sin function.
	template <typename T> T EaseInSine(float t, const T& b, const T& c, float d) { return b + c - c * cosf(t / d * HALF_PI); }
	//Simple action sequence to ease in using a linear function.
	template <typename T> T LinearEase(float t, const T& b, const T& c, float d) { return b + c * (t / d); }
	//Simple action sequence to ease in using a Lerp function.
	template <typename T> T Lerp(const T& a, const T& b, float t) { return a + (b - a) * t; }
	template <typename T> T QuadraticBezier(const T& a, const T& b, const T& c, float t) { T x = Lerp(a, b, t); T y = Lerp(b, c, t); return Lerp(x, y, t); }
	template <typename T> T CubicBezier(const T& a, const T& b, const T& c, const T& d, float t) 
	{ 
		T x = Lerp(a, b, t); 
		T y = Lerp(b, c, t); 
		T z = Lerp(c, d, t); 
		return quadraticBezier(x, y, z, t); 
	}
	template <typename T> T HermiteCurve(const T& p0, const T& t0, const T& p1, const T& t1, float t)
	{ 
		// calculate the time-step squared and cubed 
		float tt = t * t; float ttt = tt * t; 
		// calculate hermite basis curves 
		float h00 = 2 * ttt - 3 * tt + 1; 
		float h10 = ttt - 2 * tt + t; 
		float h01 = -2 * ttt + 3 * tt; 
		float h11 = ttt - tt; 
		// combine points and tangents 
		return p0 * h00 + t0 * h10 + p1 * h01 + t1 * h11; 
	}
	template <typename T> T CatmullRomSpline(const T* controlPoints, size_t count, float t) 
	{
		//assert(count > 1); 

		// early out 
		if (t <= 0) 
			return controlPoints[0]; 
		if (t >= 1) return controlPoints[count - 1];
		
		// how long does a single curve segment last for 
		float stepDuration = 1.0f / (count - 1); 
		// find control point indices 
		int p0 = int(t / stepDuration); 
		int p1 = p0 + 1; 
		// calculate tangents 
		T t0, t1; 
		if (p0 == 0) 
			t0 = (controlPoints[p0 + 1] - controlPoints[p0]) * 0.5f; 
		else if (p0 == count - 1) 
			t0 = (controlPoints[p0] - controlPoints[p0 - 1]) * 0.5f; 
		else t0 = (controlPoints[p0 + 1] - controlPoints[p0 - 1]) * 0.5f; 
		if (p1 == 0) 
			t1 = (controlPoints[p1 + 1] - controlPoints[p1]) * 0.5f; 
		else if (p1 == count - 1) 
			t1 = (controlPoints[p1] - controlPoints[p1 - 1]) * 0.5f; 
		else t1 = (controlPoints[p1 + 1] - controlPoints[p1 - 1]) * 0.5f; 

		// how far are we through this segment 
		float s = fmod(t, stepDuration) / stepDuration;

		// return curve result 
		return HermiteCurve(controlPoints[p0], t0, controlPoints[p1], t1, s);
	}
	#pragma endregion All the functions that preform a template based action.

	#pragma region Vectors
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
	#pragma endregion Vector declerations.

	#pragma region Complex
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
		int R;
		int G;
		int B;
		int A;

		Color();
		Color(int v1);
		Color(int v1, int v2, int v3, int v4);
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

	#pragma region colorDecls
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
	//Predefined light green.
	#define Light_Green Color{ 0, 250, 35, 255 } 
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
	#pragma endregion colorDecls

	//NOTE: Matrices are not completed due to lack of documentation on the handbook
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

	class Random
	{
	private:
		int Seed;
	public:
		Random() {}
		
		//Returns a random value between min and max
		template <typename T> T rand(T min, T max)
		{
			//Do a modulo gen first.
			T a = Seed % (max - min) + min;

			//Make a new seed off of our current seed.
			reseed();
			//Return the result.
			return a;
		};

		//Returns a random value between min and max
		// - the value may contain decimal components
		//(MAKE SURE YOU PASS 2 DOUBLES OR 2 FLOATS IF YOU WANT DECIMAL POINT RETURNS!)
		template <typename T> T randDecimal(T min, T max)
		{
			T q = (min + max * Seed / Seed * Seed / max * min - max) * 0.01;

			reseed();

			T rando = std::fmod(Seed, (max - min) + min);

			return Clamp(q * 0.000001 + rando, (double)min, (double)max);
		};

		//[SETTER] Uses system time to seed a new value.
		void setRandSeed() { seed((time(NULL) * time(NULL))); };
		//Give a starting seed. This seed will be what we seed off of. (Recommended to use the systems time - Use setRandSeed() for easy use!)
		void seed(unsigned int value)
		{
			Seed = value;

			//Square it.
			Seed = Seed * Seed;

			//Parse the seed down to 6 characters.
			std::string temp = std::to_string(Seed);

			//Make sure the seed is the required size.
			while (temp.size() < 9)
			{
				//If it's not then square it and set it until it is.
				Seed = Seed * Seed;
				temp = std::to_string(Seed);
			}

			//Prune the seed down to 9 digits.
			while (temp.size() > 9) temp.pop_back();

			//Prune the front 3 digits of the seed.
			std::string temp2;

			//Push forward the last 6 digits.
			for (int i = 2; i < temp.size(); ++i)
			{
				temp2.push_back(temp[i]);
			}

			//Set the seed to the result.
			Seed = std::stoi(temp2);
		};

		//If you have previously seeded the value, use this
		void reseed()
		{
			//Square it.
			Seed = Seed * Seed;

			//Parse the seed down to 6 characters.
			std::string temp = std::to_string(Seed);

			//Prune the seed down to 9 digits.
			while (temp.size() > 9) temp.pop_back();

			//Prune the front 3 digits of the seed.
			std::string temp2;

			//Push forward the last 6 digits.
			for (int i = 2; i < temp.size(); ++i)
			{
				temp2.push_back(temp[i]);
			}
			
			//Set the seed to the result.
			Seed = std::stoi(temp2);
		};
	};
	#pragma endregion Complex math functions such as matrices, randoms, colors and quaternions.

	#pragma region [DEPRECATED]
	///Lerp from a start to an end with a given rate. 
	///float Lerp(float start, float end, float amount);
	///template <typename T> T Lerp(const T& a, const T& b, float t);
	///Vector2 HermiteCurve(Vector2 point0, Vector2 tangent0, Vector2 point1, Vector2 tangent1, float t)
	///{
	/// calculate t-squared and t-cubed​ float tsq = t * t; float tcub = tsq * t; // calculate the 4 basis functions​ 
	///float h00 = 2 * tcub - 3 * tsq + 1; float h01 = -2 * tcub + 3 * tsq; float h10 = tcub - 2 * tsq + t; float h11 = tcub - tsq;
	/// return the combined result​ return h00 * point0 + h10 * tangent0 + h01 * point1 + h11 * tangent1;
	///};
	///template <typename T> T rand(T min, T max) { static long a = Seed; a = (a * 32719 + 3) % 32749; return ((a % max) + min); };
	///double d = 5  %3.3d;
	#pragma endregion
}
#pragma endregion