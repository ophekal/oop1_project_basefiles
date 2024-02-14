
#include "InfoBar.h"
#include <SFML/Graphics.hpp>
#include "Macros.h"

//-----------------------------------------------------------
InfoBar::InfoBar(sf::Font& font)// pass the time of the game
{
	m_info.setFont(font);
	m_info.setString("INFORMATION");
	m_info.setCharacterSize(24);
	m_info.setFillColor(sf::Color::Black);
	m_info.setPosition(INFO_X, INFO_Y);

	//handle clock	Clock m_clock;

	m_numOfLevel.setFont(font);
	m_numOfLevel.setString("LEVEL: ");
	m_numOfLevel.setCharacterSize(24);
	m_numOfLevel.setFillColor(sf::Color::Black);
	m_numOfLevel.setPosition(INFO_X, LEVEL_Y);

	m_numOfLives.setFont(font);
	m_numOfLives.setString("LIVES: ");
	m_numOfLives.setCharacterSize(24);
	m_numOfLives.setFillColor(sf::Color::Black);
	m_numOfLives.setPosition(INFO_X, LEVEL_Y);


	m_numOfKeys.setFont(font);
	m_numOfKeys.setString("KEYS: ");
	m_numOfKeys.setCharacterSize(24);
	m_numOfKeys.setFillColor(sf::Color::Black);
	m_numOfKeys.setPosition(INFO_X, KEYS_Y);

}
//------------------------------------------------------------------------

void InfoBar::printInfoBar(sf::RenderWindow& window)
{
	window.draw(m_info);
	window.draw(m_numOfLevel);
	window.draw(m_numOfLives);
	window.draw(m_numOfKeys);

	m_clock.printClock();//pass the curr time
}