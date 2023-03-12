#pragma once

#include "NameObject.h"
#include "UnnamigObject.h"

namespace dl
{
	class NamingObject : public UnnamingObject 
	{
	public:
		NamingObject();
		NamingObject(Vector2DFloat posit, Vector2DFloat size, Vector2DFloat scl, float angle, std::string name, TypeObject tpObj = TypeObject::NAMING_OBJECT);
		virtual ~NamingObject();

		NameObject name;
	private:
		NamingObject(const NamingObject& obj) = delete;
		NamingObject& operator=(const NamingObject& obj) = delete;
	};
}