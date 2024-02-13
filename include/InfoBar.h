#pragma once
#include <SFML/Graphics.hpp>

Class InfoBar
{
public:
	Button();
	void printInfoBar(sf::RenderWindow& window) const;

private:
	sf::Text m_numOfKeys;
	sf::Text m_numOfLives
	sf::Text m_numOfLevel;
	sf::Text m_showTimer;
	sf::Clock m_timer;

	std::Vector<Button*> m_buttons //button for silencing music of restarting game
}