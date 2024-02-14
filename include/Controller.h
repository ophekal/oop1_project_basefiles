#pragma once
#include <SFML/Graphics.hpp>
#include <memory>

class Controller
{
public:
	Controller();
	void run();


private:
	
	Board m_Board;
	InfoBar m_infoBar;

	int m_levelNum;	//saves the level number

	std::vector<std::unique_ptr<MovingObjects>> m_movingObjects;

	//Mouse m_mouse;
	//std::vector<std::unique_ptr<Cat>> m_cats;

};