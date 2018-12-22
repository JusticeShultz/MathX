#pragma once
#pragma region Includes
//CMath was included to allow use of sin, cos & tan functions.
#include <cmath>
//String to parse when seeding randoms.
#include <string>
//Time to generate a "random" seed.
#include <time.h>
//Iostream to allow << cout operators.
#include <iostream>
#include <iomanip>

//#include "Color.h"
//#include "Matrix3.h"
//#include "Matrix4.h"
//#include "Randoms.h"
//#include "Vector2.h"
//#include "Vector3.h"
//#include "Vector4.h"

#pragma endregion

#pragma region MathX
//Contains all math related functions in the MathX library.
//(Everything resides in the MathX namespace to not cause issues porting in with other libraries)
//(The only exception to this is if another library has a MathX namespace)

namespace MathX
{
	class Vector2;
	class Vector3;
	class Vector4;
	class Matrix3;
	class Matrix4;

	#pragma region Definitions
	//Full circle in degrees.
	#define FULLCIRCLE 360
	//Half circle in degrees.
	#define HALFCIRCLE 180
	//Quarter circle in degrees.
	#define QUARTERCIRCLE 90
	//Eighth of a circle in degrees.
	#define EIGHTHCIRCLE 45
	//The lowest decimal place we will check the difference of to a float. (0.0001) 
	//[This is a substitute for FLT_EPSILON since floating point numbers lose data]
	#define FLOATMIN 0.0001
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

	#pragma endregion Definitions for things such as pi or Degree to Radians.

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
	//Calculates a quadratic bezier curve.
	template <typename T> T QuadraticBezier(const T& a, const T& b, const T& c, float t) 
	{ 
		T x = Lerp(a, b, t); 
		T y = Lerp(b, c, t); 
		return Lerp(x, y, t); 
	}
	//Calculated a cubic bezier curve.
	template <typename T> T CubicBezier(const T& a, const T& b, const T& c, const T& d, float t) 
	{ 
		T x = Lerp(a, b, t); 
		T y = Lerp(b, c, t); 
		T z = Lerp(c, d, t); 
		return quadraticBezier(x, y, z, t); 
	}
	//Calculates a hermite curve.
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
	//Calculates a catmull rom spline.
	template <typename T> T CatmullRomSpline(const T* controlPoints, size_t count, float t) 
	{
		//UnitTester(count > 1); 

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

	//Unit UnitTester. This is used to compare things and get a printed result to the console. !!!DO NOT USE FOR FLOAT COMPARISON!!!
	template <typename T> void UnitTester(const char *print, const T& a, const T& b)
	{
		if (a == b) std::cout << print << " did not fail!" << std::endl;
		else
		{
			std::cout << "UnitTest failed! " << print << ": " << a << " != " << b << std::endl;
		}
	};

	//Float UnitTester FOR FLOATS ONLY. This is used to compare things and get a printed result to the console. !!!USE FOR FLOATS ONLY!!!
	inline void UnitTester_FLOAT(const char *print, const float a, const float b, float maxRelDiff = FLT_EPSILON)
	{
		bool x = false;

		float temp1 = a;
		float temp2 = b;

		//Calculates the difference.
		float diff = fabs(a - b);
		temp1 = fabs(a);
		temp2 = fabs(b);

		//Finds the largest of the 2 values.
		float largest = (temp2 > temp1) ? temp2 : temp1;

		if (diff <= largest * maxRelDiff)
			x = true;
		else x = false;

		if (x == true) std::cout << print << " did not fail!" << std::endl;
		else
		{
			std::cout << std::fixed;
			std::cout << std::setprecision(7);
			std::cout << "Unit UnitTester failed! " << print << ": " << a << " != " << b << std::endl;
		}
	};

	#pragma endregion All the functions that preform a template based action.

	#pragma region Complex

	/*
	typedef struct Quaternion
	{
		float X;
		float Y;
		float Z;
		float W;

		void Zero() { X = 0, Y = 0, Z = 0; W = 0; };

		Vector3 QuaternionToEuler(Quaternion q)
		{
			Vector3 result = { 0 };
			float x0 = 2.0f*(q.W*q.X + q.Y*q.Z);
			float x1 = 1.0f - 2.0f*(q.X*q.X + q.Y*q.Y);
			result.X = atan2f(x0, x1)*RAD2DEG;
			float y0 = 2.0f*(q.W*q.Y - q.Z*q.X);
			y0 = y0 > 1.0f ? 1.0f : y0;
			y0 = y0 < -1.0f ? -1.0f : y0;
			result.Y = asinf(y0)*RAD2DEG;
			float z0 = 2.0f*(q.W*q.Z + q.X*q.Y);
			float z1 = 1.0f - 2.0f*(q.Y*q.Y + q.Z*q.Z);
			result.Z = atan2f(z0, z1)*RAD2DEG;

			return result;
		}
	};
	*/
	//32bit float type.
	typedef float float32;
	//Simple Vector1 definition.
	typedef float Vector1;

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
	///Matrix3(float q[9]);
	///Vector4 Transform(const Vector4 &a_Point);
	///Vector3 Transform(const Vector3 &a_Point);
	#pragma endregion
}

#pragma endregion