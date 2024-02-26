
#include "InfoBar.h"
#include <SFML/Graphics.hpp>
#include "Macros.h"
# include "HandleResources.h"

//-----------------------------------------------------------
InfoBar::InfoBar()// pass the time of the game
{
	const sf::Font* font = HandleResources::instance().getFont();

	m_infoBar.resize(6);
	//m_infoBar[0].updateSize(300,110);
	m_infoBar[0].updateButton(*HandleResources::instance().getInfoBarTexture(B_INFO),INFO_X, INFO_Y,INFO_SIZE);
	
	//m_infoBar[1].updateSize(300, 110);
	m_infoBar[1].updateButton(*HandleResources::instance().getInfoBarTexture(B_LEVEL),INFO_X, LEVEL_Y, INFO_SIZE);

	//m_infoBar[2].updateSize(300, 110);
	m_infoBar[2].updateButton(*HandleResources::instance().getInfoBarTexture(B_LIVES),INFO_X, LIVES_Y, INFO_SIZE);

	//m_infoBar[3].updateSize(300, 110);
	m_infoBar[3].updateButton(*HandleResources::instance().getInfoBarTexture(B_KEYS),INFO_X, KEYS_Y, INFO_SIZE);

	m_infoBar[4].updateButton(*HandleResources::instance().getInfoBarTexture(B_HOME), HOME_X, HOME_Y, SOUND_SIZE);
	m_infoBar[5].updateButton(*HandleResources::instance().getBackgroundTexture(B_SOUND), I_SOUND_X, I_SOUND_Y, SOUND_SIZE);
    //handle clock	Clock m_clock	
}
//------------------------------------------------------------------------
void InfoBar::setInfoBar(int levelNum, int levelTime)
{
	// set in the levl rectangle the level number
	// set the time in the clock
}
//------------------------------------------------------------------------
void InfoBar::printInfoBar(sf::RenderWindow& window)
{
	for (auto index = 0; index < m_infoBar.size(); index++)
	{
		m_infoBar[index].printButton(window);
	}

	//m_clock.printClock();//pass the curr time
}
//------------------------------------------------------------------------
void InfoBar::incTime()
{
	m_clock.incTime();

}
//------------------------------------------------------------------------
void InfoBar::incLife()
{

}

//------------------------------------------------------------------------
void InfoBar::handleClick( const sf::Vector2f& location, bool& gameOver)
{

}