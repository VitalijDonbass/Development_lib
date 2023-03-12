#pragma once

#include <string>
#include <vector>

namespace dl
{
	class NameObject
	{
	public:
		NameObject();
		NameObject(std::string name_obj);

		virtual ~NameObject();

		virtual const std::string& getName() const;
		virtual bool setName(std::string new_name);
	private:
		std::string name;

		NameObject(const NameObject& obj) = delete;
		NameObject& operator=(const NameObject& obj) = delete;

		static size_t counter;
	protected:
		static std::vector<NameObject*> nameSpace;

		virtual bool deleteInfoThisName();
		static bool checkColisionNames(std::string& checking_name);
		static std::string genrDefaultName();
	};
}