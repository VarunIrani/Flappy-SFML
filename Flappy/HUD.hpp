#pragma once
#include <SFML/Graphics.hpp>
#include "DEFINITIONS.hpp"
#include "Game.hpp"

using namespace sf;

namespace Flappy {
class HUD {
public:
	HUD(GameDataRef data);
	void Draw();
	void UpdateScore(int score);
	
private:
	GameDataRef _data;
	Text _scoreText;
};
}
