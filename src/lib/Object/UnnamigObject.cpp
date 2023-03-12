#include "../../include/Object/UnnamigObject.h"

namespace dl
{
	dl::UnnamingObject::UnnamingObject()
		:type(TypeObject::UNNAMIG_OBJECT), 
		position(Vector2DFloat()), 
		size(Vector2DFloat()), 
		scale(Vector2DFloat()), angle(0.0)
	{
	}

	dl::UnnamingObject::UnnamingObject(Vector2DFloat posit, Vector2DFloat sz, Vector2DFloat scl, float ang, TypeObject tpObj)
		:type(tpObj),
		position(posit),
		size(sz),
		scale(scl), angle(ang)
	{
	}

	dl::UnnamingObject::UnnamingObject(const UnnamingObject& obj)
		:type(obj.type),
		position(obj.position),
		size(obj.size),
		scale(obj.scale), angle(obj.angle)
	{
	}

	UnnamingObject& dl::UnnamingObject::operator=(const UnnamingObject& obj)
	{
		this->angle = obj.angle;
		this->position = obj.position;
		this->scale = obj.scale;
		this->size = obj.size;
		this->type = obj.type;
	}

	dl::UnnamingObject::~UnnamingObject()
	{
	}

	const TypeObject& dl::UnnamingObject::getType() const
	{
		return this->type;
	}

	const Vector2DFloat& dl::UnnamingObject::getPosition() const
	{
		return this->position;
	}

	const Vector2DFloat& dl::UnnamingObject::getSize() const
	{
		return this->size;
	}

	const Vector2DFloat& dl::UnnamingObject::getScale() const
	{
		return this->scale;
	}

	const float& dl::UnnamingObject::getAngle() const
	{
		return this->angle;
	}

	void dl::UnnamingObject::setPosition(Vector2DFloat posit)
	{
		this->position = posit;
	}

	void dl::UnnamingObject::setSize(Vector2DFloat size)
	{
		this->size = size;
	}

	void dl::UnnamingObject::setScale(Vector2DFloat scl)
	{
		this->scale = scl;
	}

	void dl::UnnamingObject::setAngle(float ang)
	{
		this->angle = ang;
	}
}
