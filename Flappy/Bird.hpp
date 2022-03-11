#pragma once
#include <SFML/Graphics.hpp>
#include "DEFINITIONS.hpp"
#include <vector>

#include "Game.hpp"

using namespace sf;
using namespace std;

namespace Flappy {
	class Bird {
	public:
		Bird(GameDataRef data);
		
		void Draw();
		void Animate(float dt);
		
		void Update(float dt);
		
		void Tap();
		
		const Sprite& GetSprite() const;
		
		
		BirdState state;
		
	private:
		GameDataRef _data;
		Sprite birdSprite;
		vector<Texture> animationFrames;
		int animationIterator;
		
		Clock _clock;
		Clock _movementClock;
		
		float delta;
		
	};
}
