#pragma once
#include <SFML/Graphics.hpp>
#include "DEFINITIONS.hpp"
#include "Game.hpp"

namespace Dumpling {
	class Scores
	{
	public:
		Scores(GameDataRef data);

		void Draw();
		void UpdateScore(int score);

	private:
		GameDataRef data_;
		sf::Text scoreText_;

	};
}
