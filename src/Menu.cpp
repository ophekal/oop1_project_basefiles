
#include "Menu.h"
#include <vector>
#include <string.h>
#include <fstream>
#include "Macros.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include "Controller.h"

//------------------------------------------------------------------------
Menu::Menu()
	: m_window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT)," ")
{
	updateObjectVector();
	updateBackgroundVector();
	m_font.loadFromFile("font.ttf");
	updateButton();
}
//------------------------------------------------------------------------
void Menu::run()
{
	sf::Sprite background;
	background.setTexture(m_backgroundsTextures[0]);
	sf::Vector2u textureSize = m_backgroundsTextures[0].getSize();

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

//------------------------------------------------------------------------
void Menu::updateObjectVector()
{
	m_objectsTextures.resize(7);
	m_objectsTextures[I_CAT].loadFromFile("cat.png");
	m_objectsTextures[I_MOUSE].loadFromFile("mouse.png");
	m_objectsTextures[I_KEY].loadFromFile("key.png");
	m_objectsTextures[I_GIFT].loadFromFile("gift.png");
	m_objectsTextures[I_CHEESE].loadFromFile("cheese.png");
	m_objectsTextures[I_DOOR].loadFromFile("door.png");
	m_objectsTextures[I_WALL].loadFromFile("wall.png");
}

//-------------------------------------------------------------------------
void Menu::updateBackgroundVector()
{
	m_backgroundsTextures.resize(3);
	m_backgroundsTextures[0].loadFromFile("menuLandscape.jpg");
	m_backgroundsTextures[1].loadFromFile("landscape.png");
	m_backgroundsTextures[2].loadFromFile("button.png");
}
//-------------------------------------------------------------------------
void Menu::updateButton()
{
	m_buttons[M_EXIT].updateButton(m_font, m_backgroundsTextures[2], "EXIT", EXIT_X, EXIT_Y,48);
	m_buttons[M_HELP].updateButton(m_font, m_backgroundsTextures[2], "HELP", HELP_X, HELP_Y, 48);
	m_buttons[M_START].updateButton(m_font, m_backgroundsTextures[2], "START", START_X, START_Y,48);
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
void Menu:: pressedHelp()
{
	sf::RenderWindow helpWindow(sf::VideoMode(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2), "Game Information");

	while (helpWindow.isOpen())
	{
		helpWindow.clear(sf::Color::White);
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
	Controller controller(m_font,m_backgroundsTextures[2]);
	controller.run(m_window, m_objectsTextures,m_backgroundsTextures); //also sound!
}