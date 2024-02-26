#pragma once
#include <SFML/Graphics.hpp>
#include <memory>

class Clock
{
public:
	Clock() = default;
	void setClock();
   //Clock();//pass the time of the game
	void printClock(sf::RenderWindow& window);
	void incTime();
	const sf::Clock& getClock()const;
	// setTimer();

private:
	sf::Clock m_clock;
	sf::Time m_setTime;
	float m_timer;
	sf::Text m_showTimer;
	sf::RectangleShape m_rectangle;

};