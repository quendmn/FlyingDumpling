#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "State.hpp"
#include "Game.hpp"
#include "Fork.hpp"
#include "Land.hpp"
#include "Dumpling.hpp"
#include "Collision.hpp"
#include "Flash.hpp"
#include "Scores.hpp"

namespace Dumpling
{
	class GameState : public State
	{
	public:
		GameState(GameDataRef data);

		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		GameDataRef data_;

		sf::Sprite background_;

		Fork* fork;
		Land* land;
		Dumpling* dumpling;
		Collision collision;
		Flash* flash;
		Scores* scores;

		sf::Clock clock;

		int gameState_;

		sf::RectangleShape gameOverFlash_;
		bool flashOn_;

		int score_;

		sf::SoundBuffer hitBuffer_;
		sf::SoundBuffer pointBuffer_;
		sf::SoundBuffer wingBuffer_;

		sf::Sound hitSound_;
		sf::Sound pointSound_;
		sf::Sound wingSound_;
		
	};
}