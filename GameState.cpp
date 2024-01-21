#include <sstream>
#include "GameState.hpp"
#include "DEFINITIONS.hpp"
//#include "MainMenuState.hpp"
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
		this->data_->assets.LoadTexture("Fork Up Texture", FORK_UP_FILEPATH);
		this->data_->assets.LoadTexture("Fork Down Texture", FORK_DOWN_FILEPATH);
		this->data_->assets.LoadTexture("Land", LAND_FILEPATH);
		this->data_->assets.LoadTexture("Dumpling", DUMPLING_FILEPATH);


		fork = new Fork(data_);
		land = new Land(data_);
		dumpling = new Dumpling(data_);

		background_.setTexture(this->data_->assets.GetTexture("Game Background"));

		gameState_ = GameStates::eReady;
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

			// лкм
			if (this->data_->input.IsSpriteClicked(this->background_,
				sf::Mouse::Left, this->data_->window))
			{
				if (GameStates::eGameOver != gameState_)
				{
					gameState_ = GameStates::ePlaying;
					dumpling->Tap();
				}
					
			}

		}
	}

	// обновление
	void GameState::Update(float dt)
	{
		if (GameStates::eGameOver != gameState_)
		{
			land->MoveLand(dt);
		}
		if (GameStates::ePlaying == gameState_)
		{
			fork->MoveForks(dt);

			if (clock_.getElapsedTime().asSeconds() > FORK_SPAWN_FREQUENCY)
			{
				fork->RandomiseForkOffset();

				fork->SpawnBottomFork();
				fork->SpawnTopFork();
				fork->SpawnInvisibleFork();

				clock_.restart();
			}

			dumpling->Update(dt);

			std::vector<sf::Sprite> landSprites = land->GetSprites();
			for (int i = 0; i < landSprites.size(); i++)
			{
				if (collision.CheckSpriteCollision(dumpling->GetSprite(), landSprites.at(i)))
				{
					gameState_ = GameStates::eGameOver;
				}
			}
		}
	}

	// отрисовка
	void GameState::Draw(float dt)
	{
		this->data_->window.clear(sf::Color::Red);

		this->data_->window.draw(this->background_);
		fork->DrawForks();
		land->DrawLand();
		dumpling->Draw();

		this->data_->window.display();
	}
}