#include "Land.hpp"
#include "DEFINITIONS.hpp"

namespace Flappy {
	Land::Land(GameDataRef data) : _data(data) {
		Sprite sprite(data->assets.GetTexture("Land"));
		Sprite sprite2(data->assets.GetTexture("Land"));
		
		sprite.setPosition(0, _data->window.getSize().y - sprite.getGlobalBounds().height);
		sprite2.setPosition(sprite.getGlobalBounds().width, _data->window.getSize().y - sprite.getGlobalBounds().height);
		
		landSprites.push_back(sprite);
		landSprites.push_back(sprite2);
	}

	void Land::MoveLand(float dt) {
		for (int i = 0; i < landSprites.size(); i++) {
			float movement = PIPE_SPEED * dt;
			landSprites.at(i).move(-movement, 0);
			
			if (landSprites.at(i).getPosition().x < 0 - landSprites.at(i).getGlobalBounds().width) {
				Vector2f position(_data->window.getSize().x, landSprites.at(i).getPosition().y);
				landSprites.at(i).setPosition(position);
			}
		}
	}
	void Land::DrawLand() {
		for (int i = 0; i < landSprites.size(); i++) {
			_data->window.draw(landSprites.at(i));
		}
	}

	const vector<sf::Sprite> &Land::GetSprites() const {
		return landSprites;
	}

}
