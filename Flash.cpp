#include "Flash.hpp"

namespace Dumpling
{
	Flash::Flash(GameDataRef data) : data_(data)
	{
		shape_ = sf::RectangleShape(sf::Vector2f(data_->window.getSize().x, data_->window.getSize().y));
		shape_.setFillColor(sf::Color(255, 255, 255, 0));

		flashOn_ = true;
	}

	Flash::~Flash()
	{
	}

	//вспышка
	void Flash::Show(float dt)
	{
		if (flashOn_)
		{
			int alpha = (int)shape_.getFillColor().a + (FLASH_SPEED * dt);

			if (alpha >= 255.0f)
			{
				alpha = 255.0f;
				flashOn_ = false;
			}

			shape_.setFillColor(sf::Color(255, 255, 255, alpha));
		}
		else
		{
			int alpha = (int)shape_.getFillColor().a - (FLASH_SPEED * dt);

			if (alpha <= 0.0f)
			{
				alpha = 0.0f;
			}

			shape_.setFillColor(sf::Color(255, 255, 255, alpha));
		}
	}

	//отрисовать
	void Flash::Draw()
	{
		data_->window.draw(shape_);
	}
}