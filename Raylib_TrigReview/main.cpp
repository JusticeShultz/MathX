#include "raylib.h"
#include "utils.h"
#include "Player.h"

int main()
{
	srand(time(NULL));
	int screenWidth = 8000;
	int screenHeight = 1060;
	InitWindow(screenWidth, screenHeight, "Trig Game Example - MathX Custom Math Library");
	SetTargetFPS(61);

	Player Player1, Player2, Player3, Player4, Player5;
	Player1.Offset = 0;
	Player2.Offset = MathX::Vector2(-250, 250);
	Player3.Offset = MathX::Vector2(250, -250);
	Player4.Offset = MathX::Vector2(-250, -250);
	Player5.Offset = MathX::Vector2(250, 250);

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(BLACK);

		Player1.Draw();
		Player2.Draw();
		Player3.Draw();
		Player4.Draw();
		Player5.Draw();
		
		DrawFPS(25, 25);

		EndDrawing();
	}

	CloseWindow();

	return 0;
}