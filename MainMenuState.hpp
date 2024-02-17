#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "State.hpp"
#include "Game.hpp"

namespace Dumpling
{
	class MainMenuState : public State
	{
	public:
		MainMenuState(GameDataRef data);

		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		GameDataRef data_;

		sf::Sprite background_;
		sf::Sprite title_;
		sf::Sprite playButton_;

		sf::SoundBuffer hitBuffer_;
		sf::SoundBuffer pointBuffer_;
		sf::SoundBuffer wingBuffer_;
		sf::SoundBuffer musicBuffer_;

		sf::Sound hitSound_;
		sf::Sound pointSound_;
		sf::Sound wingSound_;
		sf::Sound musicSound_;


	};
}