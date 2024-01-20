#pragma once

#include "SFML\Graphics.hpp"

namespace Dumpling
{
	class InputManager
	{
	public:
		InputManager() {}
		~InputManager() {}

		// обработка клика по спрайту
		bool IsSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow& window);

		sf::Vector2i GetMousePosition(sf::RenderWindow& window);
	};
}