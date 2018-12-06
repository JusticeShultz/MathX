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
}