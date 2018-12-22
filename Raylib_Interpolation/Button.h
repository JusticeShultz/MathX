#pragma once
#include "MathX.h"
#include "raylib.h"

enum ButtonState { Idle, Hovered, Clicked, Disabled };

class Button
{
public:
	MathX::Color Tint1, Tint2, Tint3, Tint4, Tint5;
	MathX::Vector2 Position;
	ButtonState State;
	bool Active;

	bool Draw()
	{
		if(State != Clicked) DrawRectangle(Position.X, Position.Y, 260, 60, Color{ (unsigned char)Tint1.R, (unsigned char)Tint1.G, (unsigned char)Tint1.B, 100 });
		DrawRectangle(Position.X, Position.Y, 250, 50, Color{ (unsigned char)Tint1.R, (unsigned char)Tint1.G, (unsigned char)Tint1.B, (unsigned char)Tint1.A });

		if (State == Idle) Tint1 = MathX::Lerp(Tint1, Tint2, 0.025);
		if (State == Hovered) Tint1 = MathX::Lerp(Tint1, Tint3, 0.025);
		if (State == Clicked) Tint1 = MathX::Lerp(Tint1, Tint4, 0.025);
		if (State == Disabled) Tint1 = MathX::Lerp(Tint1, Tint5, 0.025);
		
		if (Active)
		{
			Rectangle Me;
			Me.x = Position.X;
			Me.y = Position.Y;
			Me.width = 250;
			Me.height = 50;

			if (CheckCollisionPointRec(GetMousePosition(), Me))
			{
				if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
				{
					State = Clicked;
					return true;
				}
				else State = Hovered;
			}
			else State = Idle;
		}
		else State = Disabled;

		return false;
	}
};