#include "AssetManager.hpp"

namespace Pelmen {

	// зарузка текстур
	void AssetManager::LoadTexture(std::string name, std::string fileName)
	{
		sf::Texture tex;
		if (tex.loadFromFile(fileName))
		{
			this->textures_[name] = tex;
		}
	}
	sf::Texture& AssetManager::GetTexture(std::string name) {
		return this->textures_.at(name);
	}


	// загрузка шрифтов
	void AssetManager::LoadFont(std::string name, std::string fileName)
	{
		sf::Font font;
		if (font.loadFromFile(fileName))
		{
			this->fonts_[name] = font;
		}
	}
	sf::Font& AssetManager::GetFont(std::string name) {
		return this->fonts_.at(name);
	}
}