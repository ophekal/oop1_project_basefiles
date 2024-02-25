
#include "InfoBar.h"
#include <SFML/Graphics.hpp>
#include "Macros.h"
# include "HandleResources.h"
//-----------------------------------------------------------
InfoBar::InfoBar()// pass the time of the game
{
	const sf::Font* font = HandleResources::instance().getFont();
	const sf::Texture* background = HandleResources::instance().getBackgroundTexture(B_BUTTON);

	m_infoBar.resize(4);
	m_infoBar[0].updateSize(300,110);
	m_infoBar[0].updateButton(*font, *background, "INFORMATION", INFO_X, INFO_Y,24);
	
	m_infoBar[1].updateSize(300, 110);
	m_infoBar[1].updateButton(*font,*background, "LEVEL: ", INFO_X, LEVEL_Y,24);

	m_infoBar[2].updateSize(300, 110);
	m_infoBar[2].updateButton(*font, *background, "LIVES: ", INFO_X, LIVES_Y,24);

	m_infoBar[3].updateSize(300, 110);
	m_infoBar[3].updateButton(*font, *background, "KEYS: ", INFO_X, KEYS_Y,24);


    //handle clock	Clock m_clock	
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

}
//------------------------------------------------------------------------
void InfoBar::incLife()
{

}