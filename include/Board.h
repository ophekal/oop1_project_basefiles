#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include <fstream>
#include <vector>
#include <string.h>
#include "StaticObjects.h"
#include "Macros.h"

class MovingObjects;
class Mouse;
class Cat;

class Board
{
public:
	Board();
	void readTheLevel(std::ifstream& levelFile);
	std::vector<std::string> getBoard() const;
	void updateBoard(std::vector<std::unique_ptr<MovingObjects>> & cats, std::vector<std::unique_ptr<MovingObjects>>& mouse, const std::vector<sf::Texture>& objectsTextures,
		             const std::vector<sf::Texture>& backgroundsTextures, int& numOfCheese);
	void updateObjects(std::vector<std::unique_ptr<MovingObjects>>& cats, std::vector <std::unique_ptr<MovingObjects>> & mouse,const std::vector<sf::Texture>& objectsTextures,
	                	const std::vector<sf::Texture>& backgroundsTextures, int& numOfCheese);
	void updateMembers(std::vector<std::unique_ptr<MovingObjects>>& cats, std::vector <std::unique_ptr<MovingObjects>>& mouse,
		               const char character, int row, int col,const std::vector<sf::Texture>& objectsTextures,
		               const std::vector<sf::Texture>& backgroundsTextures, int& numOfCheese);
	void printBoard(sf::RenderWindow& window) const;

private:
	
	int m_boardHeight=0;	//to initialize the values
	int m_boardWidth=0;

	//int m_tilesInRow;
	//int m_tilesInCol;

	sf::Vector2f m_tileSize;

	/*float m_tileHeight=0;
	float m_tileWidth=0;*/

	sf::RectangleShape m_board; //hold the level itself
	std::vector <std::string> m_currLevel;
	std::vector<std::unique_ptr<StaticObjects>> m_staticObjects;

	void updateBoradSize();

};

