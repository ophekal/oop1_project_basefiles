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
	I_CAT,
	I_MOUSE,
	I_KEY,
	I_GIFT,
	I_CHEESE,
	I_DOOR,
	I_WALL
};

enum MenuButton
{
	M_EXIT,
	M_HELP,
	M_START
};

const sf::Vector2f Directions[] = { {-1,0},{1,0},{0,-1},{0,1} };

enum Direction {
	D_UP,
	D_DOWN,
	D_LEFT,
	D_RIGHT
};


//------------menu------------
const int WINDOW_HEIGHT = 850;
const int WINDOW_WIDTH = 1500;
const float EXIT_X = 50;
const float EXIT_Y = 150;
const float HELP_X = 550;
const float HELP_Y = 150;
const float START_X = 1050;
const float START_Y = 150;

//------------board------------
const float BOARD_HIG = 1000;
const float BOARD_WID = 750;
const float BOARD_START_X = 450;
const float BOARD_START_Y = 50;

//----------infoBar-------------

const float INFO_X = 50;
const float INFO_Y = 50;
const float CLOCK_Y = 190;
const float LEVEL_Y = 330;
const float LIVES_Y = 470;
const float KEYS_Y = 610;