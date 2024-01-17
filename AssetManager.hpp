#pragma once
#include <map>
#include <SFML/Graphics.hpp>

namespace Pelmen {

	class AssetManager {
	public:
		AssetManager() {}
		~AssetManager() {}

		// загрузить текстуру
		void LoadTexture(std::string name, std::string fileName);
		sf::Texture& GetTexture(std::string name);

		// загрузить шрифт
		void LoadFont(std::string name, std::string fileName);
		sf::Font &GetFont(std::string name);

	private:
		// для хранения текстур и шрифтов вместе с их названиями
		std::map<std::string, sf::Texture> textures_;
		std::map<std::string, sf::Font> fonts_;
	};
}