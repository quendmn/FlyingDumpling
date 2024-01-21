#include "Land.hpp"
#include "DEFINITIONS.hpp"

namespace Dumpling
{
	Land::Land(GameDataRef data) : data_(data)
	{
		sf::Sprite sprite(this->data_->assets.GetTexture("Land"));
		sf::Sprite sprite2(this->data_->assets.GetTexture("Land"));

		sprite.setPosition(0, this->data_->window.getSize().y - sprite.getLocalBounds().height);
		sprite2.setPosition(sprite.getLocalBounds().width, this->data_->window.getSize().y - sprite2.getLocalBounds().height);

		landSprites_.push_back(sprite);
		landSprites_.push_back(sprite2);
	}

	void Land::MoveLand(float dt)
	{
		for (unsigned short int i = 0; i < landSprites_.size(); i++)
		{
			sf::Vector2f position = landSprites_.at(i).getPosition();
			float movement = FORK_MOVEMENT_SPEED * dt;

			landSprites_.at(i).move(-movement, 0.0f);

			if (landSprites_.at(i).getPosition().x < 0 - landSprites_.at(i).getLocalBounds().width)
			{
				sf::Vector2f position(data_->window.getSize().x, landSprites_.at(i).getPosition().y);

				landSprites_.at(i).setPosition(position);
			}
		}
	}

	void Land::DrawLand()
	{
		for (unsigned short int i = 0; i < landSprites_.size(); i++)
		{
			this->data_->window.draw(landSprites_.at(i));
		}
	}

	const std::vector<sf::Sprite>& Land::GetSprites() const {
		return landSprites_;
	}



}