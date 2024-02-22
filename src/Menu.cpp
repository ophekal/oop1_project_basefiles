
#include "Menu.h"
#include <vector>
#include <string.h>
#include <fstream>
#include "Macros.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include "Controller.h"
#include "HandleResources.h"

//------------------------------------------------------------------------
Menu::Menu()
	: m_window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT)," ")
{
	updateButton();
}
//------------------------------------------------------------------------
void Menu::run()
{
	sf::Sprite background;
	const sf::Texture* backgroundTexture = HandleResources::instance().getBackgroundTexture(B_MENU);
	background.setTexture(*backgroundTexture);
	sf::Vector2u textureSize = (*backgroundTexture).getSize();

	// Scale the background sprite to fit the window
	background.setScale((float)(m_window.getSize().x) / textureSize.x,
		                (float)(m_window.getSize().y) / textureSize.y);

	while (m_window.isOpen())
	{
		print(background);

		if (auto event = sf::Event{}; m_window.waitEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				m_window.close();
				break;
			case sf::Event::MouseButtonReleased:
				handleClick(event.mouseButton);
				break;
			}
		}
	}
}

//-------------------------------------------------------------------------
void Menu::updateButton()
{
	const sf::Font* font = HandleResources::instance().getFont();
	const sf::Texture* background = HandleResources::instance().getBackgroundTexture(B_BUTTON);

	m_buttons[M_EXIT].updateButton(*font, *background, "EXIT", EXIT_X, EXIT_Y,48);
	m_buttons[M_HELP].updateButton(*font, *background, "HELP", HELP_X, HELP_Y, 48);
	m_buttons[M_START].updateButton(*font, *background, "START", START_X, START_Y,48);
}

//------------------------------------------------------------------
void Menu::print(sf::Sprite& background)
{
	m_window.clear();
	m_window.draw(background);
	printButtons();
	m_window.display();
}

//------------------------------------------------------------------
void Menu::printButtons()
{
	for (int i = 0; i < 3; i++)
	{
		m_buttons[i].printButton(m_window);
	}
}
//------------------------------------------------------------
void Menu::handleClick(sf::Event::MouseButtonEvent& event)
{
	auto location = m_window.mapPixelToCoords({ event.x,event.y });

	if (m_buttons[M_EXIT].getRectangleButton().getGlobalBounds().contains(location))
	{
		m_window.close();
		return;
	}
	else if (m_buttons[M_HELP].getRectangleButton().getGlobalBounds().contains(location))
	{
		pressedHelp();	//creates a window that explains the game
	}
	else if (m_buttons[M_START].getRectangleButton().getGlobalBounds().contains(location))
	{
		startGame();	//calls on controller and starts the game
	}
}

//---------------------------------------------------------------------------------------
void Menu::pressedHelp()
{
	sf::Sprite help;
	const sf::Texture* backgroundTexture = HandleResources::instance().getBackgroundTexture(B_HELP);
	help.setTexture(*backgroundTexture);
	sf::Vector2u textureSize = (*backgroundTexture).getSize();

	// Scale the background sprite to fit the window
	help.setScale((float)(m_window.getSize().x) / textureSize.x,
		(float)(m_window.getSize().y) / textureSize.y);

	sf::RenderWindow helpWindow(sf::VideoMode(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2), "Game Information");

	while (helpWindow.isOpen())
	{
		helpWindow.clear();
		helpWindow.draw(help);
		helpWindow.display();

		if (auto event = sf::Event{}; helpWindow.waitEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				helpWindow.close();
				break;
			}
		}
	}
}

//----------------------------------------------------------------------
void Menu::startGame()
{
	Controller controller;
	controller.run(m_window); //also sound!
}