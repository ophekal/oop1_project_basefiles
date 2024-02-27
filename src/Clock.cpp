
#include "Clock.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include "Button.h"
#include "HandleResources.h"
#include <string>
#include <iostream>

//------------------------------------------------------------------------

void Clock::setClock(float levelTime, bool& levelOver)
{
	m_rectangle.updateButton(*HandleResources::instance().getInfoBarTexture(B_TIME), INFO_X, CLOCK_Y, INFO_SIZE);
	
    levelOver = false;
	m_timer = levelTime;
	//std::cout << m_timer << std::endl;
	m_clock.restart();
	//updateTime(levelTime, levelOver);
}
//------------------------------------------------------------------------
void Clock::incTime()
{

}
//-----------------------------------------------------------------------
void Clock::printClock(sf::RenderWindow& window, bool& levelOver)
{
	updateTime(0, levelOver);
	m_rectangle.setText(m_timeString);
	m_rectangle.printButton(window);
}
//-----------------------------------------------------------------------
const sf::Clock& Clock::getClock()const
{
	return m_clock;
}
//-----------------------------------------------------------------------
void Clock::updateTime(float time, bool& levelOver)
{
	//m_timer += time;
	std::cout << m_timer << std::endl;
	m_timer -= m_clock.getElapsedTime().asSeconds();
	m_clock.restart();
	std::cout << m_timer << std::endl;


	if (m_timer <= -1)
	{
		//levelOver = true;
	}
	int leftMinutes = m_timer/60;
	std::cout << leftMinutes << std::endl;
	int leftSeconds = (int)m_timer % 60;
	std::cout << leftSeconds << std::endl;

	std::string minString = leftMinutes < 10 ? "0" + std::to_string(leftMinutes) : std::to_string(leftMinutes);
	std::cout << minString << std::endl;
	std::string secString = leftSeconds < 10 ? "0" + std::to_string(leftSeconds) : std::to_string(leftSeconds);
	std::cout << secString << std::endl;
	m_timeString = minString + ":" + secString;
	//m_clock.restart();
}
