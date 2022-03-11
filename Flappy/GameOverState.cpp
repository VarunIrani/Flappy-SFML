#include "GameOverState.hpp"
#include <sstream>
#include "DEFINITIONS.hpp"
#include <iostream>
#include "GameState.hpp"
#include <fstream>

using namespace std;
using namespace sf;

namespace Flappy {
	GameOverState::GameOverState(GameDataRef data, int score) : _data(data), _score(score) {
		
	}

	void GameOverState::Init() {
		ifstream readFile;
		readFile.open("Resources/Highscore.txt");
		if (readFile.is_open()) {
			while (!readFile.eof()) {
				readFile >> _highScore;
			}
		}
		readFile.close();
		ofstream writeFile;
		writeFile.open("Resources/Highscore.txt");
		if (writeFile.is_open()) {
			if (_score > _highScore) {
				_highScore = _score;
			}
			
			writeFile << _highScore;
		}
		writeFile.close();
		_data->assets.LoadTexture("Game Over State Background", GAME_OVER_BACKGROUND);
		_data->assets.LoadTexture("Game Over Title", GAME_OVER_TITLE);
		_data->assets.LoadTexture("Game Over Body", GAME_OVER_BODY);
		_data->assets.LoadTexture("Bronze Medal", BRONZE_MEDAL);
		_data->assets.LoadTexture("Silver Medal", SILVER_MEDAL);
		_data->assets.LoadTexture("Gold Medal", GOLD_MEDAL);
		_data->assets.LoadTexture("Platinum Medal", PLATINUM_MEDAL);
		
		_background.setTexture(this->_data->assets.GetTexture("Game Over State Background"));
		_gameOverTitle.setTexture(this->_data->assets.GetTexture("Game Over Title"));
		_gameOverBody.setTexture(this->_data->assets.GetTexture("Game Over Body"));
		_retryButton.setTexture(this->_data->assets.GetTexture("Play Button"));
		
		_gameOverBody.setPosition(_data->window.getSize().x / 2 - _gameOverBody.getGlobalBounds().width / 2, _data->window.getSize().y / 2 - _gameOverBody.getGlobalBounds().height / 2);
		
		_gameOverTitle.setPosition(_data->window.getSize().x / 2 - _gameOverTitle.getGlobalBounds().width / 2, _gameOverBody.getPosition().y - _gameOverTitle.getGlobalBounds().height * 1.2);
		
		_retryButton.setPosition(_data->window.getSize().x / 2 - _retryButton.getGlobalBounds().width / 2, _gameOverBody.getPosition().y + _gameOverBody.getGlobalBounds().height + _retryButton.getGlobalBounds().height * 0.2);
		
		_scoreText.setFont(_data->assets.GetFont("Flappy Font"));
		_scoreText.setString(to_string(_score));
		_scoreText.setCharacterSize(56);
		_scoreText.setFillColor(Color(63, 31, 9));
		_scoreText.setOrigin(_scoreText.getGlobalBounds().width / 2, _scoreText.getGlobalBounds().height / 2);
		_scoreText.setPosition(_data->window.getSize().x / 10 * 7.25, _data->window.getSize().y / 2.15);
		
		_highScoreText.setFont(_data->assets.GetFont("Flappy Font"));
		_highScoreText.setString(to_string(_highScore));
		_highScoreText.setCharacterSize(56);
		_highScoreText.setFillColor(Color(63, 31, 9));
		_highScoreText.setOrigin(_highScoreText.getGlobalBounds().width / 2, _highScoreText.getGlobalBounds().height / 2);
		_highScoreText.setPosition(_data->window.getSize().x / 10 * 7.25, _data->window.getSize().y / 1.78);
		string tex = "";
		if (_score >= PLATINUM_SCORE) {
			tex = "Platinum Medal";
		} else if (_score >= GOLD_SCORE) {
			tex = "Gold Medal";
		} else if (_score >= SILVER_SCORE) {
			tex = "Silver Medal";
		} else {
			tex = "Bronze Medal";
		}
		_medal.setTexture(_data->assets.GetTexture(tex));
		_medal.setPosition(175, 465);
	}

	void GameOverState::HandleInput() {
		Event e;
		while (_data->window.pollEvent(e)) {
			if (Event::Closed == e.type) {
				_data->window.close();
			}
			if (_data->input.IsSpriteClicked(_retryButton, Mouse::Left, _data->window)) {
				_data->machine.AddState(StateRef(new GameState(_data)), true);
			}
		}
	}

	void GameOverState::Update(float dt) {

	}

	void GameOverState::Draw(float dt) {
		_data->window.clear(Color::Black);
		_data->window.draw(_background);
		_data->window.draw(_gameOverTitle);
		_data->window.draw(_gameOverBody);
		_data->window.draw(_retryButton);
		_data->window.draw(_scoreText);
		_data->window.draw(_highScoreText);
		_data->window.draw(_medal);
		_data->window.display();
	}
}



