#pragma once
#include "raylib.h"
#include "EngineExtras.h"

class Sprite
{
public:
	Texture2D SpriteSource;
	Color Tint;
	
	void RenderSprite(MathX::Object2D& toRender)
	{
		if (&toRender == nullptr) return;

		Rectangle Destination, Origin;
		
		Destination.x = toRender.Transform->localPos.X;
		Destination.y = toRender.Transform->localPos.Y;
		Origin.width = SpriteSource.width;
		Origin.height = SpriteSource.height;
		Destination.width = 0;
		Destination.height = 0;
		Origin.x = 0;
		Origin.y = 0;

		DrawTexturePro(SpriteSource, Destination, Origin, Vector2{ 0,0 }, toRender.Transform->localRot.Z, Tint);
	};
};