#include "utils.h"
#include <cassert>
#include <iostream>

using namespace MathX;

int main()
{
	// vector addition
	Vector2 v2a(13.5f, -48.23f), v2b(5, 3.99f), v2c;
	v2c = v2a + v2b;
	Vector3 v3a(13.5f, -48.23f, 862), v3b(5, 3.99f, -12), v3c;
	v3c = v3a + v3b;
	Vector4 v4a(13.5f, -48.23f, 862, 0), v4b(5, 3.99f, -12, 1), v4c;
	v4c = v4a + v4b;

	assert("Vector2 addition", v2c, Vector2(18.5f, -44.24f));
	assert("Vector3 addition", v3c, Vector3(18.5f, -44.24f, 850));
	assert("Vector4 addition", v4c, Vector4(18.5f, -44.24f, 850, 1));

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

	assert("Vector2 subtraction", v2c, Vector2(8.5f, -52.22f));
	assert("Vector3 subtraction", v3c, Vector3(8.5f, -52.22f, 874));
	assert("Vector4 subtraction", v4c, Vector4(8.5f, -52.22f, 874, -1));

	// vector post-scale
	v2a = Vector2(13.5f, -48.23f);
	v2c = v2a * 2.482f;
	v3a = Vector3(13.5f, -48.23f, 862);
	v3c = v3a * 0.256f;
	v4a = Vector4(13.5f, -48.23f, 862, 0);
	v4c = v4a * 4.89f;

	assert("Vector2 post-scale", v2c, Vector2(33.5069999695f, -119.706863403f));
	assert("Vector3 post-scale", v3c, Vector3(3.45600008965f, -12.3468809128f, 220.672012329f));
	assert("Vector4 post-scale", v4c, Vector4(66.0149993896f, -235.844696045f, 4215.1796875f, 0));

	// vector pre-scale
	v2a = Vector2(13.5f, -48.23f);
	v2c = 2.482f * v2a;
	v3a = Vector3(13.5f, -48.23f, 862);
	v3c = 0.256f * v3a;
	v4a = Vector4(13.5f, -48.23f, 862, 0);
	v4c = 4.89f * v4a;

	assert("Vector2 pre-scale", v2c, Vector2(33.5069999695f, -119.706863403f));
	assert("Vector3 pre-scale", v3c, Vector3(3.45600008965f, -12.3468809128f, 220.672012329f));
	assert("Vector4 pre-scale", v4c, Vector4(66.0149993896f, -235.844696045f, 4215.1796875f, 0));

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

	assert("Vector2 Dot", Dot2, -124.937698364f);
	assert("Vector3 Dot", Dot3, -10468.9375f);
	assert("Vector4 Dot", Dot4, -10468.9375f);

	// vector Cross product
	v3a = Vector3(13.5f, -48.23f, 862);
	v3b = Vector3(5, 3.99f, -12);
	v3c = v3a.Cross(v3b);
	v4a = Vector4(13.5f, -48.23f, 862, 0);
	v4b = Vector4(5, 3.99f, -12, 1);
	v4c = v4a.Cross(v4b);

	assert("Vector3 Cross", v3c, Vector3(-2860.62011719f, 4472.00000000f, 295.01498413f));
	assert("Vector4 Cross", v4c, Vector4(-2860.62011719f, 4472.00000000f, 295.01498413f, 0));

	// vector Length
	v2a = Vector2(13.5f, -48.23f);
	float mag2 = v2a.Length();
	v3a = Vector3(13.5f, -48.23f, 862);
	float mag3 = v3a.Length();
	v4a = Vector4(13.5f, -48.23f, 862, 0);
	float mag4 = v4a.Length();

	assert("Vector2 Length", mag2, 50.0837593079f);
	assert("Vector3 Length", mag3, 863.453735352f);
	assert("Vector4 Length", mag4, 863.453735352f);

	// vector Normalize
	v2a = Vector2(-13.5f, -48.23f);
	v2a.Normalize();
	v3a = Vector3(13.5f, -48.23f, 862);
	v3a.Normalize();
	v4a = Vector4(243, -48.23f, 862, 0);
	v4a.Normalize();

	assert("Vector2 Normalize", v2a, Vector2(-0.269548f, -0.962987f));
	assert("Vector3 Normalize", v3a, Vector3(0.0156349f, -0.0558571f, 0.998316f));
	assert("Vector4 Normalize", v4a, Vector4(0.270935f, -0.0537745f, 0.961094f, 0));

	//Matrixes and color not included currently.

	std::cout << "Program calculated everything without errors!" << std::endl;
	system("pause");
	return true;
}