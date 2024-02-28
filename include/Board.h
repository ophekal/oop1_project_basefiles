#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include <fstream>
#include <vector>
#include <string.h>
#include "StaticObjects.h"

class MovingObjects;
class Controller;

class Board
{
public:
	Board();
	void readTheLevel(std::ifstream& levelFile);
	std::vector<std::string> getBoard() const;
	std::vector<std::unique_ptr<StaticObjects>>& getStaticObjects();
	void updateBoard(std::vector<std::unique_ptr<MovingObjects>> & cats, 
		             std::unique_ptr<MovingObjects > &mouse,
					 float& levelTime);
	void updateObjects(std::vector<std::unique_ptr<MovingObjects>>& cats,
		               std::unique_ptr<MovingObjects >& mouse);
	void updateMembers(std::vector<std::unique_ptr<MovingObjects>>& cats, 
		               std::unique_ptr<MovingObjects >& mouse,
		               const char character, int row, int col);
	void checkStaticObjectCollision(std::unique_ptr<MovingObjects>& object,
		                            Controller& controller);
	void printBoard(sf::RenderWindow& window) const;
	sf::Vector2f getTileSize() const;
	const sf::RectangleShape& getRectangle() const;
	void clear();
	void reset();


private:
	
	int m_boardHeight=0;	//to initialize the values
	int m_boardWidth=0;
	sf::Vector2f m_tileSize;
	sf::RectangleShape m_board; 
	std::vector <std::string> m_currLevel;
	std::vector<std::unique_ptr<StaticObjects>> m_staticObjects;


	void pushGift(const sf::Vector2f& position);
	void setMouse(std::unique_ptr<MovingObjects >& mouse,
	              const sf::Vector2f& position);
	void updateBoradSize();
	void pushCat(std::vector<std::unique_ptr<MovingObjects>>& cats,
	             const sf::Texture& icon, sf::Vector2f& position);
	void checkGift(const std::unique_ptr<StaticObjects>& object,
	 	           Controller& controller);
};          

