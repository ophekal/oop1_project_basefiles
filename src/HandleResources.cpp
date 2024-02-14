
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
	m_backgroundsTextures.resize(2);
	m_backgroundsTextures[0].loadFromFile("menuLandscape.png");
	m_backgroundsTextures[1].loadFromFile("landscape.png");
}