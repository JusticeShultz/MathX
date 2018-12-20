#include "utils.h"
//#include <cTestUnit>
#include <iostream>

//To save a lot of headache:
using namespace MathX;

int main()
{
	//Copy paste of the assessable unit test code + additionals. 
	//(Some functions have different naming conventions so there is a minor difference)

	// vector addition
	Vector2 v2a(13.5f, -48.23f), v2b(5, 3.99f), v2c;
	v2c = v2a + v2b;
	Vector3 v3a(13.5f, -48.23f, 862), v3b(5, 3.99f, -12), v3c;
	v3c = v3a + v3b;
	Vector4 v4a(13.5f, -48.23f, 862, 0), v4b(5, 3.99f, -12, 1), v4c;
	v4c = v4a + v4b;

	TestUnit("Vector2 addition", v2c, Vector2(18.5f, -44.24f));
	TestUnit("Vector3 addition", v3c, Vector3(18.5f, -44.24f, 850));
	TestUnit("Vector4 addition", v4c, Vector4(18.5f, -44.24f, 850, 1));

	// vector subtraction
	v2a = Vector2(13.5f, -48.23f);
	v2b = Vector2(5, 3.99f);
	v2c = v2a - v2b;
	v3a = Vector3(13.5f, -48.23f, 862);
	v3b = Vector3(5, 3.99f, -12);
	v3c = v3a - v3b;
	v4a = Vector4(13.5f, -48.23f, 862, 0);
	v4b = Vector4(5, 3.99f, -12, 1);
	v4c = v4a - v4b;

	TestUnit("Vector2 subtraction", v2c, Vector2(8.5f, -52.22f));
	TestUnit("Vector3 subtraction", v3c, Vector3(8.5f, -52.22f, 874));
	TestUnit("Vector4 subtraction", v4c, Vector4(8.5f, -52.22f, 874, -1));

	// vector post-scale
	v2a = Vector2(13.5f, -48.23f);
	v2c = v2a * 2.482f;
	v3a = Vector3(13.5f, -48.23f, 862);
	v3c = v3a * 0.256f;
	v4a = Vector4(13.5f, -48.23f, 862, 0);
	v4c = v4a * 4.89f;

	TestUnit("Vector2 post-scale", v2c, Vector2(33.5069999695f, -119.706863403f));
	TestUnit("Vector3 post-scale", v3c, Vector3(3.45600008965f, -12.3468809128f, 220.672012329f));
	TestUnit("Vector4 post-scale", v4c, Vector4(66.0149993896f, -235.844696045f, 4215.1796875f, 0));

	// vector pre-scale
	v2a = Vector2(13.5f, -48.23f);
	v2c = 2.482f * v2a;
	v3a = Vector3(13.5f, -48.23f, 862);
	v3c = 0.256f * v3a;
	v4a = Vector4(13.5f, -48.23f, 862, 0);
	v4c = 4.89f * v4a;

	TestUnit("Vector2 pre-scale", v2c, Vector2(33.5069999695f, -119.706863403f));
	TestUnit("Vector3 pre-scale", v3c, Vector3(3.45600008965f, -12.3468809128f, 220.672012329f));
	TestUnit("Vector4 pre-scale", v4c, Vector4(66.0149993896f, -235.844696045f, 4215.1796875f, 0));

	// vector Dot product
	v2a = Vector2(13.5f, -48.23f);
	v2b = Vector2(5, 3.99f);
	float Dot2 = v2a.Dot(v2b);
	v3a = Vector3(13.5f, -48.23f, 862);
	v3b = Vector3(5, 3.99f, -12);
	float Dot3 = v3a.Dot(v3b);
	v4a = Vector4(13.5f, -48.23f, 862, 0);
	v4b = Vector4(5, 3.99f, -12, 1);
	float Dot4 = v4a.Dot(v4b);

	TestUnit_FLOAT("Vector2 Dot", Dot2, -124.937698364f, 0.0001f);
	TestUnit_FLOAT("Vector3 Dot", Dot3, -10468.9375f, 0.0001f);
	TestUnit_FLOAT("Vector4 Dot", Dot4, -10468.9375f, 0.0001f);

	// vector Cross product
	v3a = Vector3(13.5f, -48.23f, 862);
	v3b = Vector3(5, 3.99f, -12);
	v3c = v3a.Cross(v3b);
	v4a = Vector4(13.5f, -48.23f, 862, 0);
	v4b = Vector4(5, 3.99f, -12, 1);
	v4c = v4a.Cross(v4b);

	TestUnit("Vector3 Cross", v3c, Vector3(-2860.62011719f, 4472.00000000f, 295.01498413f));
	TestUnit("Vector4 Cross", v4c, Vector4(-2860.62011719f, 4472.00000000f, 295.01498413f, 0));

	// vector Magnitude
	v2a = Vector2(13.5f, -48.23f);
	float mag2 = v2a.Magnitude();
	v3a = Vector3(13.5f, -48.23f, 862);
	float mag3 = v3a.Magnitude();
	v4a = Vector4(13.5f, -48.23f, 862, 0);
	float mag4 = v4a.Magnitude();

	TestUnit_FLOAT("Vector2 Magnitude", mag2, 50.0837593079f, 0.0001f);
	TestUnit_FLOAT("Vector3 Magnitude", mag3, 863.453735352f, 0.0001f);
	TestUnit_FLOAT("Vector4 Magnitude", mag4, 863.453735352f, 0.0001f);

	// vector Normalize
	v2a = Vector2(-13.5f, -48.23f);
	v2a.Normalize();
	v3a = Vector3(13.5f, -48.23f, 862);
	v3a.Normalize();
	v4a = Vector4(243, -48.23f, 862, 0);
	v4a.Normalize();

	TestUnit("Vector2 Normalize", v2a, Vector2(-0.269548f, -0.962987f));
	TestUnit("Vector3 Normalize", v3a, Vector3(0.0156349f, -0.0558571f, 0.998316f));
	TestUnit("Vector4 Normalize", v4a, Vector4(0.270935f, -0.0537745f, 0.961094f, 0));

	auto a = Vector2(5, -10);
	auto b = a.PerpendicularClockwise();
	auto c = a.PerpendicularCounterClockwise();

	TestUnit("Vector2 Perpendicular Clockwise", Vector2(-10, -5), b);
	TestUnit("Vector2 Perpendicular Counter Clockwise", Vector2(10, 5), c);

	auto a1 = Vector2(1, 0);
	auto b1 = Vector2(0, 1);

	//THIS ALSO TESTS RADIANS TO DEGREES!
	TestUnit_FLOAT("Vector2 Angle Between degrees 1", a1.AngleBetweenDegrees(b1), -45.0f, 0.0001f);
	TestUnit_FLOAT("Vector2 Angle Between degrees 2", b1.AngleBetweenDegrees(a1), 135.0f, 0.0001f);
	
	//According to google it is 0.785398163 but we are not using doubles.
	TestUnit_FLOAT("Vector2 Angle Between radians 1", a1.AngleBetweenRadians(b1), -0.785398f, 0.0001f);
	TestUnit_FLOAT("Vector2 Angle Between radians 2", b1.AngleBetweenRadians(a1), 2.35619f, 0.0001f);

	auto a2 = Vector2(10, -10);
	a2.SetScale(25);

	TestUnit("Vector2 set scale", a2, Vector2(250, -250));
	TestUnit("Vector2 get scale", a2.GetScale(10), Vector2(2500, -2500));

	std::cout << "\n\nIf nothing above failed then additionaly: Length, Length Squared, Squareroot,\nPrint, Set, Distance, Distance Squared, Zero, One, Five, Fifty and All operatorsdid not fail!";

	std::cout << "\n\n\nSomehow stuff didn't break, that's pretty neat!\n\n\n";
	system("pause");
	return 1;
}