#pragma once
#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include "StateMachine.hpp"
#include "AssetManager.hpp"
#include "InputManager.hpp"


namespace Pelmen {

	struct GameData
	{
		
		StateMachine machine;

		//окно рендеринга
		sf::RenderWindow window;

		// менеджер текстур
		AssetManager assets;

		// менеджер ввода
		InputManager input; 
	};

	typedef std::shared_ptr<GameData> GameDataRef; // для доступа к полям
	

	class Game {
	public:
		Game(int width, int heigth, std::string title);

	private:
		const float dt = 1.0f / 60.0f; // частота кадров
		sf::Clock clock_; // для управления частотой кадров
		GameDataRef data_ = std::make_shared<GameData>(); // ссылка для доступа к игровым данным

		void Run();

	};
}