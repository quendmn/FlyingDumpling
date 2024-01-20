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
		
		//������ � ����������
		void LoadTexture(std::string name, std::string fileName);
		sf::Texture& GetTexture(std::string name);

		//������ �� ��������
		void LoadFont(std::string name, std::string fileName);
		sf::Font& GetFont(std::string name);

	private:
		
		//��������
		std::map<std::string, sf::Texture> textures_;
		std::map<std::string, sf::Font> fonts_;
	};
}