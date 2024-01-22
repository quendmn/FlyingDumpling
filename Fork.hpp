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
		void SpawnScoringFork();
		void MoveForks(float dt);
		void RandomiseForkOffset();

		const std::vector<sf::Sprite>& GetSprites() const;
		std::vector<sf::Sprite>& GetScoringSprites();

	private:
		GameDataRef data_;
		std::vector<sf::Sprite> forkSprites_;
		std::vector<sf::Sprite> scoringForks_;

		int landHeight_;
		int forkSpawnYOffset_;


	};
}