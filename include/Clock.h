#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "Button.h"

class Clock
{
public:
	Clock() = default;
	void setClock(double levelTime);
	void updateTime(float time);
   //Clock();//pass the time of the game
	void printClock(sf::RenderWindow& window);
	void incTime();
	const sf::Clock& getClock()const;
	// setTimer();

private:
	sf::Clock m_clock;
	sf::Time m_setTime;
	float m_timer;

	Button m_rectangle;
	//sf::Text m_showTimer;
	//sf::RectangleShape m_rectangle;

};