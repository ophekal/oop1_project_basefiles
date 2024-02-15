#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "MovingObjects.h"
#include "Board.h"
#include "InfoBar.h"

class Controller
{
public:
	Controller(sf::Font& font);
	void run(sf::RenderWindow& window);

private:
	
	Board m_board;
	InfoBar m_infoBar;

	int m_levelNum = 0;	//saves the level number

	std::vector<std::unique_ptr<MovingObjects>> m_movingObjects;
	std::vector<std::string> m_playlist;

	//Mouse m_mouse;
	//std::vector<std::unique_ptr<Cat>> m_cats;

};