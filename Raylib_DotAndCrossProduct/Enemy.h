#pragma once
#include "utils.h"

typedef MathX::Vector2 V2;

class Enemy
{
public:
	MathX::Vector2 Translation, Velocity, StartingLookNode;
	
	Enemy();
	~Enemy();

	bool Alive = true;
	void Update();
};

void Enemy::Update()
{
	if (Alive)
	{
		DrawCircle(Translation.X, Translation.Y, 20, RED);

		//Although extremely costly it renders the light the way I want - layered in 100 sections to go above and below the player.
		for (int i = 0; i < 10; ++i)
		{
			V2 VectorCalculation = { StartingLookNode.X - Translation.X, StartingLookNode.Y - Translation.Y };
			float normalMouse = MathX::Sqrt(VectorCalculation.X * VectorCalculation.X + VectorCalculation.Y * VectorCalculation.Y);

			VectorCalculation.X = VectorCalculation.X / normalMouse;
			VectorCalculation.Y = VectorCalculation.Y / normalMouse;

			V2 calcc;
			calcc.X = Translation.X + VectorCalculation.X * 1000;
			calcc.Y = Translation.Y + VectorCalculation.Y * 1000;

			V2 offset1 = V2(MathX::MoveTowards((float)Translation.X, (float)calcc.X, (float)12), MathX::MoveTowards((float)Translation.Y, (float)calcc.Y, (float)12));

			for (int i = 0; i < 650; ++i)
				DrawLine(offset1.X, offset1.Y, calcc.X + i * 1.5, calcc.Y + i * 1.5, Color{ 255, 203, 50, 1 });
		}
	}
}

Enemy::Enemy()
{
	Alive = true;
	StartingLookNode = V2(350, -350);//V2(GetScreenWidth()/2, GetScreenHeight()/2);
	Translation = 350;
	Velocity = 0;
}

Enemy::~Enemy()
{
}