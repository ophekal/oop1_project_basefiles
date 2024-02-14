#pragma once
#include <SFML/Graphics.hpp>
#include <memory>

class Clock
{
public:
	Clock() = default;
//	Clock();//pass the time of the game
	void printClock(sf::RenderWindow& window);
	// setTimer();

private:
	sf::Clock m_clock;
	float m_timer;
	sf::Text m_showTimer;
	sf::RectangleShape m_rectangle;

};