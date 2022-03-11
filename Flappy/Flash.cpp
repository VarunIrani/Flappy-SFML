#include "Flash.hpp"

namespace Flappy {
	Flash::Flash(Flappy::GameDataRef data) : _data(data){
		_shape = RectangleShape(Vector2f(data->window.getSize()));
		_shape.setFillColor(Color(255, 255, 255, 0));
		flashOn = true;
	}

	void Flash::Show(float dt) {
		if (flashOn) {
			int alpha = (int) _shape.getFillColor().a + FLASH_SPEED * dt;
			if (alpha >= 255.0f) {
				alpha = 255.0f;
				flashOn = false;
			}
			_shape.setFillColor(Color(255, 255, 255, alpha));
		} else {
			int alpha = (int) _shape.getFillColor().a - FLASH_SPEED * dt;
			if (alpha < 0.0f) {
				alpha = 0.0f;
				flashOn = false;
			}
			_shape.setFillColor(Color(255, 255, 255, alpha));
		}
	}

	void Flash::Draw() {
		_data->window.draw(_shape);
	}
}


