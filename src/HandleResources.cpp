
#include "HandleResources.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
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
	updateBufferSounds();
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
	m_screenTextures.resize(5);
	m_screenTextures[S_WIN].loadFromFile("youWin.png");
	m_screenTextures[S_GAMEOVER].loadFromFile("gameOver.png");
	m_screenTextures[S_TRYAGAIN].loadFromFile("tryAgain.png");
	m_screenTextures[S_GOODJOB].loadFromFile("goodJob.png");
	m_screenTextures[S_FINALSCORE].loadFromFile("finalScore.png");
}
//-------------------------------------------------------------------------
void HandleResources::updateBufferSounds()
{
	m_bufferSounds.resize(6);
	m_bufferSounds[G_CHEESE].loadFromFile("yummy.wav");
	m_bufferSounds[G_GIFT].loadFromFile("gift.wav");
	m_bufferSounds[G_MOUSE].loadFromFile("mouseEaten.wav");
	m_bufferSounds[G_WIN].loadFromFile("goodJobYouWin.wav");
	m_bufferSounds[G_LOST].loadFromFile("tryAgainGameOver.wav");
	m_bufferSounds[G_KEY].loadFromFile("keys.wav");
}
//-------------------------------------------------------------------------
void HandleResources::updateGameSounds()
{
	m_gameSound.resize(6);
	m_gameSound[G_CHEESE].setBuffer(m_bufferSounds[G_CHEESE]);
	m_gameSound[G_GIFT].setBuffer(m_bufferSounds[G_GIFT]);
	m_gameSound[G_MOUSE].setBuffer(m_bufferSounds[G_MOUSE]);
	m_gameSound[G_WIN].setBuffer(m_bufferSounds[G_WIN]);
	m_gameSound[G_LOST].setBuffer(m_bufferSounds[G_LOST]);
	m_gameSound[G_KEY].setBuffer(m_bufferSounds[G_KEY]);
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
	m_gameSound[sound].setVolume(50);
	m_gameSound[sound].play();
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