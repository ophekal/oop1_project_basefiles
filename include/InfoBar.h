#pragma once
#include <SFML/Graphics.hpp>
#include "Clock.h"
#include <vector>
#include "Button.h"

class InfoBar
{
public:
	InfoBar();
	void printInfoBar(sf::RenderWindow& window) const;

private:
	sf::Text m_numOfKeys;
	sf::Text m_numOfLives;
	sf::Text m_numOfLevel;
	sf::Text m_showTimer;
	Clock m_clock;

	std::vector<Button*> m_buttons; //button for silencing music of restarting game
};