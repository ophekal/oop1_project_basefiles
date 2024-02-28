#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Button.h"
#include <string.h>

class MovingObjects;

class InfoBar
{
public:
	InfoBar();
	void printInfoBar(sf::RenderWindow& window);
	void updateLife(int lives);
	void updateScore(int score);
	void updateKey(int keys);
	void updateLevel(int level);
	void setInfoBar(int levelNum, int score, int key, int lives, bool& musicOn);
	void handleClick(const sf::Vector2f& location, bool& gameOver, bool& levelOver,
		             std::unique_ptr<MovingObjects>& mouse, bool& musicOn);
	void updateMusic(bool& musicOn);
	void checkMusic(const bool& musicOn);


private:
	std::string m_numOfKeys;
	std::string m_numOfLives;
	std::string m_numOfLevel;
	std::string m_score;
	std::vector< Button> m_infoBar; 
};