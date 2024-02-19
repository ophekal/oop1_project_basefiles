#pragma once
#include <SFML/Graphics.hpp>
#include "Clock.h"
#include <vector>
#include "Button.h"

class InfoBar
{
public:
	InfoBar(const sf::Font& font, const sf::Texture& background);
	void printInfoBar(sf::RenderWindow& window);

private:
	sf::Text m_numOfKeys;
	sf::Text m_numOfLives;
	sf::Text m_numOfLevel;
	sf::Text m_info;
	Clock m_clock;

	std::vector< Button> m_infoBar; // for the information
	//std::vector<Button*> m_buttons; //button for silencing music of restarting game

	//void setText(const sf::Font& font, std::string text, float x, float y);
};