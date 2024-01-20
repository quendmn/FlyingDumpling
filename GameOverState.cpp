#include <sstream>
#include "DEFINITIONS.hpp"
#include "GameOverState.hpp"
#include <iostream>

namespace Dumpling
{
	GameOverState::GameOverState(GameDataRef data) : data_(data)
	{

	}

	// �������������
	void GameOverState::Init()
	{
		this->data_->assets.LoadTexture("Game Over Background", GAME_OVER_BACKGROUND_FILEPATH);
		background_.setTexture(this->data_->assets.GetTexture("Game Over Background"));

	}

	//��������� �������� ������������
	void GameOverState::HandleInput()
	{
		sf::Event event;

		while (this->data_->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->data_->window.close();
			}
		}
	}

	// ����������
	void GameOverState::Update(float dt)
	{

	}

	// ���������
	void GameOverState::Draw(float dt)
	{
		this->data_->window.clear(sf::Color::Red);

		this->data_->window.draw(this->background_);

		this->data_->window.display();
	}
}