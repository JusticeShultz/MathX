#pragma once
#include "raylib.h"
#include "utils.h"
#include <stdlib.h>

class Particle
{
public:
	float Rotation, 
	      Spin,
		  Scale,
		  Lifetime;

	bool Alive;
	MathX::Color ConversionColor = MathX::Color(255, 0, 0, 100);
	MathX::Vector2 Position, Velocity;

	Texture2D Sprite = LoadTexture("Heart.png");

	void Update(MathX::Vector2 Offset)
	{
		if (Alive)
		{
			//Raylib has no operators so a temp color was used.
			ConversionColor = MathX::lerp(ConversionColor.A, 0, 0.01f + (Lifetime * 0.01));
			Color temp;
			temp.r = (const char)255;
			temp.g = (const char)0;
			temp.b = (const char)0;
			temp.a = (const char)ConversionColor.A;

			Vector2 IDontLikeOverloads;
			IDontLikeOverloads.x = Position.X;
			IDontLikeOverloads.y = Position.Y;
			Rotation += Spin;
			DrawTextureEx(Sprite, IDontLikeOverloads, Rotation, Scale * 0.4, temp);

			Position += Velocity;
			
			if (ConversionColor.A <= 0) Alive = false;
		}
	};

	void Revive(float rotation, float spin, float scale, MathX::Color tint, MathX::Vector2 pos, MathX::Vector2 vel);

	Particle();
	Particle(float rotation, float spin, float scale, MathX::Color tint, MathX::Vector2 pos, MathX::Vector2 vel);
	~Particle();
};

Particle::Particle()
{

}

Particle::Particle(float rotation, float spin, float scale, MathX::Color tint, MathX::Vector2 pos, MathX::Vector2 vel)
{
	Rotation = rotation;
	Spin = spin;
	Scale = scale;
	ConversionColor = MathX::Color(255, 0, 0, 100);
	Position = pos;
	Velocity = vel;
	
	Alive = true;
	Lifetime = (rand() % 30 + 1) / 10 + 1;
}

void Particle::Revive(float rotation, float spin, float scale, MathX::Color tint, MathX::Vector2 pos, MathX::Vector2 vel)
{
	Rotation = rotation;
	Spin = spin;
	Scale = scale;
	ConversionColor = MathX::Color(255, 0, 0, 100);
	Position = pos;
	Velocity = vel;
	Alive = true;
	Lifetime = (rand() % 30 + 1) / 10 + 1;
}

Particle::~Particle()
{
	UnloadTexture(Sprite);
}