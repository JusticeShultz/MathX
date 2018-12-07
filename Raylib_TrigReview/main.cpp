#include "raylib.h"
#include "utils.h"
#include "Player.h"
#include "Orbital.h"
#include <vector>

int main()
{
	srand(time(NULL));
	int screenWidth = 800;
	int screenHeight = 450;
	InitWindow(screenWidth, screenHeight, "Tig Game Example - MathX Custom Math Library");
	SetTargetFPS(60);

	Player Player1;
	typedef std::vector<Object> alotOfObjects;
	alotOfObjects bagOfOrbitals(80);

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(RAYWHITE);
		Player1.Draw();

		DrawFPS(25, 25);

		for (int i = 0; i < bagOfOrbitals.size(); ++i)
		{
			bagOfOrbitals[i].Draw(MathX::Vector2(GetMouseX(), GetMouseY()));
		}

		EndDrawing();
	}

	CloseWindow();

	return 0;
}