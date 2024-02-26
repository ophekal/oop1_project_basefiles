
#include "InfoBar.h"
#include <SFML/Graphics.hpp>
#include "Macros.h"
# include "HandleResources.h"

//-----------------------------------------------------------
InfoBar::InfoBar()// pass the time of the game
{
	const sf::Font* font = HandleResources::instance().getFont();

	m_infoBar.resize(7);
	m_infoBar[0].updateButton(*HandleResources::instance().getInfoBarTexture(B_INFO),INFO_X, INFO_Y,INFO_SIZE);
	m_infoBar[1].updateButton(*HandleResources::instance().getInfoBarTexture(B_LEVEL),INFO_X, LEVEL_Y, INFO_SIZE);
	m_infoBar[2].updateButton(*HandleResources::instance().getInfoBarTexture(B_LIVES),INFO_X, LIVES_Y, INFO_SIZE);
	m_infoBar[3].updateButton(*HandleResources::instance().getInfoBarTexture(B_KEYS),INFO_X, KEYS_Y, INFO_SIZE);
	m_infoBar[4].updateButton(*HandleResources::instance().getInfoBarTexture(B_HOME), HOME_X, HOME_Y, SOUND_SIZE);
	m_infoBar[5].updateButton(*HandleResources::instance().getBackgroundTexture(B_SOUND), I_SOUND_X, I_SOUND_Y, SOUND_SIZE);
	m_infoBar[6].updateButton(*HandleResources::instance().getInfoBarTexture(B_SCORE), INFO_X, SCORE_Y, INFO_SIZE);
    
}
//------------------------------------------------------------------------
void InfoBar::setInfoBar(int levelNum, int score, int key,int lives)
{
	updateLife(lives);
	updateScore(score);
	updateKey(key);
	updateLevel(levelNum);	
}
//------------------------------------------------------------------------
void InfoBar::printInfoBar(sf::RenderWindow& window)
{
	for (auto index = 0; index < m_infoBar.size(); index++)
	{
		m_infoBar[index].printButton(window);
	}
}

//------------------------------------------------------------------------
void InfoBar::updateLife(int lives)
{
	m_numOfLives = std::to_string(lives);
	m_infoBar[2].setText(m_numOfLives);
}
//------------------------------------------------------------------------
void InfoBar::updateScore(int score)
{
	m_score = std::to_string(score);
	m_infoBar[6].setText(m_score);
}
//------------------------------------------------------------------------
void InfoBar::updateKey(int keys)
{
	m_numOfKeys = std::to_string(keys);
	m_infoBar[3].setText(m_numOfKeys);
}
//------------------------------------------------------------------------
void InfoBar::updateLevel(int level)
{
	m_numOfLevel = std::to_string(level);
	m_infoBar[1].setText(m_numOfLevel);
}

//------------------------------------------------------------------------
void InfoBar::handleClick( const sf::Vector2f& location, bool& gameOver)
{

	if (m_infoBar[4].getRectangleButton().getGlobalBounds().contains(location))
	{
		//the player press on home
		gameOver = true;
		return;
	}
	else if (m_infoBar[5].getRectangleButton().getGlobalBounds().contains(location))
	{
		if (m_musicOn)
		{
			m_musicOn = false;
			m_infoBar[5].updateButton(*HandleResources::instance().getBackgroundTexture(B_MUTE), I_SOUND_X, I_SOUND_Y, SOUND_SIZE);
			// mute the music;
		}
		else
		{
			m_musicOn = true;
			m_infoBar[5].updateButton(*HandleResources::instance().getBackgroundTexture(B_SOUND), I_SOUND_X, I_SOUND_Y, SOUND_SIZE);
			// set the music on
		}
	}
}