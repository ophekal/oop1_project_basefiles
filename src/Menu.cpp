
#include "Menu.h"
#include <vector>
#include <string.h>
#include <fstream>
#include "Macros.h"
#include <SFML/Graphics.hpp>
#include <vector>

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
	m_backgroundsTextures.resize(2);
	m_backgroundsTextures[0].loadFromFile("menuLandscape.png");
	m_backgroundsTextures[1].loadFromFile("landscape.png");
}
//-------------------------------------------------------------------------
void Menu::updateButton()
{
	m_buttons[M_EXIT].updateButton(m_font, "EXIT", EXIT_X, EXIT_Y);
	m_buttons[M_HELP].updateButton(m_font, "HELP", HELP_X, HELP_Y);
	m_buttons[M_START].updateButton(m_font, "START", START_X, START_Y);

}