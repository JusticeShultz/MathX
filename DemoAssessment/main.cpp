#include "EngineExtras.h"
#include "Sprite.h"
#include "Bullet.h"

void main()
{
	int screenWidth = 1250;
	int screenHeight = 900;
	InitWindow(screenWidth, screenHeight, "Tank Matrices - MathX Custom Math Library");
	SetTargetFPS(60);
	int bulletCD = 0;
	//Everything is a child of this object---------------------------------------------------------------------------------//
	MathX::Object2D Space("Space", MathX::Vector2(0,0), MathX::Vector3(0,0,0), MathX::Vector2(1,1));
	//Mark that we are standalone. (This is a neat feature that lets us use a dynamic find something by name feature)
	Space.Attach(nullptr);
	//---------------------------------------------------------------------------------------------------------------------//

	MathX::Object2D Player("Player", MathX::Vector2(screenWidth / 2, screenHeight / 2), MathX::Vector3(0, 0, 0), MathX::Vector2(1, 1), &Space);
	MathX::Object2D Turret("Turret", MathX::Vector2(0, 0), MathX::Vector3(0, 0, 0), MathX::Vector2(1, 1), &Player);
	Sprite PlayerSprite;
	Sprite TurretSprite;
	PlayerSprite.SpriteSource = LoadTexture("TankBase.png");
	TurretSprite.SpriteSource = LoadTexture("TankTurret.png");
	std::vector<Shot*> Shots;

	MathX::Matrix3 id;
	id = id.GetIdentity();

	MathX::Matrix3 offset;
	offset = offset.GetTranslation(5, 9);

	MathX::Matrix3 trs = id * offset;

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(GRAY);

		for (int i = 0; i < Shots.size(); ++i)
			Shots[i]->Update();

		//Example of the hierarchies finding by name capability.
		PlayerSprite.RenderSprite(*Space.FindChildByName("Player"));
		TurretSprite.RenderSprite(*Space.FindChildByName("Player")->FindChildByName("Turret"));
		
		//Controls:
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		if (IsKeyDown(KEY_W))
			Space.FindChildByName("Player")->Transform->localPos += Space.FindChildByName("Player")->Transform->Forward() * -1;
		if (IsKeyDown(KEY_S))
			Space.FindChildByName("Player")->Transform->localPos += Space.FindChildByName("Player")->Transform->Forward() * 1;
		if (IsKeyDown(KEY_R))
			Space.FindChildByName("Player")->FindChildByName("Turret")->Transform->localPos += 
				Space.FindChildByName("Player")->FindChildByName("Turret")->Transform->Forward() * -1;
		if (IsKeyDown(KEY_F))
			Space.FindChildByName("Player")->FindChildByName("Turret")->Transform->localPos += 
				Space.FindChildByName("Player")->FindChildByName("Turret")->Transform->Forward() * 1;
		if (IsKeyDown(KEY_Q))
			Space.FindChildByName("Player")->FindChildByName("Turret")->Transform->localRot -= 0.05;
		if (IsKeyDown(KEY_E))
			Space.FindChildByName("Player")->FindChildByName("Turret")->Transform->localRot += 0.05;
		if (IsKeyDown(KEY_A))
			Space.FindChildByName("Player")->Transform->localRot -= 0.05;
		if (IsKeyDown(KEY_D))
			Space.FindChildByName("Player")->Transform->localRot += 0.05;
		if (IsKeyDown(KEY_Z))
			Space.FindChildByName("Player")->Transform->localScale -= 0.01;
		if (IsKeyDown(KEY_X))
			Space.FindChildByName("Player")->Transform->localScale += 0.01;
		if (IsKeyDown(KEY_C))
			Space.FindChildByName("Player")->FindChildByName("Turret")->Transform->localScale -= 0.01;
		if (IsKeyDown(KEY_V))
			Space.FindChildByName("Player")->FindChildByName("Turret")->Transform->localScale += 0.01;
		if (IsKeyDown(KEY_SPACE) && bulletCD > 25)
		{
			bulletCD = 0;
			Shots.push_back(new Shot);

			MathX::Vector3 wrld = Space.FindChildByName("Player")->FindChildByName("Turret")->Transform->GetWorldRotation();
			MathX::Vector2 Forward = MathX::Vector2(0, 0);
			MathX::Vector3 convert = (Space.FindChildByName("Player")->FindChildByName("Turret")->Transform->localRot +
				Space.FindChildByName("Player")->Transform->GetWorldRotation()) + (PI / 2);
			Forward = MathX::Vector2(cos(convert.Z), sin(convert.Z));
			Shots.back()->Velocity = Forward * -10;
			Shots.back()->Position = Space.FindChildByName("Player")->Transform->localPos + (Shots.back()->Velocity * 4);
			//Little visual memory in our console to visualize how large our bullet count is.
			std::cout << "S";
		}
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		++bulletCD;

		DrawText("Used W and S to move the tank forward and backwards.\nUsed R and F to move the turret forward and backwards.\nUse Q and E to rotate the turret.\nUse A and D to rotate the tank.\nUse Z and X to scale the tank.\nUse C and V to scale the turret.\nUse Space to fire.", 25, 25, 20, WHITE);

		EndDrawing();
	}

	CloseWindow();

	return;
}