
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
	updateScreenVector();
	updateGameSounds();
	m_font.loadFromFile("font.ttf");
	m_gameMusic.openFromFile("gameMusic.wav");
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
	m_backgroundsTextures.resize(9);
	m_backgroundsTextures[B_MENU].loadFromFile("menuLandscape.jpg");
	m_backgroundsTextures[B_GAME].loadFromFile("landscape.png");
	m_backgroundsTextures[B_SETTINGS].loadFromFile("settings.png");
	m_backgroundsTextures[B_EXIT].loadFromFile("exit.png");
	m_backgroundsTextures[B_START].loadFromFile("startgame.png");
	m_backgroundsTextures[B_HELP].loadFromFile("helpWindow.png");
	m_backgroundsTextures[B_SOUND].loadFromFile("music.png");
	m_backgroundsTextures[B_MUTE].loadFromFile("mute.png");
	m_backgroundsTextures[B_BOARD].loadFromFile("grass.png");
}


//-------------------------------------------------------------------------
void HandleResources::updateInfoBarVector()
{
	m_infoBarTextures.resize(8);
	m_infoBarTextures[B_INFO].loadFromFile("information.png");
	m_infoBarTextures[B_LEVEL].loadFromFile("level.png");
	m_infoBarTextures[B_LIVES].loadFromFile("lives.png");
	m_infoBarTextures[B_KEYS].loadFromFile("keys.png");
	m_infoBarTextures[B_TIME].loadFromFile("time.png");
	m_infoBarTextures[B_HOME].loadFromFile("home.png");
	m_infoBarTextures[B_SCORE].loadFromFile("score.png");
	m_infoBarTextures[B_RESTART].loadFromFile("restart.png");
}

//-------------------------------------------------------------------------
void HandleResources::updateScreenVector()
{
	m_screenTextures.resize(4);
	m_screenTextures[S_WIN].loadFromFile("youWin.png");
	m_screenTextures[S_GAMEOVER].loadFromFile("gameOver.png");
	m_screenTextures[S_TRYAGAIN].loadFromFile("tryAgain.png");
	m_screenTextures[S_GOODJOB].loadFromFile("goodJob.png");
}
//-------------------------------------------------------------------------
void HandleResources::updateGameSounds()
{
	m_gameSounds.resize(6);
	m_gameSounds[G_CHESSE].loadFromFile("yummy.wav");
	m_gameSounds[G_GIFT].loadFromFile("gift.wav");
	m_gameSounds[G_MOUSE].loadFromFile("mouseEaten.wav");
	m_gameSounds[G_WIN].loadFromFile("goodJobYouWin.wav");
	m_gameSounds[G_LOST].loadFromFile("tryAgainGameOver.wav");
	m_gameSounds[G_KEY].loadFromFile("keys.wav");
}
//--------------------------------------------------------------------------

const sf::Texture* HandleResources::getInfoBarTexture(Bar icon)
{
	return &(m_infoBarTextures[icon]);
}

//--------------------------------------------------------------------------

const sf::Texture* HandleResources::getScreenTexture(Screen icon)
{
	return &(m_screenTextures[icon]);
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
//-------------------------------------------------------------------------
void HandleResources::playSound(GameSound sound)
{
	sf::Sound currSound(m_gameSounds[sound]);
	//currSound.setVolume(50);
	currSound.play();
}
//-------------------------------------------------------------------------
void HandleResources::playMusic()
{
	m_gameMusic.setLoop(true);
	m_gameMusic.play();
}
//--------------------------------------------------------------------------
void HandleResources::stopMusic()
{
	m_gameMusic.pause();
}