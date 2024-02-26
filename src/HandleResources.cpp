
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
	updateInfoBarVector();
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
	m_objectsTextures.resize(12);
	m_objectsTextures[I_L_CAT].loadFromFile("leftCat.png");
	m_objectsTextures[I_R_CAT].loadFromFile("rightCat.png");
	m_objectsTextures[I_L_MOUSE].loadFromFile("leftMouse.png");
	m_objectsTextures[I_R_MOUSE].loadFromFile("rightMouse.png");
	m_objectsTextures[I_KEY].loadFromFile("key.png");
	m_objectsTextures[I_ADDLIFEGIFT].loadFromFile("addLifeGift.png");
	m_objectsTextures[I_ADDTIMEGIFT].loadFromFile("addTimeGift.png");
	m_objectsTextures[I_FREEZECATGIFT].loadFromFile("freezeCatGift.png");
	m_objectsTextures[I_KILLCATGIFT].loadFromFile("killCatGift.png");
	m_objectsTextures[I_CHEESE].loadFromFile("cheese.png");
	m_objectsTextures[I_DOOR].loadFromFile("door.png");
	m_objectsTextures[I_WALL].loadFromFile("wall.png");
}

//-------------------------------------------------------------------------
void HandleResources::updateBackgroundVector()
{
	m_backgroundsTextures.resize(8);
	m_backgroundsTextures[B_MENU].loadFromFile("menuLandscape.jpg");
	m_backgroundsTextures[B_GAME].loadFromFile("landscape.png");
	m_backgroundsTextures[B_SETTINGS].loadFromFile("settings.png");
	m_backgroundsTextures[B_EXIT].loadFromFile("exit.png");
	m_backgroundsTextures[B_START].loadFromFile("startgame.png");
	m_backgroundsTextures[B_HELP].loadFromFile("helpWindow.png");
	m_backgroundsTextures[B_SOUND].loadFromFile("music.png");
	m_backgroundsTextures[B_MUTE].loadFromFile("mute.png");
}


//-------------------------------------------------------------------------
void HandleResources::updateInfoBarVector()
{
	m_infoBarTextures.resize(6);
	m_infoBarTextures[B_INFO].loadFromFile("information.png");
	m_infoBarTextures[B_LEVEL].loadFromFile("level.png");
	m_infoBarTextures[B_LIVES].loadFromFile("lives.png");
	m_infoBarTextures[B_KEYS].loadFromFile("keys.png");
	m_infoBarTextures[B_TIME].loadFromFile("time.png");
	m_infoBarTextures[B_HOME].loadFromFile("home.png");
}

//--------------------------------------------------------------------------

const sf::Texture* HandleResources::getInfoBarTexture(Bar icon)
{
	return &(m_infoBarTextures[icon]);
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