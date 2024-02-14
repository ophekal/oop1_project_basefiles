#pragma once
#include <SFML/Graphics.hpp>
#include <memory>

class Clock
{
public:
	Clock();


private:
	sf::Clock m_clock;
	float m_timer;
	sf::RectangleShape m_rectangle;

};