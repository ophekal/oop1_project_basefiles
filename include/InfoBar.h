#pragma once
#include <SFML/Graphics.hpp>
#include "Clock.h"
#include <vector>
#include "Button.h"

class InfoBar
{
public:
	InfoBar();
	void printInfoBar(sf::RenderWindow& window);
	void incLife();
	void setInfoBar(int levelNum, int levelTime);
	void handleClick(const sf::Vector2f& location, bool& gameOver);

private:
	sf::Text m_numOfKeys;
	sf::Text m_numOfLives;
	sf::Text m_numOfLevel;
	sf::Text m_score;

	std::vector< Button> m_infoBar; // for the information
	//std::vector<Button*> m_buttons; //button for silencing music of restarting game

};