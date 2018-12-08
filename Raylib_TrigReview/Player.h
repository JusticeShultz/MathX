#pragma once
#include "utils.h"
#include "raylib.h"
#include "Orbital.h"
#include <vector>

class Player
{
public:
	MathX::Vector2 Pos, Offset;
	typedef std::vector<Object *> alotOfObjects;
	alotOfObjects bagOfOrbitals;

	void Draw()
	{
		for (int i = 0; i < bagOfOrbitals.size(); ++i)
			bagOfOrbitals[i]->Draw(MathX::Vector2(GetMouseX() + Offset.X, GetMouseY() + Offset.Y));

		DrawCircle(GetMouseX() + Offset.X, GetMouseY() + Offset.Y, 15, GREEN);
	};

	Player();
	~Player();
};

Player::Player()
{
	for(int i = 0; i < 50; ++i)
		bagOfOrbitals.push_back(new Object);
}

Player::~Player()
{

}