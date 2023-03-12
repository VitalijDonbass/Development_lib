#include "../../include/Object/NameObject.h"
#include "../../include/Loger/Loger.h"
#include "../../include/System/System.h"
#include <algorithm>

dl::NameObject::NameObject()
	:name(NameObject::genrDefaultName())
{
}

dl::NameObject::NameObject(std::string name_obj)
	:name(NameObject::checkColisionNames(name_obj) ? NameObject::genrDefaultName() : name_obj)
{
}

dl::NameObject::~NameObject()
{
	this->deleteInfoThisName();
}

const std::string& dl::NameObject::getName() const
{
	return this->name;
}

bool dl::NameObject::setName(std::string new_name)
{
	if (!NameObject::checkColisionNames(new_name))
	{
		this->name = new_name;
		return true;
	}
	else
	{
		Warning warning(TypeWarning::COLISION, std::string("Fail setting name!").append(" Problem name: ").append(new_name));
		Loger::process(warning, System::getOutputer());
		return false;
	}
}

bool dl::NameObject::deleteInfoThisName()
{
	try
	{
		NameObject::nameSpace.erase(
			std::find(NameObject::nameSpace.begin(),
				NameObject::nameSpace.end(), this));
		return true;
	}
	catch (...)
	{
		return false;
	}
}

bool dl::NameObject::checkColisionNames(std::string& checking_name)
{
	for (NameObject* obj : NameObject::nameSpace)
		if (obj->name == checking_name)
			return true;
	return false;
}

std::string dl::NameObject::genrDefaultName()
{
	std::string defaultName;
	do
	{
		defaultName.clear();
		defaultName.append("object_").append(std::to_string(NameObject::counter++));
	} while (NameObject::checkColisionNames(defaultName));
	return defaultName;
}
