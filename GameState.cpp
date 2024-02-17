#pragma once

#include <sstream>
#include "DEFINITIONS.hpp"
#include "GameState.hpp"
#include "GameOverState.hpp"
#include <iostream>

namespace Dumpling
{
	GameState::GameState(GameDataRef data) : data_(data)
	{

	}

	void GameState::Init()
	{
		this->data_->assets.LoadTexture("Game Background", GAME_BACKGROUND_FILEPATH);
		this->data_->assets.LoadTexture("Fork Up", FORK_UP_FILEPATH);
		this->data_->assets.LoadTexture("Fork Down", FORK_DOWN_FILEPATH);
		this->data_->assets.LoadTexture("Land", LAND_FILEPATH);
		this->data_->assets.LoadTexture("Dumpling", DUMPLING_FILEPATH);
		this->data_->assets.LoadTexture("Scoring Fork", SCORING_FORK_FILEPATH);
		this->data_->assets.LoadFont("Flappy Font", FLAPPY_FONT_FILEPATH);

		fork = new Fork(data_);
		land = new Land(data_);
		dumpling = new Dumpling(data_);
		flash = new Flash(data_);
		scores = new Scores(data_);

		background_.setTexture(this->data_->assets.GetTexture("Game Background"));

		score_ = 0;
		scores->UpdateScore(score_);

		gameState_ = GameStates::eReady;
	}

	void GameState::HandleInput()
	{
		sf::Event event;

		while (this->data_->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->data_->window.close();
			}

			if (this->data_->input.IsSpriteClicked(this->background_, sf::Mouse::Left, this->data_->window))
			{
				if (GameStates::eGameOver != gameState_)
				{
					gameState_ = GameStates::ePlaying;
					dumpling->Tap();
				}
			}
		}
	}

	void GameState::Update(float dt)
	{
		if (GameStates::eGameOver != gameState_)
		{
			
			land->MoveLand(dt);
		}

		if (GameStates::ePlaying == gameState_)
		{
			fork->MoveForks(dt);

			if (clock.getElapsedTime().asSeconds() > FORK_SPAWN_FREQUENCY)
			{
				fork->RandomiseForkOffset();

				fork->SpawnInvisibleFork();
				fork->SpawnBottomFork();
				fork->SpawnTopFork();
				fork->SpawnScoringFork();

				clock.restart();
			}

			dumpling->Update(dt);

			std::vector<sf::Sprite> landSprites = land->GetSprites();

			for (int i = 0; i < landSprites.size(); i++)
			{
				if (collision.CheckSpriteCollision(dumpling->GetSprite(), 0.7f, landSprites.at(i), 1.0f))
				{
					gameState_ = GameStates::eGameOver;
					clock.restart();
				}
			}

			std::vector<sf::Sprite> pipeSprites = fork->GetSprites();

			for (int i = 0; i < pipeSprites.size(); i++)
			{
				if (collision.CheckSpriteCollision(dumpling->GetSprite(), 0.625f, pipeSprites.at(i), 1.0f))
				{
					gameState_ = GameStates::eGameOver;
					clock.restart();
				}
			}

			if (GameStates::ePlaying == gameState_)
			{
				std::vector<sf::Sprite>& scoringSprites = fork->GetScoringSprites();

				for (int i = 0; i < scoringSprites.size(); i++)
				{
					if (collision.CheckSpriteCollision(dumpling->GetSprite(), 0.625f, scoringSprites.at(i), 1.0f))
					{
						score_++;

						scores->UpdateScore(score_);

						scoringSprites.erase(scoringSprites.begin() + i);
					}
				}

			}
		}

		if (GameStates::eGameOver == gameState_)
		{
			flash->Show(dt);

			if (clock.getElapsedTime().asSeconds() > TIME_BEFORE_GAMEOVER_APPEARS) {
				data_->machine.AddState(StateRef(new GameOverState(data_, score_)), true);
			}
		}

		

	}

	void GameState::Draw(float dt)
	{
		this->data_->window.clear(sf::Color::Red);

		this->data_->window.draw(this->background_);

		fork->DrawForks();
		land->DrawLand();
		dumpling->Draw();

		flash->Draw();

		scores->Draw();

		this->data_->window.display();
	}
}