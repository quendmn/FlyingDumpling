#include "Fork.hpp"
namespace Dumpling
{
	Fork::Fork(GameDataRef data) : data_(data) {
	
		landHeight_ = data->assets.GetTexture("Land").getSize().y;

		forkSpawnYOffset_ = 0;
	}

	// сгенерировать нижнюю вилку
	void Fork::SpawnBottomFork()
	{
		sf::Sprite sprite(this->data_->assets.GetTexture("Fork Up Texture"));

		sprite.setPosition(data_->window.getSize().x, data_->window.getSize().y -
			sprite.getGlobalBounds().height - forkSpawnYOffset_);

		forkSprites_.push_back(sprite);
	}

	// сгенерировать верхнюю вилку
	void Fork::SpawnTopFork()
	{
		sf::Sprite sprite(this->data_->assets.GetTexture("Fork Down Texture"));

		sprite.setPosition(this->data_->window.getSize().x, -forkSpawnYOffset_);

		forkSprites_.push_back(sprite);
	}

	// сгенерировать прозрачную вилку
	void Fork::SpawnInvisibleFork()
	{
		sf::Sprite sprite(this->data_->assets.GetTexture("Fork Down Texture"));

		sprite.setPosition(this->data_->window.getSize().x, 0);
		sprite.setColor(sf::Color(0, 0, 0, 0));

		forkSprites_.push_back(sprite);
	}

	// сгенерировать прозрачную вилку
	void Fork::SpawnScoringFork()
	{
		sf::Sprite sprite(this->data_->assets.GetTexture("Fork Down Texture"));

		sprite.setPosition(this->data_->window.getSize().x, 0);
		sprite.setColor(sf::Color(0, 0, 0, 0));

		forkSprites_.push_back(sprite);
	}


	// движение вилок на экране
	void Fork::MoveForks(float dt)
	{
		for (unsigned short int i = 0; i < forkSprites_.size(); i++)
		{
			if (forkSprites_.at(i).getPosition().x < 0 -
				forkSprites_.at(i).getGlobalBounds().width) //удаление прошедших, как только ушли с экрана
			{
				forkSprites_.erase(forkSprites_.begin() + i);
			}
			else {

				float movement = FORK_MOVEMENT_SPEED * dt;

				forkSprites_.at(i).move(-movement, 0);
			}

		}
	}


	// отрисовка
	void Fork::DrawForks()
	{
		for (unsigned short int i = 0; i < forkSprites_.size(); i++)
		{
			this->data_->window.draw(forkSprites_.at(i));
		}
	}

	// рандомное появление вилок на карте
	void Fork::RandomiseForkOffset()
	{
		//forkSpawnYOffset_ = rand() % (landHeight_ + 1) + 357;
		forkSpawnYOffset_ = rand() % (landHeight_ + 1);
	}

	// для столкновения с вилками
	const std::vector<sf::Sprite>& Fork::GetSprites() const {
		return forkSprites_;
	}

}