
#include "Clock.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include "Button.h"
#include "HandleResources.h"

//------------------------------------------------------------------------

void Clock::setClock()
{
	m_rectangle.setPosition({ INFO_X,CLOCK_Y });
	m_rectangle.setSize(INFO_SIZE);

	m_rectangle.setTexture(HandleResources::instance().getInfoBarTexture(B_TIME));
}
//------------------------------------------------------------------------
void Clock::incTime()
{

}
//-----------------------------------------------------------------------
void Clock::printClock(sf::RenderWindow& window)
{
	window.draw(m_rectangle);
}
//-----------------------------------------------------------------------
const sf::Clock& Clock::getClock()const
{
	return m_clock;
}