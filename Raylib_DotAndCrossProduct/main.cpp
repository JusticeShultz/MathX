#include "raylib.h"
#include "MathX.h"
#include "Enemy.h"
#include "Player.h"

int main()
{
	top:

	while (true)
	{
		int screenWidth = 800;
		int screenHeight = 450;
		InitWindow(screenWidth, screenHeight, "Assassin Game Example - MathX Custom Math Library");
		SetTargetFPS(60);


		Enemy Entity1;
		Player Player1;
		bool Caught = false;

		while (!WindowShouldClose())
		{
			BeginDrawing();
			ClearBackground(BLACK);

			if (Caught)
			{
				Entity1.Update();
				DrawText("You were caught!\n\nPress R to retry!", 150, 80, 55, SKYBLUE);
			}
			else
			{
				if (Entity1.Alive == false)
				{
					Player1.Update(Entity1.Translation, Entity1.Alive);
					DrawText("You stabbed the guard!\n\n     Press R to retry!", 50, 80, 55, SKYBLUE);
				}
				else
				{
					int z = Player1.Update(Entity1.Translation, Entity1.Alive);

					if (z == 1) Entity1.Alive = false;
					if (z == -1) Caught = true;

					Entity1.Update();
				}
			}

			if (IsKeyPressed(KEY_R) || IsMouseButtonPressed(MOUSE_MIDDLE_BUTTON)) goto top;

			EndDrawing();
		}

		while (WindowShouldClose()) goto end;
	}

	end:
	CloseWindow();
	return 0;
}