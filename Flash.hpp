#pragma once

#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include "DEFINITIONS.hpp"

namespace Dumpling
{
	class Flash
	{
	public:
		Flash(GameDataRef data);
		~Flash();

		void Show(float dt);
		void Draw();

	private:
		GameDataRef data_;

		sf::RectangleShape shape_;

		bool flashOn_;

	};
}