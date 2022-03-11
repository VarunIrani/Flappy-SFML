#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

namespace Flappy {
	class InputManager {
	public:
		InputManager() {}
		~InputManager() {}
		
		bool IsSpriteClicked(Sprite object, Mouse::Button button, RenderWindow &window);
        bool IsSpacePressed();
		Vector2i GetMousePosition(RenderWindow &window);
	};
}

