#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"
#include "Fork.hpp"
#include "Land.hpp"
#include "Dumpling.hpp"
#include "Collision.hpp"
#include "Flash.hpp"

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
		sf::Clock clock_;

		Fork* fork;
		Land* land;
		Dumpling* dumpling;
		Collision collision;
		Flash* flash;

		int gameState_;

	};
}