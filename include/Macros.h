#pragma once
#include <SFML/Graphics.hpp>


const int PIXELS = 50;
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


const sf::Vector2f Directions[] = { {-1,0},{1,0},{0,-1},{0,1} };

enum Direction {
	D_UP,
	D_DOWN,
	D_LEFT,
	D_RIGHT
};


//------------menu------------
const int WINDOW_HEIGHT = 1000;
const int WINDOW_WIDTH = 1500;


//------------board------------
const int SIZE = 500;


