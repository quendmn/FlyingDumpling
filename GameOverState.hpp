#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "State.hpp"
#include "Game.hpp"

namespace Dumpling
{
	class GameOverState : public State
	{
	public:
		GameOverState(GameDataRef data, int score);

		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		GameDataRef data_;

		sf::Sprite background_;

		sf::Sprite gameOverTitle_;
		sf::Sprite gameOverBody_;
		sf::Sprite gameOverRetry_;
		sf::Sprite medal_;


		sf::Text scoreText_;
		sf::Text highScoreText_;

		int score_;
		int highScore_;

		sf::SoundBuffer hitBuffer_;
		sf::SoundBuffer pointBuffer_;
		sf::SoundBuffer wingBuffer_;

		sf::Sound hitSound_;
		sf::Sound pointSound_;
		sf::Sound wingSound_;

	};
}