#pragma once
#include "MathX.h"
#include "raylib.h"
#include "ParticleSystem.h"
#include <vector>
#include <stdlib.h>

class Follower
{
public:
	MathX::Vector2 Position;
	MathX::Vector2 Destination;
	float Health, DisplayedHealth;
	std::vector<Particle*> Particles;

	void Draw()
	{
		DisplayedHealth = MathX::Lerp(DisplayedHealth, Health, 0.03f);

		Health = MathX::Clamp((int)Health, 0, 100);
		Position = MathX::Lerp(Position, Destination, 0.05f);
		DrawCircle(Position.X, Position.Y, 25, RED);
		DrawLine(Position.X, Position.Y, Destination.X, Destination.Y, GREEN);
		
		float PosX = MathX::Clamp((float)Position.X - 125, (float)0, (float)GetScreenWidth() - 250);
		float PosY = MathX::Clamp((float)Position.Y - 65, (float)0, (float)GetScreenHeight() - 25);

		DrawRectangle(PosX, PosY, 250, 25, RED);

			DrawRectangle(PosX, PosY, 250 * (DisplayedHealth / 100), 25, GREEN);
			
		for (int i = 0; i < Particles.size(); ++i)
		{
			if (!Particles[i]->Alive)
			{
				Particles[i]->Revive(0, (rand() % 5 + 1), (rand() % 3 + 0.1), MathX::Color(255, 0, 0, 255), Position,
											MathX::Vector2((rand() % 8 + -4), (rand() % 8 + -4)));
			}

			Particles[i]->Update(Position);
		}
	};

	Follower();
	~Follower();
};

Follower::Follower()
{
	DisplayedHealth = 0;

	//Preprocessor loading, add 10,000 if you'd like.
	for (int i = 0; i < 100; ++i)
	{
		Particles.push_back(new Particle);
		Particles.back()->Revive(0, (rand() % 5 + 1), ((rand() % 3 * 0.15) + 0.1), MathX::Color(255, 0, 0, 255), Position,
									 MathX::Vector2((rand() % 8 + -4) + Position.X, (rand() % 8 + -4) + Position.Y));
	}
}

Follower::~Follower() { }