#include "../../include/System/Loader.h"
#include "../../include/Loger/Loger.h"

namespace dl
{
	template<typename typeLoadFile>
	Loader<typeLoadFile>::Loader(Outputer* outpt) 
		:outputer(outpt), file(new typeLoadFile()), loadStatusFile(false) {};
	template<typename typeLoadFile>
	Loader<typeLoadFile>::~Loader()
	{
		if (this->loadStatusFile)
			delete this->file;
	}
	template<typename typeLoadFile>
	typeLoadFile* Loader<typeLoadFile>::getFile(bool isClearMemory)
	{
		if (!this->loadStatusFile)
		{
			this->failGettingLog();
			return nullptr;
		}
		else
		{
			if (isClearMemory)
			{
				auto buff = this->file;
				this->file = nullptr;
				return buff;
			}
			else
			{
				return this->file;
			}
		}
	}

	template<typename typeLoadFile>
	void Loader<typeLoadFile>::failLoadLog(std::string pachToFile)
	{
		Error failLoadFile(TypeError::FAIL_LOAD,
			std::string("Fail load file! \"").append(pachToFile).append("\""),
			false);
		this->processLog(failLoadFile);
	}
	template<typename typeLoadFile>
	void Loader<typeLoadFile>::processLog(Log& lg)
	{
		if (this->outputer == nullptr)
			Loger::process(lg);
		else
			Loger::process(lg, *(this->outputer));
	}
	template<typename typeLoadFile>
	void Loader<typeLoadFile>::failGettingLog()
	{
		Error failGettingFile(
			TypeError::FAIL_FIND_FILE,
			std::string("Fail getting file! \""),
			true);
		this->processLog(failGettingFile);
	}

	template<typename typeLoadFile>
	void Loader<typeLoadFile>::warningFileLoss(std::string infoDeleteObject)
	{
		Warning fileLoss(TypeWarning::DATA_LOSS, std::string("File loss!").append(infoDeleteObject));
		this->processLog(fileLoss);
	}

	TextureLoader::TextureLoader(Outputer* outpt) :Loader<sf::Texture>(outpt) {}
	bool TextureLoader::loadFile(std::string pachToFile)
	{
		if (this->loadStatusFile) this->warningFileLoss("Texture pointer loss! Write it down, and free in future!");
		if (!(this->loadStatusFile = ((this->file = new sf::Texture())->loadFromFile(pachToFile))))
			this->failLoadLog(pachToFile);
		return this->loadStatusFile;
	}
}