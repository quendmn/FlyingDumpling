#pragma once

#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include "StateMachine.hpp"
#include "AssetManager.hpp"

namespace Dumpling
{
	struct GameData
	{
		StateMachine machine;
		sf::RenderWindow window;
		AssetManager assets;
	};

	typedef std::shared_ptr<GameData> GameDataRef;

	class Game
	{
	public:

		//для работы с окном
		Game(int width, int height, std::string title);

	private:
		// обновление кадра 
		const float dt = 1.0f / 60.0f;
		sf::Clock clock_;
		sf::Image icon_;

		GameDataRef data_ = std::make_shared<GameData>();

		void Run();
	};
}