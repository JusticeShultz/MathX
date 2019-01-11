#pragma once
#include "MathX.h"
#include <vector>
#include <string>

//Why is this in the math library? Good question, I don't know.
//This holds some extra utilities relating to game engine like code
//that structurely uses a hierarchy with transform data to make easily form objects.

namespace MathX
{
	class Object2D;
	class Transform2D;

	//Objects have parents, children and additional class data. (2D)
	class Object2D
	{ //Full access.
	public:
		//Empty constructor.
		Object2D() { this->Parent = nullptr; };
		//Named constructor.
		Object2D(std::string nm) { this->Name = nm; this->Parent = nullptr; };
		//Complete constructor.
		Object2D(std::string nm, Vector2 pos, Vector3 rot, Vector2 scale);
		//Child constructor. (Creating something childed to an object)
		Object2D(std::string nm, Vector2 pos, Vector3 rot, Vector2 scale, Object2D* toWho);

		~Object2D();
		//Our objects name(THIS IS IMPORTANT FOR DETACH LISTING UPDATES!) (ALSO NOTE YOU CAN CHANGE THE NAME WHENEVER IT DOES NOT MATTER!)
		std::string Name;
		//Transform data for our object.
		Transform2D * Transform;
		//Vector list of all of our children.
		typedef std::vector<Object2D *> BagOfChildren; BagOfChildren Children;
		//If parent is a nullptr we have no parented object and we are standalone.
		Object2D* Parent;
		//Attach us to a new parent and keep our children.
		void Attach(Object2D* toWho);
		//Detach us from our parent but keep our children.
		void Detach()
		{
			int MeToMyParent = -1;

			for (int i = 0; i < this->Parent->Children.size(); ++i)
			{
				//Look for someone that is(maybe) us. (Individual naming is important!)
				if (this->Parent->Children[i]->Name == this->Name)
					MeToMyParent = i;
			}
			//Escape, somethings wrong.
			if (MeToMyParent == -1) return;
			//We are no longer a child of this parent, back to the adoption place.
			this->Parent->Children.erase(this->Parent->Children.begin() + MeToMyParent);
			//Our parents are gone help.
			this->Parent = nullptr;
			//EOFunction.
			return;
		}
		Object2D* FindChildByName(std::string objName)
		{
			int Object = -1;
			for (int i = 0; i < this->Children.size(); ++i)
				//Look for someone that is(maybe) us. (Individual naming is important!)
				if (this->Children[i]->Name == objName)
					Object = i;
			//We didn't find the desired object so return null.
			if (Object == -1) return nullptr;
			//Return who we found.
			return this->Children[Object];
		}
	};

	class Transform2D : public Object2D
	{ //Full access.
	public:
		//Constructor()
		Transform2D() { };

		Vector2 localPos;
		Vector3 localRot;
		Vector2 localScale;
		Vector2 localDirection;

		//SETTER
		void Translate(const Vector2 &offset)
		{
			localPos += offset;
		};

		//SETTER
		void Rotate(const float angle)
		{
			localRot.Z += angle;
		};

		//SETTER
		void SetScale(const Vector2 &scale)
		{
			localScale = scale;
		};

		//SETTER TAKES TRANSFORM2D
		void LookAt(const Transform2D &target)
		{
			Vector2 targetVec = target.localPos;
			Vector2 VectorCalculation = { targetVec.X - localPos.X, targetVec.Y - localPos.Y };
			float normalVec = sqrt(VectorCalculation.X * VectorCalculation.X + VectorCalculation.Y * VectorCalculation.Y);
			VectorCalculation.X = VectorCalculation.X / normalVec;
			VectorCalculation.Y = VectorCalculation.Y / normalVec;
			localRot.Z = atan2(VectorCalculation.Y, VectorCalculation.X) * RAD2DEG;
			localDirection = VectorCalculation;
		};

