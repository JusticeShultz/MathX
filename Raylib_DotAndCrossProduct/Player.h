#pragma once
#include "utils.h"
#include "raylib.h"
#include <iostream>

typedef MathX::Vector2 V2;

class Player
{
public:
	V2 Position = V2(150, 150);
	
	int Update(V2 pos1, int a);
};

int Player::Update(V2 pos1, int a)
{
	DrawCircle(Position.X, Position.Y, 15, GREEN);

	if (IsKeyDown(KEY_W) || IsMouseButtonDown(MOUSE_RIGHT_BUTTON))
	{
		Position.X = MathX::MoveTowards((float)Position.X, (float)GetMouseX(), (float)2);
		Position.Y = MathX::MoveTowards((float)Position.Y, (float)GetMouseY(), (float)2);
	}

	if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
	{
		DrawCircle(MathX::MoveTowards((float)Position.X, (float)GetMouseX(), (float)10), MathX::MoveTowards((float)Position.Y, (float)GetMouseY(), (float)10), 8, RED);

		float distance = Position.Distance(pos1);
		
		//std::cout << distance << std::endl;

		//We can probably reach at this point:
		if (distance < 55)
		{
			//Are we behind them?
			if (Position.X < pos1.X && Position.Y > pos1.Y)
			{
				return 1;
			}
		}
	}
	
	if (Position.X > pos1.X && Position.Y < pos1.Y) return -1;
	else
	return 0;
}