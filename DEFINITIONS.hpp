#pragma once

#define SCREEN_WIDTH 1000 // ширина экрана
#define SCREEN_HEIGHT 700 // высота экрана

#define SPLASH_STATE_SHOW_TIME 1.5 // время показа заставки
#define SPLASH_SCENE_BACKGROUND_FILEPATH "Resources/res/SplashBackground.png" // заставка
#define ICON_FILEPATH "Resources/res/Icon.png" // иконка

#define MAIN_MENU_BACKGROUND_FILEPATH "Resources/res/MainMenuBackground.png" // главное меню
#define GAME_TITLE_FILEPATH "Resources/res/Title.png" // название
#define PLAY_BUTTON_FILEPATH "Resources/res/PlayButton.png" // кнопка играть

#define GAME_BACKGROUND_FILEPATH "Resources/res/GameBackground.png" // фон игры
#define GAME_OVER_BACKGROUND_FILEPATH "Resources/res/GameBackground.png" // фон конца игры

#define FORK_UP_FILEPATH "Resources/res/ForkUp.png"// вилка вверх
#define FORK_DOWN_FILEPATH "Resources/res/ForkDown.png" // вилка вниз
#define SCORING_FORK_FILEPATH "Resources/res/InvisibleScoringFork.png" // вилка вниз
#define FORK_MOVEMENT_SPEED 150.0f // скорость движения
#define FORK_SPAWN_FREQUENCY 2.0f // частота появления

#define LAND_FILEPATH "Resources/res/Land.png" // нижняя часть экрана игры

#define DUMPLING_FILEPATH "Resources/res/Dumpling.png" // пельмешка

#define DUMPLING_STATE_STILL 1
#define DUMPLING_STATE_FALLING 2  //состояния пельмешки
#define DUMPLING_STATE_FLYING 3

#define FLAPPY_FONT_FILEPATH "Resources/fonts/FlappyFont.ttf"
#define GAME_OVER_TITLE_FILEPATH "Resources/res/Game-Over-Title.png"
#define GAME_OVER_BODY_FILEPATH "Resources/res/Game-Over-Body.png"
#define GAME_OVER_RETRY_FILEPATH "Resources/res/PlayButton.png"
#define GOLDEN_MEDAL_FILEPATH "Resources/res/GoldenMedal.png"
#define BRONZE_MEDAL_FILEPATH "Resources/res/BronzeMedal.png"
#define SILVER_MEDAL_FILEPATH "Resources/res/SilverMedal.png"

#define GRAVITY 250.0f
#define FLYING_SPEED 250.0f //скорость полета
#define FLYING_DURATION 0.2f //продолжительность полета

enum GameStates {
	eReady,
	ePlaying,
	eGameOver
	
};

#define FLASH_SPEED 1500.0f
#define TIME_BEFORE_GAMEOVER_APPEARS 1.5f

#define BRONZE_MEDAL_SCORE 0
#define SILVER_MEDAL_SCORE 5
#define GOLDEN_MEDAL_SCORE 15