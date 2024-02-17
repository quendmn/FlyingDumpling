#include <sstream>
#include "DEFINITIONS.hpp"
#include "GameOverState.hpp"
#include "GameState.hpp"
#include <iostream>

namespace Dumpling
{
	GameOverState::GameOverState(GameDataRef data) : data_(data)
	{

	}

	// инициализация
	void GameOverState::Init()
	{
		this->data_->assets.LoadTexture("Game Over Background", GAME_OVER_BACKGROUND_FILEPATH);
		background_.setTexture(this->data_->assets.GetTexture("Game Over Background"));

		this->data_->assets.LoadTexture("Game Over Title", GAME_OVER_TITLE_FILEPATH);	
		gameOverTitle_.setTexture(this->data_->assets.GetTexture("Game Over Title"));

		this->data_->assets.LoadTexture("Game Over Body", GAME_OVER_BODY_FILEPATH);
		gameOverBody_.setTexture(this->data_->assets.GetTexture("Game Over Body"));

		this->data_->assets.LoadTexture("Game Over Retry", GAME_OVER_RETRY_FILEPATH);
		gameOverRetry_.setTexture(this->data_->assets.GetTexture("Game Over Retry"));
		

		//расположение 
		gameOverBody_.setPosition((data_->window.getSize().x / 2) - (gameOverBody_.getGlobalBounds().width / 2),
			(data_->window.getSize().y / 2) - (gameOverBody_.getGlobalBounds().height / 2));

		gameOverTitle_.setPosition((data_->window.getSize().x / 2) - (gameOverTitle_.getGlobalBounds().width / 2),
			gameOverBody_.getPosition().y - (gameOverTitle_.getGlobalBounds().height * 1.2));

		gameOverRetry_.setPosition((data_->window.getSize().x / 2) - (gameOverRetry_.getGlobalBounds().width / 2),
			gameOverBody_.getPosition().y + (gameOverBody_.getGlobalBounds().height +
				gameOverRetry_.getGlobalBounds().height * 0.2));

	}

	//обработка действий пользователя
	void GameOverState::HandleInput()
	{
		sf::Event event;

		while (this->data_->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->data_->window.close();
			}

			if (data_->input.IsSpriteClicked(gameOverRetry_, sf::Mouse::Left, data_->window )) {
				data_->machine.AddState(StateRef(new GameState(data_)), true);
			}
		}
	}

	// обновление
	void GameOverState::Update(float dt)
	{

	}

	// отрисовка
	void GameOverState::Draw(float dt)
	{
		this->data_->window.clear(sf::Color::Red);

		this->data_->window.draw(this->background_);
		this->data_->window.draw(this->gameOverTitle_);
		this->data_->window.draw(this->gameOverBody_);
		this->data_->window.draw(this->gameOverRetry_);


		this->data_->window.display();
	}
}