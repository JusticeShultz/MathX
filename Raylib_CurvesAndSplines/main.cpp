#include "raylib.h"
#include "utils.h"
#include <vector>

int main()
{
	int screenWidth = 1000;
	int screenHeight = 850;
	InitWindow(screenWidth, screenHeight, "Bezier / Catmull-Rom Spline Example - MathX Custom Math Library");
	SetTargetFPS(60);
	std::vector<MathX::Vector2> points; 
	// create a series of points in our spline 
	points.push_back({ 200 + 50, 100 }); 
	points.push_back({ 200 + 350, 100 }); 
	points.push_back({ 200 + 75, 300 }); 
	points.push_back({ 200 + 625, 300 }); 
	points.push_back({ 200 + 450, 500 });
	//points.push_back({ 200 + 100, 570 });
	//points.push_back({ 200 + 400, 600 });
	//points.push_back({ 200 + 200, 700 });
	//points.push_back({ 200 + 600, 800 });
	
	// last needed to store previous interpolated position 
	MathX::Vector2 last = MathX::catmullRomSpline(points.data(), points.size(), 0);
	MathX::Vector2 Position = MathX::Vector2(GetScreenWidth() * 0.5, GetScreenHeight() * 0.5);

	int QQ = 1;
	MathX::Vector2 pos_last = MathX::catmullRomSpline(points.data(), points.size(), 0);

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(BLACK);

		MathX::Vector2 last = MathX::catmullRomSpline(points.data(), points.size(), 0);

		// loop and create a smooth spline with 50 segments, skip first point 
		for (int i = 1; i < 250; ++i)
		{
			MathX::Vector2 curr = MathX::catmullRomSpline(points.data(), points.size(), i / 50.0f);

			DrawLine(last.X, last.Y, curr.X, curr.Y, GRAY);

			last = curr;
		}

		for (int i = 0; i < points.size(); ++i)
		{
			if (CheckCollisionPointCircle(GetMousePosition(), Vector2{ points[i].X, points[i].Y }, 15))
			{
				if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
				{
					DrawCircleLines(points[i].X, points[i].Y, 15, Yellow);
					points[i].X = GetMouseX();
					points[i].Y = GetMouseY();
				}
				else
					DrawCircleLines(points[i].X, points[i].Y, 15, Orange);
			}
			else
				DrawCircleLines(points[i].X, points[i].Y, 15, WHITE);
		}
		
		MathX::Vector2 pos_curr = MathX::catmullRomSpline(points.data(), points.size(), QQ / 50.0f);
		
		if (Position.Distance(pos_curr) < 0.1)
		{
			pos_last = pos_curr;

			++QQ;
			
			if (QQ > 51) QQ = 0;
		}

		Position = MathX::lerp(Position, pos_curr, 1.05f);

		DrawCircle(Position.X, Position.Y, 15, RAYWHITE);
		EndDrawing();
	}

	CloseWindow();
	return 0;
}