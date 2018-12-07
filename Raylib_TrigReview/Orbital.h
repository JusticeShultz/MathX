#pragma once
#include "utils.h"
#include "raylib.h"
#include <cmath>
#include <time.h>
#include <stdlib.h>

class Object
{
public:
	float Radius = 125;
	float Angle = rand() % 359 + 1;;

	MathX::Vector2 Pos;

	void Draw(MathX::Vector2 pos);
	
	Object();
	~Object();
};

void Object::Draw(MathX::Vector2 pos)
{
	Angle += 0.1;
	if (Angle > 360) Angle = 0;
	DrawCircle(pos.X + (cos(Angle) * Radius), pos.Y + (sin(Angle) * Radius), 15, RED);
}

Object::Object()
{

}

Object::~Object()
{

}