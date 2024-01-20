#include <sstream>
#include "GameState.hpp"
#include "DEFINITIONS.hpp"
#include "MainMenuState.hpp"
#include <iostream>

namespace Dumpling
{
	GameState::GameState(GameDataRef data) : data_(data)
	{

	}

	// инициализация
	void GameState::Init()
	{
		this->data_->assets.LoadTexture("Game Background", GAME_BACKGROUND_FILEPATH);
		background_.setTexture(this->data_->assets.GetTexture("Game Background"));

		this->data_->assets.LoadTexture("Fork Up Texture", FORK_UP_FILEPATH);
		background_.setTexture(this->data_->assets.GetTexture("Fork Up Texture"));

		this->data_->assets.LoadTexture("Fork Down Texture", FORK_DOWN_FILEPATH);
		background_.setTexture(this->data_->assets.GetTexture("Fork Down Texture"));

		fork = new Fork(data_);
		background_.setTexture(this->data_->assets.GetTexture("Game Background"));

	}

	//обработка действий 
	void GameState::HandleInput()
	{
		sf::Event event;

		while (this->data_->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->data_->window.close();
			}

			//генерация вилок
			if (this->data_->input.IsSpriteClicked(this->background_,
				sf::Mouse::Left, this->data_->window))
			{
				
			}

		}
	}

	// обновление
	void GameState::Update(float dt)
	{
		fork->MoveForks(dt);
		if (clock_.getElapsedTime().asSeconds() > FORK_SPAWN_FREQUENCY)
		{
			fork->SpawnBottomFork();
			fork->SpawnTopFork();
			fork->SpawnInvisibleFork();

			clock_.restart();
		}
	}

	// отрисовка
	void GameState::Draw(float dt)
	{
		this->data_->window.clear(sf::Color::Red);

		this->data_->window.draw(this->background_);
		fork->DrawForks();

		this->data_->window.display();
	}
}