#pragma once

#include <sstream>
#include "SplashState.hpp"
#include "DEFINITIONS.hpp"

#include <iostream>

namespace Dumpling
{
	SplashState::SplashState(GameDataRef data) : data_(data)
	{

	}

	// инициализация
	void SplashState::Init()
	{
		this->data_->assets.LoadTexture("Splash State Background", SPLASH_SCENE_BACKGROUND_FILEPATH);
		background_.setTexture(this->data_->assets.GetTexture("Splash State Background"));

	}

	//обработка действий пользователя
	void SplashState::HandleInput()
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

	// обновление
	void SplashState::Update(float dt)
	{
		if (this->clock_.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME)
		{
			std::cout << "exit" << std::endl;
		}
	}

	// отрисовка
	void SplashState::Draw(float dt)
	{
		this->data_->window.clear(sf::Color::Red);

		this->data_->window.draw(this->background_);

		this->data_->window.display();
	}
}