#include "raylib.h"
#include "utils.h"
//#include <cUnitTester>
#include "Sprite.h"

int main()
{
	int screenWidth = 800;
	int screenHeight = 450;
	InitWindow(screenWidth, screenHeight, "Tank Game Example - MathX Custom Math Library");

	SetTargetFPS(60);
	Sprite Tank;

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(RAYWHITE);
		Tank.Draw();
		EndDrawing();
	}

	CloseWindow();

	return 0;
}