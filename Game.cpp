#include "Game.hpp"
#include "SplashState.hpp"
#include "DEFINITIONS.hpp"

namespace Dumpling
{
	Game::Game(int width, int height, std::string title)
	{
		data_->window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);
		data_->machine.AddState(StateRef(new SplashState(this->data_)));

		this->icon_.loadFromFile(ICON_FILEPATH);
		data_->window.setIcon(32, 32, this->icon_.getPixelsPtr());

		this->Run();
	}

	void Game::Run()
	{
		float newTime, frameTime, interpolation;

		float currentTime = this->clock_.getElapsedTime().asSeconds();
		float accumulator = 0.0f;

		while (this->data_->window.isOpen())
		{
			this->data_->machine.ProcessStateChanges();

			newTime = this->clock_.getElapsedTime().asSeconds();
			frameTime = newTime - currentTime;

			if (frameTime > 0.25f)
			{
				frameTime = 0.25f;
			}

			currentTime = newTime;
			accumulator += frameTime;

			while (accumulator >= dt)
			{
				this->data_->machine.GetActiveState()->HandleInput();
				this->data_->machine.GetActiveState()->Update(dt);

				accumulator -= dt;
			}

			interpolation = accumulator / dt;
			this->data_->machine.GetActiveState()->Draw(interpolation);
		}
	}
}