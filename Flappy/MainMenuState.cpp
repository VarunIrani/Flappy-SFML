#include "MainMenuState.hpp"
#include "GameState.hpp"
#include <sstream>
#include "DEFINITIONS.hpp"
#include <iostream>

using namespace std;
using namespace sf;

namespace Flappy {
	MainMenuState::MainMenuState(GameDataRef data) : _data(data){
		
	}

	void MainMenuState::Init() {
		_data->assets.LoadTexture("Main Menu State Background", MAIN_BACKGROUND);
		_data->assets.LoadTexture("Title", TITLE_PATH);
		_data->assets.LoadTexture("Play Button", PLAY_BUTTON_PATH);
		_background.setTexture(this->_data->assets.GetTexture("Main Menu State Background"));
		_title.setTexture(this->_data->assets.GetTexture("Title"));
		_playButton.setTexture(this->_data->assets.GetTexture("Play Button"));
		
		_title.setPosition((SCREEN_WIDTH / 2) - (_title.getGlobalBounds().width / 2), (_title.getGlobalBounds().height / 2));
		
		_playButton.setPosition(SCREEN_WIDTH / 2 - _playButton.getGlobalBounds().width / 2, SCREEN_HEIGHT / 2 - _title.getGlobalBounds().height / 2);
	}

	void MainMenuState::HandleInput() {
		Event e;
		while (_data->window.pollEvent(e)) {
			if (Event::Closed == e.type) {
				_data->window.close();
			}
			
			if (_data->input.IsSpriteClicked(_playButton, Mouse::Left, _data->window)) {
				_data->machine.AddState(StateRef(new GameState(_data)), true);
			}
		}
	}

	void MainMenuState::Update(float dt) {
	}

	void MainMenuState::Draw(float dt) {
		_data->window.clear(Color::Black);
		_data->window.draw(_background);
		_data->window.draw(_title);
		_data->window.draw(_playButton);
		_data->window.display();
	}
}



