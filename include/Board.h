#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include <fstream>

Class Board
{
public:
	Board();
	void print();

private:
	int m_startBoardX;	//in order to know where to draw the board
	int m_startBoardY;
	int m_boardHeight;
	int m_boardLength;

	float m_tileSize;		//holds the size of "tiles" in the level
	std::ifstream m_fileStream;

	sf::RectangleShape m_board	//hold the level itself

	std::vector<std::unique_ptr<StaticObjects>> m_staticObjects;

};

