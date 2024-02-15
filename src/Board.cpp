#include "Board.h"
#include <vector>
#include <fstream>
#include <string.h>
#include "Macros.h"

//-----------------------------------------------------------------------------
Board::Board()
	: m_board(sf::Vector2f(BOARD_HIG, BOARD_WID))
{

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
void Board::updateBoard(std::vector<std::unique_ptr<MovingObjects>> &movingObjects)
{
	m_boardHeight = (int)m_currLevel.size();
	m_boardWidth= (int)m_currLevel[0].size();

	//int numOfTiles = m_boardHeight * m_boardWidth; //500

	m_tileHeight = BOARD_HIG / m_boardHeight,
	m_tileWidth = BOARD_WID / m_boardWidth;

	updateStaticObjects(std::vector<std::unique_ptr<MovingObjects>>&movingObjects);
}

//--------------------------------------------------------------------------
//Function that goes through the board and updates the locations of the
//static objects

void Board::updateStaticObjects(std::vector<std::unique_ptr<MovingObjects>>& movingObjects)
{
	auto rows = m_board.getBoard().size();

		// go through the rows in the board
		for (int row = 0; row < rows; row++)
		{
			std::string currLine = (m_board.getBoard())[row];
			auto cols = currLine.size();

			// go through the cols in the board
			for (int col = 0; col < cols; col++)
			{
				char character = currLine[col];
				Location place;
				place.col = col;
				place.row = row;

				updateMembers(character, place);
			}
		}
}

	//-----------------------------------------------------------------------------
	//This function checks what is the character in the given location and updates
	//the relevant members.

	void GameController::updateMembers(const char character,
		const Location & place)
	{
		switch (character)
		{
		case '^':
		{
			Cat kitten;				//calling the default constructor 
			kitten.setLocation(place);
			kitten.setInitLocation(place);
			m_cats.push_back(kitten);
			return;
		}
		case '%':
		{
			m_mouse.setInitLocation(place);
			m_mouse.setLocation(place);
			return;
		}
		case '*':
		{
			int numOfCheeses = m_board.getCheeses() + 1;
			m_board.setCheeses(numOfCheeses);
			return;
		}
		}
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
