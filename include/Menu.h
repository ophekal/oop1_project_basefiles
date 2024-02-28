#pragma once
#include <SFML/Graphics.hpp>
#include "Button.h"

class Menu
{
public:
	Menu();
	void run();  

private:
	void updateButton();
	void print(const sf::Sprite& background);
	void printButtons();
	void handleClick(sf::Event::MouseButtonEvent& event);
	void pressedHelp();
	void startGame();
	void handleMusic();
	void checkMusic();

	sf::RenderWindow m_window;
	Button m_buttons[4];
	bool m_musicOn = true;
};

