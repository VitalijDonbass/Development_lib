#pragma once

#include "../../include/Math/Vector2D.h"
#include "TypeObject.h"

namespace dl
{
	class UnnamingObject
	{
	public:
		UnnamingObject();
		UnnamingObject(Vector2DFloat posit, Vector2DFloat sz, Vector2DFloat scl, float ang, TypeObject tpObj = TypeObject::UNNAMIG_OBJECT);
		UnnamingObject(const UnnamingObject& obj);
		UnnamingObject& operator=(const UnnamingObject& obj);
		virtual ~UnnamingObject();

		virtual const TypeObject& getType() const;
		virtual const Vector2DFloat& getPosition() const;
		virtual const Vector2DFloat& getSize() const;
		virtual const Vector2DFloat& getScale() const;
		virtual const float& getAngle() const;

		virtual void setPosition(Vector2DFloat posit);
		virtual void setSize(Vector2DFloat size);
		virtual void setScale(Vector2DFloat scl);
		virtual void setAngle(float ang);
	private:
		TypeObject type;
		Vector2DFloat position;
		Vector2DFloat size;
		Vector2DFloat scale;
		float angle;
	};
}