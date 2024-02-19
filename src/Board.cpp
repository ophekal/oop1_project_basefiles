#include "Board.h"
#include <vector>
#include <fstream>
#include <string.h>
#include "Macros.h"
#include <SFML/Graphics.hpp>
#include "StupidCat.h"
#include "SmartCat.h"
#include "Cat.h"
#include "Mouse.h"
#include "Cheese.h"
#include "AddLifeGift.h"
#include "Key.h"
#include "Door.h"
#include "Wall.h"
#include <memory>

//-----------------------------------------------------------------------------
Board::Board()
	: m_board(sf::Vector2f(BOARD_HIG, BOARD_WID))
{
	m_board.setPosition({ BOARD_START_X ,BOARD_START_Y });
	m_board.setFillColor(sf::Color::White);
}

//-----------------------------------------------------------------------------
void Board::readTheLevel(std::ifstream& levelFile)
{
	// read the level and insert into vector
	for (auto line = std::string(); std::getline(levelFile, line); )
	{
		m_currLevel.push_back(line);
	}
}

//----------------------------------------------------------------------------
std::vector<std::string> Board::getBoard() const
{
	return ((this)->m_currLevel);
}

//-------------------------------------------------------------------------
void Board::updateBoard(std::vector<std::unique_ptr<MovingObjects>>& movingObjects,
	                    const std::vector<sf::Texture>& objectsTextures,
	                    const std::vector<sf::Texture>& backgroundsTextures, int& numOfCheese)
{
	m_boardHeight = (int)m_currLevel.size();
	m_boardWidth= (int)m_currLevel[0].size();

	updateBoradSize();

	updateObjects(movingObjects,objectsTextures,backgroundsTextures,numOfCheese);
}
//--------------------------------------------------------------------------

void Board::updateBoradSize()
{
	float tileHeight = BOARD_HIG / m_boardHeight,
		  tileWidth = BOARD_WID / m_boardWidth;
	float newHeight, newWidth;

	if (tileHeight == tileWidth)
	{
		m_tileSize = { tileHeight,tileWidth };
		//m_board stay the same 
	}
	else if (tileHeight > tileWidth)
	{		
		newHeight= tileWidth * m_boardHeight;
		newWidth = tileWidth * m_boardWidth;
		m_tileSize = { tileWidth,tileWidth };
		m_board.setSize({ newWidth, newHeight });
	}
	else if (tileHeight < tileWidth)
	{
		newWidth = tileHeight * m_boardWidth;
		newHeight = tileHeight * m_boardHeight;
		m_tileSize = { tileHeight,tileHeight };
		m_board.setSize({ newWidth, newHeight });
	}
}

//--------------------------------------------------------------------------
//Function that goes through the board and is responsible of calling other
//functions in order to update the game objects' location

void Board::updateObjects(std::vector<std::unique_ptr<MovingObjects>>& movingObjects,
	                      const std::vector<sf::Texture>& objectsTextures,
	                      const std::vector<sf::Texture>& backgroundsTextures, int& numOfCheese)
{
	auto rows = m_currLevel.size();

	// go through the rows in the board
	for (int row = 0; row < rows; row++)
	{
		std::string currLine = m_currLevel[row];
		auto cols = currLine.size();

		// go through the cols in the board
		for (int col = 0; col < cols; col++)
		{
			char character = currLine[col];
			updateMembers(movingObjects,character, row, col, objectsTextures, backgroundsTextures, numOfCheese);
		}
	}
}

//-----------------------------------------------------------------------------
//This function checks what is the character in the given location and updates
//the relevant members.

