#pragma once
#include "raylib.h"
#include "utils.h"
#include <cmath>

class Sprite
{
public:
	Texture2D SpriteSource;
	Color VertexColor;
	MathX::Vector2 Pos, FirePoint, Direction;
	float Rotation, Scale;

	Sprite();
	void Draw();
	~Sprite();
};

Sprite::Sprite()
{
	VertexColor = SKYBLUE;
	Rotation = 0;
	Scale = 0.5;
	Pos = MathX::Vector2{ 250, 250 };
	FirePoint = 0;
	Direction = 0;
	SpriteSource = LoadTexture("Sprites/Tank.png");
}

void Sprite::Draw()
{
	Rectangle Rec1 = Rectangle{ (float)Pos.X, (float)Pos.Y, (float)SpriteSource.width * Scale, (float)SpriteSource.height * Scale };
	Rectangle SourceRec = Rectangle{ 0.0f, 0.0f, (float)SpriteSource.width, (float)SpriteSource.height };

	if (Rotation > 360) Rotation = 0;
	if (Rotation < 0) Rotation = 360;

	MathX::Vector2 mouseVec = MathX::Vector2{ (float)GetMouseX(), (float)GetMouseY() };

	//Distance formula.
	MathX::Vector2 VectorCalculation = { mouseVec.X - Pos.X, mouseVec.Y - Pos.Y };
	float normalMouse = sqrt(VectorCalculation.X * VectorCalculation.X + VectorCalculation.Y * VectorCalculation.Y);
	VectorCalculation.X = VectorCalculation.X / normalMouse;
	VectorCalculation.Y = VectorCalculation.Y / normalMouse;
	Rotation = atan2(VectorCalculation.Y, VectorCalculation.X) * RAD2DEG;
	Direction = VectorCalculation;

	if ((IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)) && (abs(normalMouse) > 5))
	{
		Pos += Direction * 5;
	}
	else
	if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S))
	{
		Pos -= Direction * 5;
	}

	DrawTexturePro(SpriteSource, SourceRec, Rec1, Vector2{ Rec1.width / 2, Rec1.height / 2 }, Rotation, VertexColor);
}

Sprite::~Sprite()
{
	UnloadTexture(SpriteSource);
}