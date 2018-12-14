#pragma once
#include "utils.h"
#include "raylib.h"
#include <vector>

class Player
{
public:
	MathX::Vector2 Position;
	std::vector<MathX::Vector2> Positions;

	void Draw()
	{
		DrawCircle(Position.X, Position.Y, 25, RED);

		if (IsKeyDown(KEY_W))
			Position.Y -= 3;
		if (IsKeyDown(KEY_S))
			Position.Y += 3;
		if (IsKeyDown(KEY_D))
			Position.X += 3;
		if (IsKeyDown(KEY_A))
			Position.X -= 3;

		if (IsKeyDown(KEY_LEFT_SHIFT))
		{
			if (Positions.size() > 0)
			{
				Positions.pop_back();

				if (Positions.size() > 0)
					Position = Positions.back();
			}
		}
		else
		{
			Positions.push_back(new MathX::Vector2);
			Positions.back() = Position;
		}
	}
};