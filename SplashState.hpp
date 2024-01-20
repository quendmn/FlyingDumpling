#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"

namespace Dumpling
{
	class SplashState : public State
	{
	public:
		SplashState(GameDataRef data);

		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		GameDataRef data_;

		sf::Clock clock_;

		sf::Sprite background_;
	};
}