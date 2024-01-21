#pragma once

#define SCREEN_WIDTH 1000 // ������ ������
#define SCREEN_HEIGHT 700 // ������ ������

#define SPLASH_STATE_SHOW_TIME 1.5 // ����� ������ ��������
#define SPLASH_SCENE_BACKGROUND_FILEPATH "Resources/res/SplashBackground.png" // ��������
#define ICON_FILEPATH "Resources/res/Icon.png" // ������

#define MAIN_MENU_BACKGROUND_FILEPATH "Resources/res/MainMenuBackground.png" // ������� ����
#define GAME_TITLE_FILEPATH "Resources/res/Title.png" // ��������
#define PLAY_BUTTON_FILEPATH "Resources/res/PlayButton.png" // ������ ������

#define GAME_BACKGROUND_FILEPATH "Resources/res/GameBackground.png" // ��� ����
#define GAME_OVER_BACKGROUND_FILEPATH "Resources/res/GameBackground.png" // ��� ����� ����

#define FORK_UP_FILEPATH "Resources/res/ForkUp.png"// ����� �����
#define FORK_DOWN_FILEPATH "Resources/res/ForkDown.png" // ����� ����
#define FORK_MOVEMENT_SPEED 150.0f // �������� ��������
#define FORK_SPAWN_FREQUENCY 1.5f // ������� ���������

#define LAND_FILEPATH "Resources/res/Land.png" // ������ ����� ������ ����

#define DUMPLING_FILEPATH "Resources/res/Dumpling.png" // ���������

#define DUMPLING_STATE_STILL 1
#define DUMPLING_STATE_FALLING 2  //��������� ���������
#define DUMPLING_STATE_FLYING 3

#define GRAVITY 250.0f
#define FLYING_SPEED 250.0f //�������� ������
#define FLYING_DURATION 0.2f //����������������� ������

enum GameStates {
	eReady,
	ePlaying,
	eGameOver
	
};