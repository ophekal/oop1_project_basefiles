
#include "InfoBar.h"
#include <SFML/Graphics.hpp>
#include "Macros.h"

//-----------------------------------------------------------
InfoBar::InfoBar(const sf::Font& font, const sf::Texture& background)// pass the time of the game
{
	m_infoBar.resize(4);
	m_infoBar[0].updateSize(300,110);
	m_infoBar[0].updateButton(font, background, "INFORMATION", INFO_X, INFO_Y,24);
	
	m_infoBar[1].updateSize(300, 110);
	m_infoBar[1].updateButton(font, background, "LEVEL: ", INFO_X, LEVEL_Y,24);

	m_infoBar[2].updateSize(300, 110);
	m_infoBar[2].updateButton(font, background, "LIVES: ", INFO_X, LIVES_Y,24);

	m_infoBar[3].updateSize(300, 110);
	m_infoBar[3].updateButton(font, background, "KEYS: ", INFO_X, KEYS_Y,24);


    //handle clock	Clock m_clock

	//m_numOfLevel.setFont(font);
	//m_numOfLevel.setString("LEVEL: ");
	//m_numOfLevel.setCharacterSize(24);
	//m_numOfLevel.setFillColor(sf::Color::Black);
	//m_numOfLevel.setPosition(INFO_X, LEVEL_Y);

	//m_numOfLives.setFont(font);
	//m_numOfLives.setString("LIVES: ");
	//m_numOfLives.setCharacterSize(24);
	//m_numOfLives.setFillColor(sf::Color::Black);
	//m_numOfLives.setPosition(INFO_X, LIVES_Y);


	//m_numOfKeys.setFont(font);
	//m_numOfKeys.setString("KEYS: ");
	//m_numOfKeys.setCharacterSize(24);
	//m_numOfKeys.setFillColor(sf::Color::Black);
	//m_numOfKeys.setPosition(INFO_X, KEYS_Y);

	/*setText(font, "INFORMATION", INFO_X, INFO_Y);
	//handle clock	Clock m_clock;
	setText(font, "LEVEL: ", INFO_X, LEVEL_Y);
	setText(font, "LIVES: ", INFO_X, LIVES_Y);
	setText(font, "KEYS: ", INFO_X, KEYS_Y);*/
	
}
//------------------------------------------------------------------------
/*void InfoBar::setText(const sf::Font& font, std::string text, float x, float y)
{
	m_numOfLevel.setFont(font);
	m_numOfLevel.setString("LEVEL: ");
	m_numOfLevel.setCharacterSize(24);
	m_numOfLevel.setFillColor(sf::Color::Black);
	m_numOfLevel.setPosition(INFO_X, LEVEL_Y);
}*/
//------------------------------------------------------------------------
void InfoBar::printInfoBar(sf::RenderWindow& window)
{
	for (auto index = 0; index < m_infoBar.size(); index++)
	{
		m_infoBar[index].printButton(window);
	}
	//window.draw(m_info);
	//window.draw(m_numOfLevel);
	//window.draw(m_numOfLives);
	//window.draw(m_numOfKeys);

	//m_clock.printClock();//pass the curr time
}