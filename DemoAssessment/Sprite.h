#pragma once
#include "raylib.h"
#include "EngineExtras.h"

class Sprite
{
public:
	Texture2D SpriteSource;
	Color Tint = WHITE;
	
	void RenderSprite(MathX::Object2D& toRender)
	{
		if (&toRender == nullptr) return;

		Rectangle Destination, Origin;

		MathX::Matrix3 TRS = toRender.Transform->GetTRSMatrix();

		MathX::Vector3 Transform = TRS.xAxis;
		MathX::Vector3 Rotation = TRS.yAxis;
		MathX::Vector3 Scale = TRS.zAxis;

		//World position of the object.
		Destination.x = Transform.X; //toRender.Parent->Transform->GetWorldTranslation().X + toRender.Transform->localPos.X;
		Destination.y = Transform.Y; //toRender.Parent->Transform->GetWorldTranslation().Y + toRender.Transform->localPos.Y;
		float rotation = Rotation.Z;//toRender.Parent->Transform->GetWorldRotation().Z + toRender.Transform->localRot.Z;
		Origin.width = SpriteSource.width;
		Origin.height = SpriteSource.height;
		Destination.width = SpriteSource.width * Scale.X;
		Destination.height = SpriteSource.height * Scale.Y;
		Origin.x = 0;
		Origin.y = 0;

		//DrawTexture(SpriteSource, Destination.x, Destination.y, Tint);
		DrawTexturePro(SpriteSource, Origin, Destination, Vector2{ ((float)SpriteSource.width * Scale.X) / 2, 
																   ((float)SpriteSource.height * Scale.Y) / 2 }, rotation, Tint);

		return;
	};
};