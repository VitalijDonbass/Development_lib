#include "../../include/Object/NamingObject.h"

namespace dl
{
	dl::NamingObject::NamingObject()
		:name(), UnnamingObject()
	{
	}

	dl::NamingObject::NamingObject(Vector2DFloat posit, Vector2DFloat size, Vector2DFloat scl, float angle, std::string name, TypeObject tpObj)
		:name(name), UnnamingObject(posit, size, scl, angle, tpObj)
	{
	}

	dl::NamingObject::~NamingObject()
	{
	}
}