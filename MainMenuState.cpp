
#include <sstream>
#include "DEFINITIONS.hpp"
#include "MainMenuState.hpp"
#include "SplashState.hpp"
#include "GameState.hpp"
#include <iostream>

namespace Dumpling
{
	MainMenuState::MainMenuState(GameDataRef data) : data_(data)
	{
		
	}

	// инициализация текстур
	void MainMenuState::Init()
	{
		if (!hitBuffer_.loadFromFile(HIT_SOUND_FILEPATH)) {
			std::cerr << "Oops :(";
		}
		if (!pointBuffer_.loadFromFile(POINT_SOUND_FILEPATH)) {
			std::cerr << "Oops :(";
		}
		if (!wingBuffer_.loadFromFile(CLICK_SOUND_FILEPATH)) {
			std::cerr << "Oops :(";
		}

		if (!musicBuffer_.loadFromFile(MUSIC_FILEPATH)) {
			std::cerr << "Oops :(";
		}

		hitSound_.setBuffer(hitBuffer_);
		hitSound_.setVolume(45.f);

		pointSound_.setBuffer(pointBuffer_);
		pointSound_.setVolume(45.f);

		wingSound_.setBuffer(wingBuffer_);
		wingSound_.setVolume(45.f);

		musicSound_.setBuffer(musicBuffer_);
		musicSound_.setVolume(50.f);

		this->data_->assets.LoadTexture("Main Menu Background", MAIN_MENU_BACKGROUND_FILEPATH);
		this->data_->assets.LoadTexture("Game Title", GAME_TITLE_FILEPATH);
		this->data_->assets.LoadTexture("Play Button", PLAY_BUTTON_FILEPATH);

		background_.setTexture(this->data_->assets.GetTexture("Main Menu Background"));
		title_.setTexture(this->data_->assets.GetTexture("Game Title"));
		playButton_.setTexture(this->data_->assets.GetTexture("Play Button"));

		title_.setPosition((SCREEN_WIDTH / 2) - (title_.getGlobalBounds().width / 2),
			246);
		playButton_.setPosition(406, 350);

		musicSound_.setVolume(7.f);
		musicSound_.play();
		
	}

	// обработка ввода
	void MainMenuState::HandleInput()
	{
		sf::Event event;

		while (this->data_->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->data_->window.close();
			}

			if (this->data_->input.IsSpriteClicked(this->playButton_,
			 sf::Mouse::Left, this->data_->window))
			{
				data_->machine.AddState(StateRef(new GameState(data_)), true);
			}

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				wingSound_.play();
			}
		}
	}

	// обновление
	void MainMenuState::Update(float dt)
	{

	}

	// отрисовка
	void MainMenuState::Draw(float dt)
	{
		this->data_->window.clear(sf::Color::Red);

		this->data_->window.draw(this->background_);
		this->data_->window.draw(this->title_);
		this->data_->window.draw(this->playButton_);

		this->data_->window.display();
	}
}