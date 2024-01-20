#pragma once

#include "InputManager.hpp"

namespace Dumpling
{
	// обработка клика по спрайту
	bool InputManager::IsSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow& window)
	{
		if (sf::Mouse::isButtonPressed(button))
		{
			sf::IntRect playButtonRect(object.getPosition().x, object.getPosition().y, object.getGlobalBounds().width, object.getGlobalBounds().height);

			if (playButtonRect.contains(sf::Mouse::getPosition(window)))
			{
				return true;
			}
		}

		return false;
	}

	// узнать позицию мышки
	sf::Vector2i InputManager::GetMousePosition(sf::RenderWindow& window)
	{
		return sf::Mouse::getPosition(window);
	}
}