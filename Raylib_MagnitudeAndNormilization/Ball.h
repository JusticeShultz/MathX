#pragma once
#include "utils.h"
#include "raylib.h"

class Ball
{
public:
	MathX::Vector2 Position = MathX::Vector2{ (float)GetScreenWidth() / 2, (float)GetScreenHeight() / 2 }, Velocity;
	void Draw();
};

void Ball::Draw()
{
	Position += Velocity * 5 * GetFrameTime();

	if (Position.X >= GetScreenWidth())
	{
		MathX::Vector2 temp = Velocity;
		Velocity.X = -temp.X;
		Velocity.Y = temp.Y;
	}

	if (Position.Y >= GetScreenHeight())
	{
		MathX::Vector2 temp = Velocity;
		Velocity.X = temp.X;
		Velocity.Y = -temp.Y;
	}

	if (Position.Y <= 0)
	{
		MathX::Vector2 temp = Velocity;
		Velocity.X = temp.X;
		Velocity.Y = -temp.Y;
	}

	if (Position.X <= 0)
	{
		MathX::Vector2 temp = Velocity;
		Velocity.X = -temp.X;
		Velocity.Y = temp.Y;
	}

	DrawCircle(Position.X, Position.Y, 10, RED);
}