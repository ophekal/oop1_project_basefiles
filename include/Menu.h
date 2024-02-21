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
	//void updateObjectVector();
	//void updateBackgroundVector();
	void updateButton();
	void print(sf::Sprite& background);
	void printButtons();
	void handleClick(sf::Event::MouseButtonEvent& event);
	void pressedHelp();
	void startGame();

	//a member that saves the text of help windpw

	sf::RenderWindow m_window;
	Button m_buttons[3];
	//sf::RenderWindow m_helpButtonPressed;	//will show the rules of the game

	//sf::Music m_gameMusic;	//maybe needs to be in controller?

	//std::vector<sf::Texture> m_objectsTextures;
	//std::vector<sf::Texture> m_backgroundsTextures;	//menu, infobar, window

	//sf::Font m_font;
};

