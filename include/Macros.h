#pragma once
#include <SFML/Graphics.hpp>


const int PIXELS = 48;
const int BUTTON_TEXT_SIZE = 50;
const int INFOBAR_TEXT_SIZE = 30;


enum TileType : char
{
	T_EMPTY = ' ',
	T_CAT = '^',
	T_MOUSE = '%',
	T_GIFT = '$',
	T_CHEESE = '*',
	T_DOOR = 'D',
	T_WALL = '#',
	T_KEY = 'F'
};

enum IconType
{
	I_L_CAT,
	I_R_CAT,
	I_L_MOUSE,
	I_R_MOUSE,
	I_KEY,
	I_ADDLIFEGIFT,
	I_ADDTIMEGIFT,
	I_FREEZECATGIFT,
	I_KILLCATGIFT,
	I_CHEESE,
	I_DOOR,
	I_WALL
};

enum Background
{
	B_MENU,
	B_GAME,
	B_SETTINGS,
	B_EXIT,
	B_START,
	B_HELP,
	B_SOUND,
	B_MUTE,
	B_BOARD
};

enum MenuButton
{
	M_START,
	M_SETTINGS,
	M_EXIT,
	M_SOUND
};

enum Screen
{
	S_WIN,
	S_GAMEOVER,
	S_TRYAGAIN,
	S_GOODJOB
};

//-------keyboard-movement-----
const sf::Vector2f Directions[] = { {-1,0},{1,0},{0,-1},{0,1} };

enum Direction {
	D_LEFT,
	D_RIGHT,
	D_UP,
	D_DOWN	
};

//------------menu------------
const int WINDOW_HEIGHT = 1070;
const int WINDOW_WIDTH = 1500;
const float START_X = 550;
const float START_Y = 150;
const float SETTINGS_X = 550;
const float SETTINGS_Y = 300;
const float EXIT_X = 550;
const float EXIT_Y = 450;
const float SOUND_X = 1385;
const float SOUND_Y = 42;
const sf::Vector2f BUTTON_SIZE = { 400,100 };
const sf::Vector2f SOUND_SIZE = { 65,65 };


const int HELP_HEIGHT = 720;
const int HELP_WIDTH = 1280;

//------------board------------
const float BOARD_HIG = 1000;
const float BOARD_WID = 1000;
const float BOARD_START_X = 450;
const float BOARD_START_Y = 50;

//----------infoBar-------------

enum Bar
{
	B_INFO,
	B_LEVEL,
	B_TIME,
	B_LIVES,
	B_KEYS,
	B_HOME,
	B_SCORE,
	B_RESTART
};

const sf::Vector2f INFO_SIZE = { 300,110 };

const float INFO_X = 50;
const float INFO_Y = 50;
const float CLOCK_Y = 190;
const float LEVEL_Y = 330;
const float LIVES_Y = 470;
const float KEYS_Y = 610;
const float SCORE_Y = 750;


const float I_SOUND_X = 50;
const float I_SOUND_Y = 900;
const float HOME_X = 167.5;
const float HOME_Y = 900;
const float RESTART_X = 285;
const float RESTART_Y = 900;


const float LONG_LEVEL = (3*60)+1;
const float SHORT_LEVEL = ((1.5)*60)+1;

//---------------presents-----------
const float TIMEGIFT = 31;


//----------------sounds-----------

enum Sound 
{
	S_CHESSE,
	S_GIFT,
	S_MOUSE,
	S_WIN,
	S_LOST,
	S_KEY
};