		//SETTER TAKES VECTOR2
		void LookAt(const Vector2 &target)
		{
			Vector2 targetVec = target;
			Vector2 VectorCalculation = { targetVec.X - localPos.X, targetVec.Y - localPos.Y };
			float normalVec = sqrt(VectorCalculation.X * VectorCalculation.X + VectorCalculation.Y * VectorCalculation.Y);
			VectorCalculation.X = VectorCalculation.X / normalVec;
			VectorCalculation.Y = VectorCalculation.Y / normalVec;
			localRot.Z = atan2(VectorCalculation.Y, VectorCalculation.X) * RAD2DEG;
			localDirection = VectorCalculation;
		};

		//GETTER
		Vector2 Forward() const
		{
			Vector2 Forward = Vector2(0, 0);
			Vector3 convert = localRot + (PI / 2);
			Forward = Vector2(cos(convert.Z), sin(convert.Z));
			return Forward;
		};

		//SETTER
		void SetForward(const Vector2 &newFwd)
		{
			LookAt(newFwd);
		};

		//GETTER
		Matrix3 GetTRSMatrix() const
		{
			Matrix3 transMatrix;
			transMatrix = transMatrix.GetTranslation(localPos);
			Matrix3 rotMatrix;
			rotMatrix = rotMatrix.GetRotation(localRot.Z);
			Matrix3 scaleMatrix;
			scaleMatrix = scaleMatrix.GetScale(localScale.X, localScale.Y);
			// translate rotate scale
			return transMatrix * rotMatrix * scaleMatrix;
		};

		//GETTER
		Vector2 GetWorldTranslation() const
		{
			Vector2 wrld = Vector2(0,0);
			wrld += localPos;

			if (Parent != nullptr)
				wrld += Parent->Transform->GetWorldTranslation();

			return wrld;
		};

		//GETTER
		Vector3 GetWorldRotation() const
		{
			Vector3 wrld = Vector3(0, 0, 0);
			wrld += Vector3(0, 0, localRot.Z);

			if (Parent != nullptr)
				wrld += Parent->Transform->GetWorldRotation();

			return wrld;
		};

		//GETTER
		Vector2 GetWorldScale() const
		{
			Vector2 wrld = Vector2(0, 0);
			wrld += localScale;

			if (Parent != nullptr)
				wrld += Parent->Transform->GetWorldScale();

			return wrld;
		};

		//GETTER
		Vector2 WorldForward() const
		{
			Vector3 wrld = Vector3(0, 0, 0);

			if (Parent != nullptr)
				wrld += Parent->Transform->GetWorldRotation();

			Vector2 Forward = Vector2(0, 0);
			Vector3 convert = Vector3(0, 0, (wrld.Z + localRot.Z)) * DEG2RAD + (PI / 2);
			Forward = Vector2(cos(convert.Z), sin(convert.Z));
			return Forward;
		};

		//GETTER
		Matrix3 GetWorldTRSMatrix() const
		{
			Matrix3 wrld(0, 0, 0, 0, 0, 0, 0, 0, 0);
			wrld = GetTRSMatrix();

			if (Parent != nullptr)
				wrld = Parent->Transform->GetTRSMatrix() * wrld;

			return wrld;
		};
	};

	struct Transform3D
	{
		//Constructor()
		Transform3D() { };

		Vector2 localPos;
		Vector2 localRot;
		Vector2 localScale;

		//SETTER
		void Translate(const Vector2 &offset)
		{

		};

		//SETTER
		void Rotate(const float angle)
		{

		};

		//SETTER
		void LookAt(const Transform3D &target)
		{

		};

		//GETTER
		Vector2 Forward() const
		{

		};

		//SETTER
		void SetForward(const Vector2 &newFwd)
		{

		};

		//GETTER
		Matrix3 GetTRSMatrix() const
		{
			
		};
	};


	//Objects have parents, children and additional class data. (3D)
	class Object3D
	{
		Transform3D Transform;
	};
}