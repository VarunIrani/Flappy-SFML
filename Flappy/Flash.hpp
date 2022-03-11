#pragma once

#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include "DEFINITIONS.hpp"

using namespace sf;

namespace Flappy {
class Flash {
public:
	Flash(GameDataRef data);
	
	void Show(float dt);
	void Draw();
	
private:
	GameDataRef _data;
	
	RectangleShape _shape;
	
	bool flashOn;
};
}
