#pragma once

#include <string>
#include <SFML/Graphics.hpp>
#include "../Loger/Outputer.h"

namespace dl
{
	template<typename typeLoadFile>
	class Loader
	{
	public:
		Loader(Outputer* outpt = nullptr);
		virtual ~Loader();
		virtual bool loadFile(std::string pachToFile) = 0;
		virtual typeLoadFile* getFile(bool isClearMemory = false);
	protected:
		virtual void failLoadLog(std::string pachToFile);
		virtual void warningFileLoss(std::string infoDeleteObject);

		Outputer* outputer;
		typeLoadFile* file;
		bool loadStatusFile;
	private:
		virtual void processLog(Log& lg);
		virtual void failGettingLog();
	};

	class TextureLoader : public Loader<sf::Texture>
	{
	public:
		TextureLoader(Outputer* outpt = nullptr);

		bool loadFile(std::string pachToFile) override;
	private:
	};
}
