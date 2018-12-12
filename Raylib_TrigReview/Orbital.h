#pragma once
#include "utils.h"
#include "raylib.h"
#include <cmath>
#include <time.h>
#include <stdlib.h>

class Object
{
public:
	MathX::Vector2 Pos;
	float Radius = 125;
	float Angle = rand() % 359 + 1;;
	bool check = false;

	void Draw(MathX::Vector2 pos);
	
	Object();
	~Object();
};

void Object::Draw(MathX::Vector2 pos)
{
	if (check) { Radius += 8; if (Radius > 600) check = !check; }
	else { Radius -= 8; if (Radius < 20) check = !check; }
	Angle += 0.1; if (Angle > 360) Angle = 0; DrawCircle(pos.X + (cos(Angle) * Radius), pos.Y + (sin(Angle) * Radius), 15, DARKGREEN);
}

Object::Object() { }
Object::~Object() { }