#include "MathX.h"
#include <cassert>
//#include <cUnitTester>
#include <iostream>

//To save a lot of headache:
using namespace MathX;

int main()
{
	//Copy paste of the assessable unit UnitTester code + additionals. 
	//(Some functions have different naming conventions so there is a minor difference)

	// vector addition
	Vector2 v2a(13.5f, -48.23f), v2b(5, 3.99f), v2c;
	v2c = v2a + v2b;
	Vector3 v3a(13.5f, -48.23f, 862), v3b(5, 3.99f, -12), v3c;
	v3c = v3a + v3b;
	Vector4 v4a(13.5f, -48.23f, 862, 0), v4b(5, 3.99f, -12, 1), v4c;
	v4c = v4a + v4b;

	UnitTester("Vector2 addition", v2c, Vector2(18.5f, -44.24f));
	UnitTester("Vector3 addition", v3c, Vector3(18.5f, -44.24f, 850));
	UnitTester("Vector4 addition", v4c, Vector4(18.5f, -44.24f, 850, 1));

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

	UnitTester("Vector2 subtraction", v2c, Vector2(8.5f, -52.22f));
	UnitTester("Vector3 subtraction", v3c, Vector3(8.5f, -52.22f, 874));
	UnitTester("Vector4 subtraction", v4c, Vector4(8.5f, -52.22f, 874, -1));

	// vector post-scale
	v2a = Vector2(13.5f, -48.23f);
	v2c = v2a * 2.482f;
	v3a = Vector3(13.5f, -48.23f, 862);
	v3c = v3a * 0.256f;
	v4a = Vector4(13.5f, -48.23f, 862, 0);
	v4c = v4a * 4.89f;

	UnitTester("Vector2 post-scale", v2c, Vector2(33.5069999695f, -119.706863403f));
	UnitTester("Vector3 post-scale", v3c, Vector3(3.45600008965f, -12.3468809128f, 220.672012329f));
	UnitTester("Vector4 post-scale", v4c, Vector4(66.0149993896f, -235.844696045f, 4215.1796875f, 0));

	// vector pre-scale
	v2a = Vector2(13.5f, -48.23f);
	v2c = 2.482f * v2a;
	v3a = Vector3(13.5f, -48.23f, 862);
	v3c = 0.256f * v3a;
	v4a = Vector4(13.5f, -48.23f, 862, 0);
	v4c = 4.89f * v4a;

	UnitTester("Vector2 pre-scale", v2c, Vector2(33.5069999695f, -119.706863403f));
	UnitTester("Vector3 pre-scale", v3c, Vector3(3.45600008965f, -12.3468809128f, 220.672012329f));
	UnitTester("Vector4 pre-scale", v4c, Vector4(66.0149993896f, -235.844696045f, 4215.1796875f, 0));

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

	UnitTester_FLOAT("Vector2 Dot", Dot2, -124.937698364f, 0.0001f);
	UnitTester_FLOAT("Vector3 Dot", Dot3, -10468.9375f, 0.0001f);
	UnitTester_FLOAT("Vector4 Dot", Dot4, -10468.9375f, 0.0001f);

	// vector Cross product
	v3a = Vector3(13.5f, -48.23f, 862);
	v3b = Vector3(5, 3.99f, -12);
	v3c = v3a.Cross(v3b);
	v4a = Vector4(13.5f, -48.23f, 862, 0);
	v4b = Vector4(5, 3.99f, -12, 1);
	v4c = v4a.Cross(v4b);

	UnitTester("Vector3 Cross", v3c, Vector3(-2860.62011719f, 4472.00000000f, 295.01498413f));
	UnitTester("Vector4 Cross", v4c, Vector4(-2860.62011719f, 4472.00000000f, 295.01498413f, 0));

	// vector Magnitude
	v2a = Vector2(13.5f, -48.23f);
	float mag2 = v2a.Magnitude();
	v3a = Vector3(13.5f, -48.23f, 862);
	float mag3 = v3a.Magnitude();
	v4a = Vector4(13.5f, -48.23f, 862, 0);
	float mag4 = v4a.Magnitude();

	UnitTester_FLOAT("Vector2 Magnitude", mag2, 50.0837593079f, 0.0001f);
	UnitTester_FLOAT("Vector3 Magnitude", mag3, 863.453735352f, 0.0001f);
	UnitTester_FLOAT("Vector4 Magnitude", mag4, 863.453735352f, 0.0001f);

	// vector Normalize
	v2a = Vector2(-13.5f, -48.23f);
	v2a.Normalize();
	v3a = Vector3(13.5f, -48.23f, 862);
	v3a.Normalize();
	v4a = Vector4(243, -48.23f, 862, 0);
	v4a.Normalize();

	UnitTester("Vector2 Normalize", v2a, Vector2(-0.269548f, -0.962987f));
	UnitTester("Vector3 Normalize", v3a, Vector3(0.0156349f, -0.0558571f, 0.998316f));
	UnitTester("Vector4 Normalize", v4a, Vector4(0.270935f, -0.0537745f, 0.961094f, 0));

	auto a = Vector2(5, -10);
	auto b = a.PerpendicularClockwise();
	auto c = a.PerpendicularCounterClockwise();

	UnitTester("Vector2 Perpendicular Clockwise", Vector2(-10, -5), b);
	UnitTester("Vector2 Perpendicular Counter Clockwise", Vector2(10, 5), c);

	auto a1 = Vector2(1, 0);
	auto b1 = Vector2(0, 1);

	//THIS ALSO UnitTesterS RADIANS TO DEGREES!
	UnitTester_FLOAT("Vector2 Angle Between degrees 1", a1.AngleBetweenDegrees(b1), -45.0f, 0.0001f);
	UnitTester_FLOAT("Vector2 Angle Between degrees 2", b1.AngleBetweenDegrees(a1), 135.0f, 0.0001f);
	
	//According to google it is 0.785398163 but we are not using doubles.
	UnitTester_FLOAT("Vector2 Angle Between radians 1", a1.AngleBetweenRadians(b1), -0.785398f, 0.0001f);
	UnitTester_FLOAT("Vector2 Angle Between radians 2", b1.AngleBetweenRadians(a1), 2.35619f, 0.0001f);

	auto a2 = Vector2(10, -10);
	a2.SetScale(25);

	UnitTester("Vector2 set scale", a2, Vector2(250, -250));
	UnitTester("Vector2 get scale", a2.GetScale(10), Vector2(2500, -2500));

	// matrix rotation
	Matrix3 m3a, m3b, m3c, m3d;
	Matrix4 m4a, m4b, m4c, m4d;
	m3a.SetRotateX(3.98f);
	m4a.SetRotateX(4.5f);
	m3b.SetRotateY(1.76f);
	m4b.SetRotateY(-2.6f);
	m3c.SetRotateZ(9.62f);
	m4c.SetRotateZ(0.72f);

	UnitTester("Matrix3 set rotate", m3a, Matrix3(1, 0, 0, 0, -0.668648f, -0.743579f, 0, 0.743579f, -0.668648f));
	UnitTester("Matrix3 set rotate", m3b, Matrix3(-0.188077f, 0, -0.982154f, 0, 1, 0, 0.982154f, 0, -0.188077f));
	UnitTester("Matrix3 set rotate", m3c, Matrix3(-0.981005f, -0.193984f, 0, 0.193984f, -0.981005f, 0, 0, 0, 1));
	UnitTester("Matrix4 set rotate", m4a, Matrix4(1, 0, 0, 0, 0, -0.210796f, -0.97753f, 0, 0, 0.97753f, -0.210796f, 0, 0, 0, 0, 1));
	UnitTester("Matrix4 set rotate", m4b, Matrix4(-0.856889f, 0, 0.515501f, 0, 0, 1, 0, 0, -0.515501f, 0, -0.856889f, 0, 0, 0, 0, 1));
	UnitTester("Matrix4 set rotate", m4c, Matrix4(0.751806f, 0.659385f, 0, 0, -0.659385f, 0.751806f, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1));
	
	// vector transform
	v2a = Vector2(13.5f, -48.23f);
	v3a = Vector3(13.5f, -48.23f, 862);
	v3b = m3b * v3a;
	v3c = m3c * v3a;
	v4a = Vector4(13.5f, -48.23f, 862, 0);
	v4b = m4b * v4a;
	v4c = m4c * v4a;

	Matrix3 id3;
	id3.SetIdentity();

	Vector3 id3test = id3 * Vector3{ 4,7,3 };
	
	Matrix4 AHHHHHHHHH;
	AHHHHHHHHH.SetIdentity();
	Vector4 AHHHHHHHHH1 = AHHHHHHHHH * Vector4(4, 7, 5, 3);
	assert("PAIN", AHHHHHHHHH1, Vector4(4, 7, 5, 3));

	UnitTester("Vector3 matrix transform A", id3test, Vector3{ 4,7,3 });
	UnitTester("Vector3 matrix transform B", v3b, Vector3(-849.156f, -48.23f, -148.863f));
	UnitTester("Vector3 matrix transform C", v3c, Vector3(-22.5994224548f, 44.6950683594f, 862));
	UnitTester("Vector4 matrix transform PAIN", AHHHHHHHHH1, Vector4(4, 7, 5, 3));
	UnitTester("Vector4 matrix transform A", v4b, Vector4(432.794f, -48.23f, -745.597f, -8.88274e+10));
	UnitTester("Vector4 matrix transform B", v4c, Vector4(41.9515f, -27.3579f, 862, 0.0f));

	// matrix multiply
	m3d = m3a * m3c;
	m4d = m4c * m4b;

	UnitTester("Matrix3 multiply", m3d, Matrix3(-0.981004655361f, 0.129707172513f, 0.14424264431f, 0.193984255195f, 0.655946731567f, 0.729454636574f, 0, 0.743579149246f, -0.668647944927f));
	UnitTester("Matrix4 multiply", m4d, Matrix4(-0.644213855267f, -0.565019249916f, 0.515501439571f, 0, -0.659384667873f, 0.751805722713f, 0, 0, -0.387556940317f, -0.339913755655f, -0.856888711452f, 0, 0, 0, 0, 1));

	// homogeneous point translation
	m3b = Matrix3(1, 0, 0,
		0, 1, 0,
		0, 0, 1);
	m3b.zAxis = Vector3(55, 44, 1);
	m3c.SetRotateZ(2.2f);
	m3c.zAxis = Vector3(55, 44, 1);
	m4b = Matrix4(1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1);
	m4b.wAxis = Vector4(55, 44, 99, 1);
	m4c.SetRotateZ(2.2f);
	m4c.wAxis = Vector4(55, 44, 99, 1);

	v3a = Vector3(13.5f, -48.23f, 1);
	v3b = m3b * v3a;
	v3c = m3c * v3a;
	v4a = Vector4(13.5f, -48.23f, -54, 1);
	v4b = m4b * v4a;
	v4c = m4c * v4a;

	UnitTester("Vector3 matrix translation A", v3b, Vector3(68.5f, -4.23f, 1));
	UnitTester("Vector3 matrix translation B", v3c, Vector3(86.0490112305f, 83.2981109619f, 1));
	UnitTester("Vector4 matrix translation A", v4b, Vector4(68.5f, -4.23f, 45, 1));
	UnitTester("Vector4 matrix translation B", v4c, Vector4(86.0490112305f, 83.2981109619f, 45, 1));

	// homogeneous vector translation
	m3b = Matrix3(1, 0, 0,
		0, 1, 0,
		0, 0, 1);
	m3b.zAxis = Vector3(55, 44, 1);
	m3c.SetRotateZ(2.2f);
	m3c.zAxis = Vector3(55, 44, 1);
	m4b = Matrix4(1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1);
	m4b.wAxis = Vector4(55, 44, 99, 1);
	m4c.SetRotateZ(2.2f);
	m4c.wAxis = Vector4(55, 44, 99, 1);

	v3a = Vector3(13.5f, -48.23f, 0);
	v3b = m3b * v3a;
	v3c = m3c * v3a;
	v4a = Vector4(13.5f, -48.23f, -54, 0);
	v4b = m4b * v4a;
	v4c = m4c * v4a;

	UnitTester("Vector3 matrix translation C", v3b, Vector3(13.5f, -48.23f, 0));
	UnitTester("Vector3 matrix translation D", v3c, Vector3(31.0490131378f, 39.2981109619f, 0));
	UnitTester("Vector4 matrix translation C", v4b, Vector4(13.5f, -48.23f, -54, 0));
	UnitTester("Vector4 matrix translation D", v4c, Vector4(31.0490131378f, 39.2981109619f, -54, 0));

	std::cout << "\n\nIf nothing above failed then additionaly: Length, Length Squared, Squareroot,\nPrint, Set, Distance, Distance Squared, Zero, One, Five, Fifty and All operatorsdid not fail for vectors!";

	std::cout << "\n\n\nSomehow stuff didn't break, that's pretty neat!\n\n\n";
	system("pause");
	return 1;
}