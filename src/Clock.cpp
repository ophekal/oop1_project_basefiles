
#include "Clock.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include "Button.h"
#include "HandleResources.h"
#include <string>

//------------------------------------------------------------------------

void Clock::setClock(double levelTime)
{
	m_rectangle.updateButton(*HandleResources::instance().getInfoBarTexture(B_TIME), INFO_X, CLOCK_Y, INFO_SIZE);
	//m_rectangle.setText
	//m_rectangle.setPosition({ INFO_X,CLOCK_Y });
	//m_rectangle.setSize(INFO_SIZE);

	//m_rectangle.setTexture(HandleResources::instance().getInfoBarTexture(B_TIME));
}
//------------------------------------------------------------------------
void Clock::incTime()
{

}
//-----------------------------------------------------------------------
void Clock::printClock(sf::RenderWindow& window)
{
	m_rectangle.printButton(window);
}
//-----------------------------------------------------------------------
const sf::Clock& Clock::getClock()const
{
	return m_clock;
}
//-----------------------------------------------------------------------
void Clock::updateTime(float time)
{
	m_timer += time;
	m_timer -= m_clock.getElapsedTime().asSeconds();

	int leftMinutes = ((int)m_timer) / 60;
	int leftSeconds = ((int)m_timer) % 60;

	std::string minString = leftMinutes < 10 ? "0" + std::to_string(leftMinutes) : std::to_string(leftMinutes);
	std::string secString = leftSeconds < 10 ? "0" + std::to_string(leftSeconds) : std::to_string(leftSeconds);
	std::string timeString = minString + ":" + secString;
}
