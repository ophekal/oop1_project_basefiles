#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include <fstream>
#include <vector>
#include <string.h>
#include "StaticObjects.h"
#include "Macros.h"

class MovingObjects;

class Board
{
public:
	Board();
	void readTheLevel(std::ifstream& levelFile);
	std::vector<std::string> getBoard() const;
	void updateBoard(std::vector<std::unique_ptr<MovingObjects>>& movingObjects);
	void updateObjects(std::vector<std::unique_ptr<MovingObjects>>& movingObjects);
	//void print(sf::RenderWindow &);

private:
	
	int m_boardHeight=0;	//to initialize the values
	int m_boardWidth=0;

	//int m_tilesInRow;
	//int m_tilesInCol;
	float m_tileHeight=0;
	float m_tileWidth=0;

	sf::RectangleShape m_board; //hold the level itself
	std::vector <std::string> m_currLevel;
	std::vector<std::unique_ptr<StaticObjects>> m_staticObjects;

};

