#include "raylib.h"
#include "waypoint.h"
#include <vector>
#include "Follower.h"
#include <stdlib.h>
#include <time.h>
#include "Button.h"
#include "Popin.h"

int main()
{
	srand(time(NULL));

	int screenWidth = 800;
	int screenHeight = 500, frames = 500;
	InitWindow(screenWidth, screenHeight, "Interpolation Example - MathX Custom Math Library");
	std::vector<Waypoint*> WaypointQueue;
	Follower Followee;
	Followee.Health = 65;

	Button Clickable;
	Clickable.Position = MathX::Vector2(10, 15);
	Clickable.Tint1 = MathX::Sky_Blue;
	Clickable.Tint2 = MathX::Sky_Blue;
	Clickable.Tint3 = MathX::Violet;
	Clickable.Tint4 = MathX::Blue;
	Clickable.Tint5 = MathX::Dark_Gray;

	Button Clickable2;
	Clickable2.Position = MathX::Vector2(10, GetScreenHeight() - 70);
	Clickable2.Tint1 = MathX::Green;
	Clickable2.Tint2 = MathX::Green;
	Clickable2.Tint3 = MathX::Light_Green;
	Clickable2.Tint4 = MathX::Dark_Green;
	Clickable2.Tint5 = MathX::Dark_Gray;

	std::vector<Popper*> PopperStack;

	for (int i = 0; i < 10; ++i)
	{
		WaypointQueue.push_back(new Waypoint);
		WaypointQueue.back()->Point = MathX::Vector2(rand() % GetScreenWidth() + 1, rand() % GetScreenHeight() + 1);
	}

	SetTargetFPS(60);

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(RAYWHITE);

		bool result = Clickable.Draw();

		if (result)
			Followee.Health -= 1;

		bool result1 = Clickable2.Draw();

		if (result1)
			Followee.Health += 1;

		Followee.Destination = WaypointQueue.back()->Point;

		if (Followee.Position.Distance(WaypointQueue.back()->Point) < 4)
		{
			if (WaypointQueue.size() > 0)
			{
				WaypointQueue.pop_back();
			}

			if (WaypointQueue.size() <= 0)
			{
				//New set
				for (int i = 0; i < 10; ++i)
				{
					WaypointQueue.push_back(new Waypoint);
					WaypointQueue.back()->Point = MathX::Vector2(rand() % GetScreenWidth() + 1, rand() % GetScreenHeight() + 1);
				}
			}
		}

		for (int i = 0; i < WaypointQueue.size(); ++i)
		{
			WaypointQueue[i]->Debug();
		}

		Followee.Draw();

		++frames;

		if (frames > 350)
		{
			if (PopperStack.size() > 0) PopperStack.pop_back();

			frames = 0;
			PopperStack.push_back(new Popper);
			int b = rand() % 1 + 1;

			if (b == 1)
				PopperStack.back()->Position.X = GetScreenWidth() + 100;
			else PopperStack.back()->Position.X = -100;

			PopperStack.back()->Position.Y = rand() % GetScreenHeight();
		}

		for (int i = 0; i < PopperStack.size(); ++i)
			PopperStack[i]->Update();

		EndDrawing();
	}

	CloseWindow();

	return 0;
}