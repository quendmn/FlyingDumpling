#pragma once
#include <SFML/Graphics.hpp>

namespace Dumpling {

	class Collision {

	public:
		Collision();

		bool CheckSpriteCollision(sf::Sprite sprite1, sf::Sprite sprite2);

	};
}


