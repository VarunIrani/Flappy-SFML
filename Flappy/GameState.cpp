#include "GameState.hpp"
#include <sstream>
#include "DEFINITIONS.hpp"
#include <iostream>
#include "GameOverState.hpp"

using namespace std;
using namespace sf;

namespace Flappy {
	GameState::GameState(GameDataRef data) : _data(data){
		
	}

	void GameState::Init() {
		if (!_hitSoundBuffer.loadFromFile(HIT_SOUND))
			cout << "\nError Loading Hit Sound";
		
		if (!_wingSoundBuffer.loadFromFile(WING_SOUND))
			cout << "\nError Loading Wing Sound";
		
		if (!_pointSoundBuffer.loadFromFile(POINT_SOUND))
			cout << "\nError Loading Point Sound";
		
		_hitSound.setBuffer(_hitSoundBuffer);
		_wingSound.setBuffer(_wingSoundBuffer);
		_pointSound.setBuffer(_pointSoundBuffer);
		
		_data->assets.LoadTexture("Game State Background", GAME_BACKGROUND);
		_data->assets.LoadTexture("Pipe Up", PIPE_UP);
		_data->assets.LoadTexture("Pipe Down", PIPE_DOWN);
		_data->assets.LoadTexture("Scoring Pipe", SCORING_PIPE);
		_data->assets.LoadTexture("Land", LAND_PATH);
		_data->assets.LoadTexture("Bird Frame 1", BIRD_FRAME_1);
		_data->assets.LoadTexture("Bird Frame 2", BIRD_FRAME_2);
		_data->assets.LoadTexture("Bird Frame 3", BIRD_FRAME_3);
		_data->assets.LoadTexture("Bird Frame 4", BIRD_FRAME_4);
		_data->assets.LoadFont("Flappy Font", FLAPPY_FONT);
		
		pipe = new Pipe(_data);
		land = new Land(_data);
		bird = new Bird(_data);
		flash = new Flash(_data);
		hud = new HUD(_data);
		
		_background.setTexture(this->_data->assets.GetTexture("Game State Background"));
		
		state = GameStates::READY;
		_score = 0;
		
		hud->UpdateScore(_score);
		
	}

	void GameState::HandleInput() {
		Event e;
		while (_data->window.pollEvent(e)) {
			if (Event::Closed == e.type) {
				_data->window.close();
			}
			
			if (_data->input.IsSpriteClicked(_background, Mouse::Left, _data->window)) {
				if (state != GameStates::GAME_OVER) {
					state = GameStates::PLAYING;
					bird->Tap();
					_wingSound.play();
				}
			} else {
				bird->state = BirdState::FALLING;
			}
		}
	}

	void GameState::Update(float dt) {
		if (state != GameStates::GAME_OVER) {
			land->MoveLand(dt);
			bird->Animate(dt);
		}
		
		if (state == GameStates::PLAYING) {
			pipe->MovePipes(dt);
			if (_clock.getElapsedTime().asSeconds() > PIPE_SPAWN_FREQUENCY) {
				
				pipe->RandomizePipeOffset();
				pipe->SpawnInvisiblePipe();
				pipe->SpawnBottomPipe();
				pipe->SpawnTopPipe();
				pipe->SpawnScoringPipe();

				_clock.restart();
			}
			bird->Update(dt);
			
			vector<Sprite> landSprites = land->GetSprites();
			for (int i = 0; i < landSprites.size(); i++) {
				if (collision.CheckSpriteCollision(bird->GetSprite(), landSprites.at(i))) {
					state = GameStates::GAME_OVER;
					_clock.restart();
					_hitSound.play();
				}
			}
			
			vector<Sprite> pipeSprites = pipe->GetSprites();
			for (int i = 0; i < pipeSprites.size(); i++) {
				if (collision.CheckSpriteCollision(bird->GetSprite(), 1.0f, pipeSprites.at(i), 1.0f)) {
					state = GameStates::GAME_OVER;
					_clock.restart();
					_hitSound.play();
				}
			}
			
			if (state == GameStates::PLAYING) {
				vector<Sprite> &scoringPipes = pipe->GetScoringPipes();
				for (int i = 0; i < scoringPipes.size(); i++) {
					if (collision.CheckSpriteCollision(bird->GetSprite(), scoringPipes.at(i))) {
						_score++;
						_pointSound.play();
						hud->UpdateScore(_score);
						scoringPipes.erase(scoringPipes.begin() + i);
					}
				}
			}
		}
		
		if (state == GameStates::GAME_OVER) {
			flash->Show(dt);
			if (_clock.getElapsedTime().asSeconds() > TIME_BEFORE_GAME_OVER) {
				_data->machine.AddState(StateRef(new GameOverState(_data, _score)), true);
			}
		}
		
	}

	void GameState::Draw(float dt) {
		_data->window.clear(Color::Black);
		_data->window.draw(_background);
		pipe->DrawPipes();
		land->DrawLand();
		bird->Draw();
		flash->Draw();
		hud->Draw();
		_data->window.display();
	}
}



