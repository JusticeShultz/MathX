#include "EngineExtras.h"

namespace MathX
{
	Object2D::~Object2D()
	{
		delete Transform;
	}

	//Attach us to a new parent and keep our children.

	void Object2D::Attach(Object2D * toWho)
	{
		if (toWho == nullptr)
		{
			this->Parent = nullptr;
			return;
		}

		toWho->Children.push_back(this);
		this->Parent = toWho;
		this->Transform->Parent = toWho;
		return;
	}

	//Complete constructor.

	Object2D::Object2D(std::string nm, Vector2 pos, Vector3 rot, Vector2 scale)
	{
		this->Name = nm;
		this->Transform = new Transform2D();
		this->Transform->localPos = pos;
		this->Transform->localRot = rot;
		this->Transform->localScale = scale;
		this->Parent = nullptr;
	}

	//Child constructor. (Creating something childed to an object)

	Object2D::Object2D(std::string nm, Vector2 pos, Vector3 rot, Vector2 scale, Object2D * toWho)
	{
		this->Transform = new Transform2D();
		this->Name = nm; this->Transform->localPos = pos; this->Transform->localRot = rot; this->Transform->localScale = scale;
		this->Attach(toWho);
	}
}