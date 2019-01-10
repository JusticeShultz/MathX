#include "EngineExtras.h"
#include "Sprite.h"

void main()
{
	int screenWidth = 800;
	int screenHeight = 450;
	InitWindow(screenWidth, screenHeight, "Tank Matrices - MathX Custom Math Library");
	SetTargetFPS(60);

	//Everything is a child of this object---------------------------------------------------------------------------------//
	MathX::Object2D Space("Space");
	//Mark that we are standalone. (This is a neat feature that lets us use a dynamic find something by name feature)
	Space.Attach(nullptr);
	//---------------------------------------------------------------------------------------------------------------------//

	MathX::Object2D Player("Player", MathX::Vector2(screenWidth / 2, screenHeight / 2), MathX::Vector3(0, 0, 0), MathX::Vector2(1, 1), &Space);
	MathX::Object2D Turret("Turret", MathX::Vector2(0, 0), MathX::Vector3(0, 0, 0), MathX::Vector2(1, 1), &Player);
	Sprite PlayerSprite;
	Sprite TurretSprite;

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(RAYWHITE);

		//Example of the hierarchies finding by name capability.
		PlayerSprite.RenderSprite(*Space.FindChildByName("Player"));
		PlayerSprite.RenderSprite(*Space.FindChildByName("Player")->FindChildByName("Turret"));

		EndDrawing();
	}

	CloseWindow();

	return;
}