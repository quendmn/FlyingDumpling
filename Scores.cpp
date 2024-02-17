#include "Scores.hpp"
#include <string>

namespace Dumpling {

	//инициализация - загрузка шрифта, размера и тд
	Scores::Scores(GameDataRef data) : data_(data) {
		scoreText_.setFont(data_->assets.GetFont("Flappy Font"));
		scoreText_.setString("0");
		scoreText_.setCharacterSize(72);
		scoreText_.setFillColor(sf::Color::White);
		scoreText_.setOutlineColor(sf::Color::Black);
		scoreText_.setOutlineThickness(2);
		scoreText_.setOrigin(scoreText_.getGlobalBounds().width/2,
			scoreText_.getGlobalBounds().height/ 2);
		scoreText_.setPosition(data_->window.getSize().x/2, data_->window.getSize().y / 5);
	}
	
	//отрисовать
	void Scores::Draw() {
		data_->window.draw(scoreText_);
	}

	// обновить кол-во очков
	void Scores::UpdateScore(int score) {
		scoreText_.setString(std::to_string(score));
	}

}