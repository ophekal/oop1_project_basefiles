
#include "Menu.h"
#include <vector>
#include <string.h>
#include <fstream>
#include "Macros.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include "Controller.h"
#include "HandleResources.h"
#include <iostream>

//------------------------------------------------------------------------
Menu::Menu()
	: m_window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT)," ")
{
	updateButton();
}
//------------------------------------------------------------------------
void Menu::run()
{
	HandleResources::instance().playMusic();
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
	m_buttons[M_START].updateButton(*HandleResources::instance().getBackgroundTexture(B_START), START_X, START_Y,BUTTON_SIZE);
	m_buttons[M_SETTINGS].updateButton(*HandleResources::instance().getBackgroundTexture(B_SETTINGS),SETTINGS_X, SETTINGS_Y,BUTTON_SIZE);
	m_buttons[M_EXIT].updateButton(*HandleResources::instance().getBackgroundTexture(B_EXIT), EXIT_X, EXIT_Y,BUTTON_SIZE);
	m_buttons[M_SOUND].updateButton(*HandleResources::instance().getBackgroundTexture(B_SOUND),SOUND_X, SOUND_Y, SOUND_SIZE);
}

//------------------------------------------------------------------
void Menu::print(const sf::Sprite& background)
{
	m_window.clear();
	m_window.draw(background);
	printButtons();
	m_window.display();
}

//------------------------------------------------------------------
void Menu::printButtons()
{
	sf::Vector2i mousePosition = sf::Mouse::getPosition(m_window);
	sf::Vector2f mousePosF(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y));

	//increase the buttons when mouse ontop
	for (int i = 0; i < 3; i++)
	{
		sf::RectangleShape& button = m_buttons[i].getRectangleButton();
		sf::FloatRect bounds = button.getGlobalBounds();

		if (bounds.contains(mousePosF))
		{
			button.setScale(1.05f, 1.05f);
		}
		else
		{
			button.setScale(1.0f, 1.0f);
		}
	}

	for (int i = 0; i < 4; i++)
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
	else if (m_buttons[M_SETTINGS].getRectangleButton().getGlobalBounds().contains(location))
	{
		pressedHelp();	//creates a window that explains the game
	}
	else if (m_buttons[M_START].getRectangleButton().getGlobalBounds().contains(location))
	{
		startGame();	//calls on controller and starts the game
	}
	else if (m_buttons[M_SOUND].getRectangleButton().getGlobalBounds().contains(location))
	{
		handleMusic();
	}

}

//---------------------------------------------------------------------------------------
void Menu::pressedHelp()
{
	sf::Sprite help;
	const sf::Texture* backgroundTexture = HandleResources::instance().getBackgroundTexture(B_HELP);
	help.setTexture(*backgroundTexture);
	sf::Vector2u textureSize = (*backgroundTexture).getSize();

	sf::RenderWindow helpWindow(sf::VideoMode(HELP, HELP), "Game Information");

	// Scale the background sprite to fit the window
	help.setScale((float)(helpWindow.getSize().x) / textureSize.x,
		(float)(helpWindow.getSize().y) / textureSize.y);

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
	controller.run(m_window,m_musicOn); 
	checkMusic();
}
//----------------------------------------------------------------------

void Menu::handleMusic()
{
	if (m_musicOn)
	{
		m_musicOn = false;
		m_buttons[M_SOUND].updateButton(*HandleResources::instance().getBackgroundTexture(B_MUTE),SOUND_X, SOUND_Y,SOUND_SIZE);
		HandleResources::instance().stopMusic();
	}
	else
	{
		m_musicOn = true;
		m_buttons[M_SOUND].updateButton(*HandleResources::instance().getBackgroundTexture(B_SOUND), SOUND_X, SOUND_Y,SOUND_SIZE);
		HandleResources::instance().playMusic();
	}

}
//------------------------------------------------------------------------
void Menu::checkMusic()
{
	if (m_musicOn)
	{
		m_buttons[M_SOUND].updateButton(*HandleResources::instance().getBackgroundTexture(B_SOUND), SOUND_X, SOUND_Y, SOUND_SIZE);
		
	}
	else
	{
		m_buttons[M_SOUND].updateButton(*HandleResources::instance().getBackgroundTexture(B_MUTE), SOUND_X, SOUND_Y, SOUND_SIZE);
	}
}