void Board::updateMembers(std::vector<std::unique_ptr<MovingObjects>>& movingObjects,
	                      const char character, int row, int col, const std::vector<sf::Texture>& objectsTextures,
	                      const std::vector<sf::Texture>& backgroundsTextures, int& numOfCheese)
{
	// set the position of the current object
	sf::Vector2f position = { (m_tileSize.y * col) + BOARD_START_X,(m_tileSize.x * row) + BOARD_START_Y };

	switch (character)
	{
		case '^':
		{
			if (Cat::getCount() % 2 == 0)
			{
				movingObjects.push_back(std::make_unique<SmartCat>(objectsTextures[I_CAT], position, m_tileSize));
			}
			else
			{
				movingObjects.push_back(std::make_unique<StupidCat>(objectsTextures[I_CAT], position, m_tileSize));
			}

			return;
		}
		case '%':
		{
			movingObjects.push_back(std::make_unique<Mouse>(objectsTextures[I_MOUSE], position, m_tileSize));
			return;
		}
		case '*':
		{
		    numOfCheese ++;
			m_staticObjects.push_back(std::make_unique<Cheese>(objectsTextures[I_CHEESE], position, m_tileSize));
			return;
		}
		case '$':
		{
			m_staticObjects.push_back(std::make_unique<AddLifeGift>(objectsTextures[I_GIFT], position, m_tileSize));
			return;
		}
		case 'F':
		{
			m_staticObjects.push_back(std::make_unique<Key>(objectsTextures[I_KEY], position, m_tileSize));
			return;
		}
		case 'D':
		{
			m_staticObjects.push_back(std::make_unique<Door>(objectsTextures[I_DOOR], position, m_tileSize));
			return;
		}
		case '#':
		{
			m_staticObjects.push_back(std::make_unique<Wall>(objectsTextures[I_WALL], position, m_tileSize));
			return;
		}
	}
}
//------------------------------------------------------------------------

void Board::printBoard(sf::RenderWindow& window) const
{
	window.draw(m_board);

	for (size_t index = 0; index < m_staticObjects.size(); index++)
	{
		m_staticObjects[index]->draw(window);
	}
}

//
//
//
//	//copying from the file the rows into a string
//	for (int row = 0; row < m_row; row++)
//	{
//		std::string currString = level[row];
//		m_col = (m_col < currString.size()) ? (int)currString.size() : m_col;
//		Row currRow = Row();
//
//		for (int col = 0; col < currString.size(); col++)
//		{
//			TileType tileChar = (TileType)(currString[col]);
//			Tile currTile(row, col, tileChar);
//			currRow.push_back(currTile);
//		}
//		m_board.push_back(currRow);
//	}
//
//	addBlankTiles();
//}
//
////------------------------------------------------------------------------
////This constructor is used when there's no existing level, and we read
////the board size from the user
//
//Board::Board(int row, int col)
//	:m_row(row), m_col(col)
//{
//	//updating the m_board row vector
//	for (int i = 0; i < m_row; i++)
//	{
//		Row currRow(col);
//		m_board.push_back(currRow);
//		updateTileCoord(i, m_col);
//	}
//
//}
//
////-------------------------------------------------------------------------
//
////-------------------------------------------------------------------------
//
//void Board::printBoard(sf::RenderWindow& window, const std::vector<sf::Texture>& icons) const
//{
//	for (int row = 0; row < m_row; row++)
//	{
//		m_board[row].printRow(window, icons);
//	}
//}
//
////------------------------------------------------------------------------
//
//int Board::getCol()const
//{
//	return m_col;
//}
//
////-------------------------------------------------------------------------
//
//int Board::getRow() const
//{
//	return m_row;
//}
//
////--------------------------------------------------------------------------
////This function sends to the tile that's in col place in row the buttontype
////we pressed on in the toolbar
//
//void Board::setTileIcon(int row, int col, ButtonType pressed)
//{
//	m_board[row].at(col).setTileIcon(pressed);
//}
//
////--------------------------------------------------------------------------
////This function finds the mouse in the board and updates the x and y values.
//
//void Board::findMouseCoords(int& x, int& y) const
//{
//	for (int row = 0; row < m_row; row++)
//	{
//		for (int col = 0; col < m_col; col++)
//		{
//			if (m_board[row].at(col).getChar() == T_MOUSE)
//			{
//				y = row;
//				x = col;
//				return;
//			}
//		}
//	}
//}
//
////------------------------------------------------------------------------
//
//void Board::saveBoardAndCopyToText(std::ofstream& board) const
//{
//	for (int row = 0; row < m_row; row++)
//	{
//		for (int col = 0; col < m_col; col++)
//		{
//			TileType currChar = m_board[row].at(col).getChar();
//			board << (char)currChar;
//		}
//		board << "\n";
//	}
//}
