#include "Game.hpp"
#include "SplashState.hpp"

namespace Pelmen {
	Game::Game(int width, int height, std::string title)
	{
		data_->window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);
		data_->machine.AddState(StateRef(new SplashState(this->data_)));
		this->Run();
	}

	void Game::Run()
	{
		float newTime, frameTime, interpolation;

		float currentTime = this->clock_.getElapsedTime().asSeconds();
		float accumulator = 0.0f; // общее время
		
		while (this->data_->window.isOpen())
		{
			// обработка изменений
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
