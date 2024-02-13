#pragma once
#include <SFML/Graphics.hpp>
#include "Menu.h"

class Window
{
public:
	Window();
	void print();


private:
	sf::RenderWindow m_window;
	Menu m_menu;
	sf::RectangleShape m_backgroud;
	sf::RectangleShape m_loseBackground;	//when life is 0
	sf::RectangleShape m_winBackground;		//when passes a level
	sf::Sound m_gameMusic;	//maybe needs to be in controller?

}