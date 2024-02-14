#pragma once
#include <SFML/Graphics.hpp>
#include "Clock.h"
#include <vector>
#include "Button.h"

class InfoBar
{
public:
	InfoBar(const sf::Font& font);
	void printInfoBar(sf::RenderWindow& window);

private:
	sf::Text m_numOfKeys;
	sf::Text m_numOfLives;
	sf::Text m_numOfLevel;
	sf::Text m_info;
	Clock m_clock;

	//std::vector<Button*> m_buttons; //button for silencing music of restarting game

	//void setText(const sf::Font& font, std::string text, float x, float y);
};