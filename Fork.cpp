#include "Fork.hpp"
namespace Dumpling
{
	Fork::Fork(GameDataRef data) : data_(data) {}

	// ������������� ������ �����
	void Fork::SpawnBottomFork()
	{
		sf::Sprite sprite(this->data_->assets.GetTexture("Fork Up Texture"));

		sprite.setPosition(this->data_->window.getSize().x, 357);

		forkSprites_.push_back(sprite);
	}

	// ������������� ������� �����
	void Fork::SpawnTopFork()
	{
		sf::Sprite sprite(this->data_->assets.GetTexture("Fork Down Texture"));

		sprite.setPosition(this->data_->window.getSize().x, 0);

		forkSprites_.push_back(sprite);
	}

	// ������������� ���������� �����
	void Fork::SpawnInvisibleFork()
	{
		sf::Sprite sprite(this->data_->assets.GetTexture("Fork Down Texture"));

		sprite.setPosition(this->data_->window.getSize().x, 0);
		sprite.setColor(sf::Color(0, 0, 0, 0));

		forkSprites_.push_back(sprite);
	}

	// �������� ����� �� ������
	void Fork::MoveForks(float dt)
	{
		for (unsigned short int i = 0; i < forkSprites_.size(); i++)
		{
			if (forkSprites_.at(i).getPosition().x < 0 -
				forkSprites_.at(i).getGlobalBounds().width) //�������� ���������, ��� ������ ���� � ������
			{
				forkSprites_.erase(forkSprites_.begin() + i);
			}
			else {

				float movement = FORK_MOVEMENT_SPEED * dt;

				forkSprites_.at(i).move(-movement, 0);
			}

		}
	}


	// ���������
	void Fork::DrawForks()
	{
		for (unsigned short int i = 0; i < forkSprites_.size(); i++)
		{
			this->data_->window.draw(forkSprites_.at(i));
		}
	}

}