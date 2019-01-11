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

		MathX::Matrix3 TRS( 0,0,0,0,0,0,0,0,0 );
		TRS = toRender.Transform->GetWorldTRSMatrix();
		//TRS = toRender.Transform->GetTRSMatrix();
		//MathX::Vector3 wrld = MathX::Vector3(toRender.Parent->Transform->GetWorldTranslation().X, toRender.Parent->Transform->GetWorldTranslation().Y, 0.0f);
		MathX::Vector3 Transform = TRS.zAxis;
		MathX::Vector3 Rotation = TRS.xAxis;
		MathX::Vector3 Scale = MathX::Vector3(TRS.xAxis.Magnitude(), TRS.yAxis.Magnitude(), 1.0f);

		//World position of the object.
		Destination.x = Transform.X; //toRender.Parent->Transform->GetWorldTranslation().X + toRender.Transform->localPos.X;
		Destination.y = Transform.Y; //toRender.Parent->Transform->GetWorldTranslation().Y + toRender.Transform->localPos.Y;
		float rotation = atan2f(Rotation.Y, Rotation.X);//toRender.Parent->Transform->GetWorldRotation().Z + toRender.Transform->localRot.Z;
		Origin.width = SpriteSource.width;
		Origin.height = SpriteSource.height;
		Destination.width = SpriteSource.width * Scale.X;
		Destination.height = SpriteSource.height * Scale.Y;
		Origin.x = 0;
		Origin.y = 0;

		//DrawTexture(SpriteSource, Destination.x, Destination.y, Tint);
		DrawTexturePro(SpriteSource, Origin, Destination, Vector2{ (Destination.width / 2), (Destination.height / 2) }, RAD2DEG * rotation, Tint);

		return;
	};
};