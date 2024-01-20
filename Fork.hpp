#pragma once
#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include <vector>
#include "DEFINITIONS.hpp"
namespace Dumpling
{
	class Fork
	{
	public:
		Fork(GameDataRef data);

		void DrawForks();
		void SpawnBottomFork();
		void SpawnTopFork();
		void SpawnInvisibleFork();
		void MoveForks(float dt);

	private:
		GameDataRef data_;
		std::vector<sf::Sprite> forkSprites_;


	};
}