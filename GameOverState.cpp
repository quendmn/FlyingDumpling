#include <sstream>
#include "DEFINITIONS.hpp"
#include "GameOverState.hpp"
#include "GameState.hpp"
#include <iostream>
#include <fstream>

namespace Dumpling
{
	GameOverState::GameOverState(GameDataRef data, int score) : data_(data), score_(score)
	{

	}

	// инициализация
	void GameOverState::Init()
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

		hitSound_.setBuffer(hitBuffer_);
		hitSound_.setVolume(45.f);

		pointSound_.setBuffer(pointBuffer_);
		pointSound_.setVolume(45.f);

		wingSound_.setBuffer(wingBuffer_);
		wingSound_.setVolume(45.f);

		std::ifstream read;
		read.open("Resources/Highscore.txt");
		if (read.is_open())
		{
			while (!read.eof()) {
				read >> highScore_;
			}			
		}
		read.close();
		std::ofstream write("Resources/Highscore.txt");
		if (write.is_open()) {
			if (score_ > highScore_)
			{
				highScore_ = score_;
			}
			write << highScore_;
		}
		write.close();

		this->data_->assets.LoadTexture("Game Over Background", GAME_OVER_BACKGROUND_FILEPATH);
		background_.setTexture(this->data_->assets.GetTexture("Game Over Background"));

		this->data_->assets.LoadTexture("Game Over Title", GAME_OVER_TITLE_FILEPATH);	
		gameOverTitle_.setTexture(this->data_->assets.GetTexture("Game Over Title"));

		this->data_->assets.LoadTexture("Game Over Body", GAME_OVER_BODY_FILEPATH);
		gameOverBody_.setTexture(this->data_->assets.GetTexture("Game Over Body"));

		this->data_->assets.LoadTexture("Game Over Retry", GAME_OVER_RETRY_FILEPATH);
		gameOverRetry_.setTexture(this->data_->assets.GetTexture("Game Over Retry"));

		this->data_->assets.LoadTexture("Bronze Medal", BRONZE_MEDAL_FILEPATH);		

		this->data_->assets.LoadTexture("Silver Medal", SILVER_MEDAL_FILEPATH);		

		this->data_->assets.LoadTexture("Golden Medal", GOLDEN_MEDAL_FILEPATH);
		
		

		//расположение 
		gameOverBody_.setPosition(240, 220);

		gameOverTitle_.setPosition((data_->window.getSize().x / 2) - (gameOverTitle_.getGlobalBounds().width / 2),
			gameOverBody_.getPosition().y - (gameOverTitle_.getGlobalBounds().height * 1.2));

		gameOverRetry_.setPosition((data_->window.getSize().x / 2) - (gameOverRetry_.getGlobalBounds().width / 2),
			gameOverBody_.getPosition().y + (gameOverBody_.getGlobalBounds().height +
				gameOverRetry_.getGlobalBounds().height * 0.2));

		//очки
		scoreText_.setFont(data_->assets.GetFont("Flappy Font"));
		scoreText_.setString(std::to_string(score_));
		scoreText_.setCharacterSize(37);
		
		scoreText_.setFillColor(sf::Color(89,104,134,255));
		scoreText_.setOrigin(scoreText_.getGlobalBounds().width / 2, scoreText_.getGlobalBounds().height / 2);
		scoreText_.setPosition(675, 320);

		highScoreText_.setFont(data_->assets.GetFont("Flappy Font"));
		highScoreText_.setString(std::to_string(highScore_));
		highScoreText_.setCharacterSize(37);		
		highScoreText_.setFillColor(sf::Color(89, 104, 134, 255));
		highScoreText_.setOrigin(highScoreText_.getGlobalBounds().width / 2, highScoreText_.getGlobalBounds().height / 2);
		highScoreText_.setPosition(675, 415);

		if (score_ >= GOLDEN_MEDAL_SCORE) {
			medal_.setTexture(data_->assets.GetTexture("Golden Medal"));
		}
		else if (score_ >= SILVER_MEDAL_SCORE) {
			medal_.setTexture(data_->assets.GetTexture("Silver Medal"));
		}
		else if (score_ >= BRONZE_MEDAL_SCORE) {
			medal_.setTexture(data_->assets.GetTexture("Bronze Medal"));
		}

		medal_.setPosition(300, 321);
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

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				wingSound_.play();
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
		this->data_->window.draw(this->scoreText_);
		this->data_->window.draw(this->highScoreText_);
		this->data_->window.draw(this->medal_);
		this->data_->window.display();
	}
}