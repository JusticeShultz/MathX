#pragma once
#include "raylib.h"
#include "EngineExtras.h"

class Shot
{
public:
	MathX::Vector2 Position;
	MathX::Vector2 Velocity;

	void Update()
	{
		Position += Velocity;
		DrawCircleV(::Vector2{Position.X, Position.Y}, 3, BLACK);
	};
};