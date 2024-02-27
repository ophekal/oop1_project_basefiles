#pragma once
#include <SFML/Graphics.hpp>
#include "Clock.h"
#include <vector>
#include "Button.h"
#include <string.h>

class InfoBar
{
public:
	InfoBar();
	void printInfoBar(sf::RenderWindow& window);
	void updateLife(int lives);
	void updateScore(int score);
	void updateKey(int keys);
	void updateLevel(int level);
	void setInfoBar(int levelNum, int score, int key, int lives);
	void handleClick(const sf::Vector2f& location, bool& gameOver);

private:
	std::string m_numOfKeys;
	std::string m_numOfLives;
	std::string m_numOfLevel;
	std::string m_score;
	bool m_musicOn = true;

	std::vector< Button> m_infoBar; // for the information
};