#include "Bird.hpp"

namespace Flappy {
	Bird::Bird(GameDataRef data) : _data(data) {
		animationIterator = 0;
		animationFrames.push_back(_data->assets.GetTexture("Bird Frame 1"));
		animationFrames.push_back(_data->assets.GetTexture("Bird Frame 2"));
		animationFrames.push_back(_data->assets.GetTexture("Bird Frame 3"));
		animationFrames.push_back(_data->assets.GetTexture("Bird Frame 4"));
		birdSprite.setTexture(animationFrames.at(animationIterator));
		
		birdSprite.setPosition(_data->window.getSize().x / 4 - birdSprite.getGlobalBounds().width / 2, _data->window.getSize().y / 2 - birdSprite.getGlobalBounds().height / 2);
		
		state = BirdState::STILL;
		delta = 0;
	}

	void Bird::Draw() {
		_data->window.draw(birdSprite);
	}

	void Bird::Animate(float dt) {
		if (_clock.getElapsedTime().asSeconds() > BIRD_ANIMATION_DURATION / animationFrames.size()) {
			if (animationIterator < animationFrames.size() - 1) {
				animationIterator++;
			} else {
				animationIterator = 0;
			}
			birdSprite.setTexture(animationFrames.at(animationIterator));
			_clock.restart();
		}
	}

	void Bird::Update(float dt) {
		birdSprite.move(0, delta);
		if (state == BirdState::FALLING) {
			delta += GRAVITY * dt;
		}	else if (state == BirdState::FLYING){
			delta = -7;
		}
		if (_movementClock.getElapsedTime().asSeconds() > FLYING_DURATION) {
			_movementClock.restart();
			state = BirdState::FALLING;
		}
	}

	void Bird::Tap() {
		_movementClock.restart();
		state = BirdState::FLYING;
	}

	const sf::Sprite &Bird::GetSprite() const {
		return birdSprite;
	}



}
