#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include <fstream>
#include "Button.h"

class Menu
{
public:
	Menu();
	void run();   //holds the waitevents of the different options in menu

private:
	sf::RenderWindow m_window;
	Button buttons[3];
	sf::RenderWindow m_helpButtonPressed;	//will show the rules of the game

	sf::Music m_gameMusic;	//maybe needs to be in controller?

};

