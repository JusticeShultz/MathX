#include "Ball.h"

int main()
{
	int screenWidth = 800;
	int screenHeight = 500;
	InitWindow(screenWidth, screenHeight, "Ball Game Example - MathX Custom Math Library");
	Ball MainBall, Ball2, Ball3, Ball4, Ball5;
	MainBall.Velocity = MathX::Vector2{ 150, 50 };
	Ball2.Velocity = MathX::Vector2{ -150, 50 };
	Ball3.Velocity = MathX::Vector2{ 55, -80 };
	Ball4.Velocity = MathX::Vector2{ -120, -150 };
	Ball5.Velocity = MathX::Vector2{ -80, -78 };

	SetTargetFPS(60);

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(RAYWHITE);

		MathX::Vector2 center = MathX::Vector2(GetMouseX(), GetMouseY());
		DrawText(FormatText("Distance from center to ball: %f", MainBall.Position.Distance(center)), 100, 100, 20, BLACK);
		DrawLine(center.X, center.Y, MainBall.Position.X, MainBall.Position.Y, RED);
		DrawCircleLines(center.X, center.Y, 15, RED);
		MainBall.Draw();
		Ball2.Draw();
		Ball3.Draw();
		Ball4.Draw();
		Ball5.Draw();

		EndDrawing();
	}

	CloseWindow();

	return 0;
}