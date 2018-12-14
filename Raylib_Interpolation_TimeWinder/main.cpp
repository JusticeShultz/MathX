#include "raylib.h"
#include "Player.h"

int main()
{
	int screenWidth = 800;
	int screenHeight = 500, frames = 500;
	InitWindow(screenWidth, screenHeight, "Interpolation Time Reversal Example - MathX Custom Math Library");
	Player you;
	you.Position = MathX::Vector2(GetScreenWidth() * 0.5, GetScreenHeight() * 0.5);
	SetTargetFPS(60);

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(RAYWHITE);
		you.Draw();

		DrawText("WASD to move", 25, 25, 40, RED);
		DrawText("Shift to reverse time", 25, 65, 40, RED);
		EndDrawing();
	}

	CloseWindow();

	return 0;
}