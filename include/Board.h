#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include <fstream>
#include <vector>
#include <string.h>
#include "StaticObjects.h"
#include "Macros.h"

class MovingObjects;
class Controller;

class Board
{
public:
	Board();
	void readTheLevel(std::ifstream& levelFile);
	std::vector<std::string> getBoard() const;
	void updateBoard(std::vector<std::unique_ptr<MovingObjects>> & cats, 
		             std::unique_ptr<MovingObjects > &mouse,
					 float& levelTime);
	void updateObjects(std::vector<std::unique_ptr<MovingObjects>>& cats, std::unique_ptr<MovingObjects >& mouse);
	void updateMembers(std::vector<std::unique_ptr<MovingObjects>>& cats, std::unique_ptr<MovingObjects >& mouse,
		               const char character, int row, int col);
	void checkStaticObjectCollision(std::unique_ptr<MovingObjects>& object,
		                            Controller& controller);
	void printBoard(sf::RenderWindow& window) const;
	sf::Vector2f getTileSize() const;
	const sf::RectangleShape& getRectangle() const;
	void clear();
	void reset();
	std::vector<std::unique_ptr<StaticObjects>>& getStaticObjects();

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
	void pushCat(std::vector<std::unique_ptr<MovingObjects>>& cats,
		         const sf::Texture& icon, sf::Vector2f& position);
	void pushGift(const sf::Vector2f& position);
	void setMouse(std::unique_ptr<MovingObjects >& mouse,
	              const sf::Vector2f& position);
	void checkGift(const std::unique_ptr<StaticObjects>& object,
	 	           Controller& controller);
};          

