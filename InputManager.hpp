#pragma once
#include <SFML/Graphics.hpp>

namespace Pelmen
{
	class InputManager
	{
	public:
		InputManager() {}
		~InputManager() {}

		//нажат ли спрайт
		bool isSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow& window);

		//узнать позицию мышки
		sf::Vector2i GetMousePosition(sf::RenderWindow& window);

	};
}