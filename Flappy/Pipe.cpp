#include "Pipe.hpp"
#include "DEFINITIONS.hpp"

namespace Flappy {
	Pipe::Pipe(GameDataRef data) : _data(data) {
		_landHeight = _data->assets.GetTexture("Land").getSize().y;
		
		_pipeSpawnYOffset = 0;
	}

	void Pipe::DrawPipes() {
		for (int i = 0; i < pipeSprites.size(); i++) {
			_data->window.draw(pipeSprites.at(i));
		}
	}

	void Pipe::SpawnBottomPipe() {
		Sprite sprite(_data->assets.GetTexture("Pipe Up"));
		sprite.setPosition(_data->window.getSize().x, _data->window.getSize().y - sprite.getGlobalBounds().height - _pipeSpawnYOffset);
		
		pipeSprites.push_back(sprite);
	}

	void Pipe::SpawnTopPipe() {
		Sprite sprite(_data->assets.GetTexture("Pipe Down"));
		sprite.setPosition(_data->window.getSize().x, -_pipeSpawnYOffset);
		
		pipeSprites.push_back(sprite);
	}

	void Pipe::SpawnInvisiblePipe() {
		Sprite sprite(_data->assets.GetTexture("Pipe Up"));
		sprite.setPosition(_data->window.getSize().x, _data->window.getSize().y - sprite.getGlobalBounds().height);
		
		sprite.setColor(Color::Transparent);
		
		pipeSprites.push_back(sprite);
	}

	void Pipe::SpawnScoringPipe() {
		Sprite sprite(_data->assets.GetTexture("Scoring Pipe"));
		sprite.setPosition(_data->window.getSize().x, 0.0f);
		
		sprite.setColor(Color::Transparent);
		
		scoringPipes.push_back(sprite);
	}

	void Pipe::RandomizePipeOffset() {
		_pipeSpawnYOffset = rand() % _landHeight + 1;
	}

	void Pipe::MovePipes(float dt) {
		for (int i = 0; i < pipeSprites.size(); i++) {
			if (pipeSprites.at(i).getPosition().x < 0 - pipeSprites.at(i).getGlobalBounds().width) {
				pipeSprites.erase(pipeSprites.begin() + i);
			}
			else {
				float movement = PIPE_SPEED * dt;
				pipeSprites.at(i).move(-movement, 0);
			}
		}
		
		for (int i = 0; i < scoringPipes.size(); i++) {
			if (scoringPipes.at(i).getPosition().x < 0 - scoringPipes.at(i).getGlobalBounds().width) {
				scoringPipes.erase(scoringPipes.begin() + i);
			}
			else {
				float movement = PIPE_SPEED * dt;
				scoringPipes.at(i).move(-movement, 0);
			}
		}
		
	}

	const vector<sf::Sprite> &Pipe::GetSprites() const {
		return pipeSprites;
	}

	vector<sf::Sprite> &Pipe::GetScoringPipes() {
		return scoringPipes;
	}

}
