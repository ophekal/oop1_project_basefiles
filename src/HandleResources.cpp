
#include "HandleResources.h"
#include <SFML/Graphics.hpp>
#include <memory>
#include "Macros.h"


//------------------------------------------------------------------------
//update all the resources of the play
HandleResources::HandleResources()
{
	updateObjectVector();
	updateBackgroundVector();
	m_font.loadFromFile("font.ttf");
}

//------------------------------------------------------------------------
HandleResources& HandleResources::instance()
{
	static HandleResources inst;
	return inst;
}
//------------------------------------------------------------------------
void HandleResources::updateObjectVector()
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
void HandleResources::updateBackgroundVector()
{
	m_backgroundsTextures.resize(3);
	m_backgroundsTextures[B_MENU].loadFromFile("menuLandscape.jpg");
	m_backgroundsTextures[B_GAME].loadFromFile("landscape.png");
	m_backgroundsTextures[B_BUTTON].loadFromFile("button.png");
	m_backgroundsTextures[B_HELP].loadFromFile("helpWindow.png");
}

//-------------------------------------------------------------------------
const sf::Texture* HandleResources::getObjectTexture(IconType icon)
{
	return &(m_objectsTextures[icon]);
}
//-------------------------------------------------------------------------
const sf::Texture* HandleResources::getBackgroundTexture(Background icon)
{
	return &(m_backgroundsTextures[icon]);
}
//-------------------------------------------------------------------------
const sf::Font* HandleResources::getFont()
{
	return & m_font;
}