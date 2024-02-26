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
	//sf::Text m_numOfKeys;
	//sf::Text m_numOfLives;
	//sf::Text m_numOfLevel;
	//sf::Text m_score;
	std::string m_numOfKeys;// = "0";
	std::string m_numOfLives;// = "3";
	std::string m_numOfLevel;// = " ";
	std::string m_score;// =// "0";
	bool m_musicOn = true;

	std::vector< Button> m_infoBar; // for the information
	//std::vector<Button*> m_buttons; //button for silencing music of restarting game

};