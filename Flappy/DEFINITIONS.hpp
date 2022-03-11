#pragma once
#include <string>
using namespace std;

const int SCREEN_WIDTH = 768;
const int SCREEN_HEIGHT = 1024;

const string MAIN_BACKGROUND = "Resources/res/sky.png";

const string TITLE_PATH = "Resources/res/title.png";
const string PLAY_BUTTON_PATH = "Resources/res/PlayButton.png";

const string GAME_BACKGROUND = MAIN_BACKGROUND;
const string GAME_OVER_BACKGROUND = MAIN_BACKGROUND;

const string PIPE_UP = "Resources/res/PipeUp.png";
const string PIPE_DOWN = "Resources/res/PipeDown.png";
const string SCORING_PIPE = "Resources/res/InvisibleScoringPipe.png";

const float PIPE_SPEED = 200.0f;

const float PIPE_SPAWN_FREQUENCY = 1.5f;

const string LAND_PATH = "Resources/res/Land.png";

const string BIRD_FRAME_1 ="Resources/res/bird-01.png";
const string BIRD_FRAME_2 ="Resources/res/bird-02.png";
const string BIRD_FRAME_3 ="Resources/res/bird-03.png";
const string BIRD_FRAME_4 ="Resources/res/bird-04.png";

const string FLAPPY_FONT = "Resources/fonts/FlappyFont.ttf";

const string GAME_OVER_TITLE = "Resources/res/Game-Over-Title.png";
const string GAME_OVER_BODY = "Resources/res/Game-Over-Body.png";

const string BRONZE_MEDAL ="Resources/res/Bronze-Medal.png";
const string SILVER_MEDAL ="Resources/res/Silver-Medal.png";
const string GOLD_MEDAL ="Resources/res/Gold-Medal.png";
const string PLATINUM_MEDAL ="Resources/res/Platinum-Medal.png";

const string HIT_SOUND = "Resources/audio/Hit.wav";
const string POINT_SOUND = "Resources/audio/Point.wav";
const string WING_SOUND = "Resources/audio/Wing.wav";

const float BIRD_ANIMATION_DURATION = 0.4f;

enum BirdState {
	STILL,
	FALLING,
	FLYING
};

enum GameStates {
	READY,
	PLAYING,
	GAME_OVER
};

const float GRAVITY = 50.0f;
const float FLYING_SPEED = 500.0f;
const float FLYING_DURATION = 0.1f;

const float FLASH_SPEED = 1500.0f;
const float TIME_BEFORE_GAME_OVER = 1.5f;

const int BRONZE_SCORE = 0;
const int SILVER_SCORE = 5;
const int GOLD_SCORE = 25;
const int PLATINUM_SCORE = 100;
