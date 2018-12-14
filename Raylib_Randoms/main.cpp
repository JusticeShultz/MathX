#include "raylib.h"
#include "utils.h"
#include <iostream>
#include <vector>

int main()
{
	std::cout << "NOTE: This program will add as many positionals as your memory allows for so it is not recommended that you leave the program running or it will overflow." << std::endl;

	int frame = 60;
	int screenWidth = 800;
	int screenHeight = 500;
	InitWindow(screenWidth, screenHeight, "Randomization Example - MathX Custom Math Library");
	SetTargetFPS(5000);
	MathX::Random randNum;
	randNum.setRandSeed();

	//Checking to make sure stuff works as intended:
	std::cout << randNum.rand(10, 24) << std::endl;
	std::cout << randNum.rand(10, 24) << std::endl;
	std::cout << randNum.rand(10, 24) << std::endl;
	std::cout << randNum.randDecimal((double)10, (double)24) << std::endl;
	std::cout << randNum.randDecimal((double)10, (double)24) << std::endl;
	std::cout << randNum.randDecimal((double)10, (double)24) << std::endl;

	//Curves for fun:
	std::vector<MathX::Vector2> points;
	// create a series of points in our spline 
	points.push_back({ 200 + 50, 100 });
	points.push_back({ 200 + 350, 100 });

	MathX::Vector2 Position;
	MathX::Vector2 TravelTo;
	Position = 250;
	TravelTo = 0;

	MathX::Vector2 last = MathX::CatmullRomSpline(points.data(), points.size(), 0);

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(RAYWHITE);

		++frame;

		MathX::Vector2 last = MathX::CatmullRomSpline(points.data(), points.size(), 0);

		for (int i = 1; i < 500; ++i)
		{
			MathX::Vector2 curr = MathX::CatmullRomSpline(points.data(), points.size(), i / 50.0f);

			DrawLine(last.X, last.Y, curr.X, curr.Y, GRAY);

			last = curr;
		}

		if (frame >= 180)
		{
			frame = 0;
			points.push_back(new MathX::Vector2);
			points.back() = Position;
			TravelTo.X = randNum.rand(0, GetScreenWidth());
			TravelTo.Y = randNum.rand(0, GetScreenHeight());
			std::cout << "1 second past, new position: " <<TravelTo.X << ", " << TravelTo.Y << std::endl;
		}

		DrawCircle(Position.X, Position.Y, 25, RED);

		Position = MathX::Lerp(Position, TravelTo, 0.01f);

		EndDrawing();
	}

	CloseWindow();

	return 0;
}