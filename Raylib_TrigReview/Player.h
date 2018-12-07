#pragma once

#include "utils.h"
#include "raylib.h"

class Player
{
public:
	MathX::Vector2 Pos;

	void Draw()
	{
		DrawCircle(GetMouseX(), GetMouseY(), 15, RED);
	};
};