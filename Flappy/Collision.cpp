#include "Collision.hpp"

namespace Flappy {
	Collision::Collision() {}

	bool Collision::CheckSpriteCollision(sf::Sprite sprite1, sf::Sprite sprite2) {
		Rect<float> rect1 = sprite1.getGlobalBounds();
		Rect<float> rect2 = sprite2.getGlobalBounds();
		
		if (rect1.intersects(rect2))
			return true;
		else
			return false;
	}

	bool Collision::CheckSpriteCollision(sf::Sprite sprite1, float scale1, sf::Sprite sprite2, float scale2) {
		sprite1.setScale(scale1, scale2);
		sprite2.setScale(scale1, scale2);
		
		Rect<float> rect1 = sprite1.getGlobalBounds();
		Rect<float> rect2 = sprite2.getGlobalBounds();
		
		if (rect1.intersects(rect2))
			return true;
		else
			return false;
	}


}

