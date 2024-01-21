#pragma once

#include <SFML/Graphics.hpp>

#include "DEFINITIONS.hpp"
#include "Game.hpp"

namespace Dumpling
{
	class Dumpling
	{
	public:
		Dumpling(GameDataRef data);
		~Dumpling();

		void Draw();
		void Update(float dt);
		void Tap();
		const sf::Sprite& GetSprite() const;


	private:
		GameDataRef data_;

		sf::Sprite dumplingSprite_;
		sf::Clock movementClock_;
		int dumplingState_;

	};
}