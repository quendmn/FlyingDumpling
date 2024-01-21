#include "Dumpling.hpp"

namespace Dumpling
{
	// инициализация текстурки
	Dumpling::Dumpling(GameDataRef data) : data_(data)
	{
		dumplingSprite_.setTexture(this->data_->assets.GetTexture("Dumpling"));

		dumplingSprite_.setPosition((data_->window.getSize().x / 4) - (
			dumplingSprite_.getGlobalBounds().width / 2),
			(data_->window.getSize().y / 2) - (
				dumplingSprite_.getGlobalBounds().height / 2));

		dumplingState_ = DUMPLING_STATE_STILL;

	}

	Dumpling::~Dumpling()
	{
	}

	// отрисовка
	void Dumpling::Draw()
	{
		data_->window.draw(dumplingSprite_);
	}

	void Dumpling::Update(float dt) {
		if (DUMPLING_STATE_FALLING == dumplingState_)
		{
			dumplingSprite_.move(0, GRAVITY * dt);
		}
		else if (DUMPLING_STATE_FLYING == dumplingState_) {
			dumplingSprite_.move(0, -FLYING_SPEED * dt);
		}

		if (movementClock_.getElapsedTime().asSeconds() > FLYING_DURATION) {
			movementClock_.restart();
			dumplingState_ = DUMPLING_STATE_FALLING;
		}
	}

	void Dumpling::Tap(){
		movementClock_.restart();

		dumplingState_ = DUMPLING_STATE_FLYING;

	}

	const sf::Sprite& Dumpling::GetSprite() const {
		return dumplingSprite_;
	}


}