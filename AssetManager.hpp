#pragma once

#include <map>
#include <SFML/Graphics.hpp>

namespace Dumpling
{
	class AssetManager
	{
	public:

		AssetManager() { }
		~AssetManager() { }
		
		//работа с текстурами
		void LoadTexture(std::string name, std::string fileName);
		sf::Texture& GetTexture(std::string name);

		//работа со шрифтами
		void LoadFont(std::string name, std::string fileName);
		sf::Font& GetFont(std::string name);

	private:
		
		//хранение
		std::map<std::string, sf::Texture> textures_;
		std::map<std::string, sf::Font> fonts_;
	};
}