#pragma once
#include "MathX.h"
#include "raylib.h"

class Popper
{
public:
	MathX::Vector2 Position;
	int inFor = 0;

	void Update()
	{
		++inFor;

		if (inFor > 250)
		{
			//Left side.
			if (Position.X < GetScreenWidth() * 0.5)
				Position.X = MathX::Lerp(Position.X, -100.0f, 0.02f);
			//Right side.
			if (Position.X > GetScreenWidth() * 0.5)
				Position.X = MathX::Lerp(Position.X, GetScreenWidth() + 100.0f, 0.02f);
		}
		else
		{
			//Left side.
			if (Position.X < 50)
				Position.X = MathX::Lerp(Position.X, 40.0f, 0.01f);
			//Right side.
			if (Position.X > 350)
				Position.X = MathX::Lerp(Position.X, GetScreenWidth() - 40.0f, 0.01f);
		}

		DrawCircle(Position.X, Position.Y, 40, BLUE);

		if (CheckCollisionPointCircle(GetMousePosition(), Vector2{ Position.X, Position.Y }, 40))
		{
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
			{
				inFor = 300;
			}
		}
	}
};