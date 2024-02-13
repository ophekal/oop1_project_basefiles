#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include <fstream>
#include "Button.h"

Class Menu
{
public:
	Menu();
	void print();

private:
	
	sf::RectangleShape m_menu	//hold the menu that pops up when the game starts
	Button buttons[3];

	sf::RectangleShape m_helpButtonPressed;	//will show the rules of the game, how do i close it?



};

