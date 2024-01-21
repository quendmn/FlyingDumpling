#pragma once

#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include <vector>

namespace Dumpling
{
	class Land
	{
	public:
		Land(GameDataRef data);

		void MoveLand(float dt);
		void DrawLand();
		const std::vector<sf::Sprite>& GetSprites() const;

	private:
		GameDataRef data_;

		std::vector<sf::Sprite>landSprites_;

	};
}