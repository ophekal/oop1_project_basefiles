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
#include "AddTimeGift.h"
#include "FreezeCatGift.h"
#include "KillCatGift.h"
#include "Key.h"
#include "Gift.h"
#include "Door.h"
#include "Wall.h"
#include <memory>
#include "HandleResources.h"
#include <iostream>

//-----------------------------------------------------------------------------
Board::Board()
	: m_board(sf::Vector2f(BOARD_HIG, BOARD_WID))
{
	m_board.setPosition({ BOARD_START_X ,BOARD_START_Y });
	m_board.setTexture(HandleResources::instance().getBackgroundTexture(B_BOARD));
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
void Board::updateBoard(std::vector<std::unique_ptr<MovingObjects>>& cats,
						std::unique_ptr<MovingObjects >& mouse,
						double& levelTime)
{
	m_boardHeight = (int)m_currLevel.size();
	m_boardWidth= (int)m_currLevel[0].size();

	if (m_boardHeight > 15)
	{
		levelTime = SHORT_LEVEL;
	}
	else
	{
		levelTime = LONG_LEVEL;
	}

	updateBoradSize();

	updateObjects(cats,mouse);
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
	m_board.setFillColor(sf::Color::White);
}

//--------------------------------------------------------------------------
//Function that goes through the board and is responsible of calling other
//functions in order to update the game objects' location

void Board::updateObjects(std::vector<std::unique_ptr<MovingObjects>>& cats, 
	                      std::unique_ptr<MovingObjects >& mouse)
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
			updateMembers(cats,mouse,character, row, col);
		}
	}
}

//-----------------------------------------------------------------------------
//This function checks what is the character in the given location and updates
//the relevant members.

void Board::updateMembers(std::vector<std::unique_ptr<MovingObjects>>& cats, std::unique_ptr<MovingObjects >& mouse,
	                      const char character, int row, int col)
{
	// set the position of the current object
	sf::Vector2f position = { (m_tileSize.y * col) + BOARD_START_X,(m_tileSize.x * row) + BOARD_START_Y };

	switch (character)
	{
		case '^':
		{
			const sf::Texture* icon = HandleResources::instance().getObjectTexture(I_L_CAT);
			pushCat(cats, *icon, position);
			return;
		}
		case '%':
		{
			setMouse(mouse, position);
			return;
		}
		case '*':
		{
			const sf::Texture* icon = HandleResources::instance().getObjectTexture(I_CHEESE);
			m_staticObjects.push_back(std::make_unique<Cheese>(*icon, position, m_tileSize));
			return;
		}
		case '$':
		{
			pushGift(position);
			return;
		}
		case 'F':
		{
			const sf::Texture* icon = HandleResources::instance().getObjectTexture(I_KEY);
			m_staticObjects.push_back(std::make_unique<Key>(*icon, position, m_tileSize));
			return;
		}
		case 'D':
		{

			const sf::Texture* icon = HandleResources::instance().getObjectTexture(I_DOOR);
			m_staticObjects.push_back(std::make_unique<Door>(*icon, position, m_tileSize));
			return;
		}
		case '#':
		{

			const sf::Texture* icon = HandleResources::instance().getObjectTexture(I_WALL);
			m_staticObjects.push_back(std::make_unique<Wall>(*icon, position, m_tileSize));
			return;
		}
	}
}
//------------------------------------------------------------------------
void Board::pushCat(std::vector<std::unique_ptr<MovingObjects>>& cats,
	        const sf::Texture& icon, sf::Vector2f& position)
{
	if (Cat::getCount() % 2 == 0)
	{
		cats.push_back(std::make_unique<SmartCat>(icon, position, m_tileSize));
		//cats[Cat::getCount()]->setOrigin();
	}
	else
	{
		cats.push_back(std::make_unique<StupidCat>(icon, position, m_tileSize));
		//cats[Cat::getCount()]->setOrigin();
	}
}
//------------------------------------------------------------------------

void Board::setMouse(std::unique_ptr<MovingObjects >& mouse,
	                 const sf::Vector2f& position)
{
	const sf::Texture* icon = HandleResources::instance().getObjectTexture(I_L_MOUSE);
	mouse = std::make_unique<Mouse>(*icon, position, m_tileSize);

}
//------------------------------------------------------------------------
void Board::pushGift(const sf::Vector2f& position)
{
	int gift = Gift::getCount();

	if (gift % 4 == 0)
	{
		const sf::Texture* icon = HandleResources::instance().getObjectTexture(I_ADDLIFEGIFT);
		m_staticObjects.push_back(std::make_unique<AddLifeGift>(*icon, position, m_tileSize));
	}
	else if (gift % 4 == 1)
	{
		const sf::Texture* icon = HandleResources::instance().getObjectTexture(I_ADDTIMEGIFT);
		m_staticObjects.push_back(std::make_unique<AddTimeGift>(*icon, position, m_tileSize));
	}
	else if (gift % 4 == 2)
	{
		const sf::Texture* icon = HandleResources::instance().getObjectTexture(I_FREEZECATGIFT);
		m_staticObjects.push_back(std::make_unique<FreezeCatGift>(*icon, position, m_tileSize));
	}
	else if (gift % 4 == 3)
	{
		const sf::Texture* icon = HandleResources::instance().getObjectTexture(I_KILLCATGIFT);
		m_staticObjects.push_back(std::make_unique<KillCatGift>(*icon, position, m_tileSize));
	}	
}

//-------------------------------------------------------------------------
void Board::printBoard(sf::RenderWindow& window) const
{
	window.draw(m_board);

	for (size_t index = 0; index < m_staticObjects.size(); index++)
	{
		m_staticObjects[index]->draw(window);	
	}
}

//--------------------------------------------------------------------------
sf::Vector2f Board::getTileSize() const
{
	return m_tileSize;
}
//--------------------------------------------------------------------------
const sf::RectangleShape& Board::getRectangle() const
{
	return m_board;
}

//--------------------------------------------------------------------------
void Board::checkStaticObjectCollision(std::unique_ptr<MovingObjects>& object,
	                                   Controller& controller)
{
	for (auto i = 0; i < m_staticObjects.size(); i++)
	{

		if (object->checkCollision(*m_staticObjects[i]))
		{
			object->collisionHandling(*m_staticObjects[i]);
			checkGift(m_staticObjects[i], controller);

			//std::cout << "on Board?" << m_staticObjects[i]->offBoard() << std::endl;
			break;
		}
	}

	std::erase_if(m_staticObjects, [](const auto& object) {
		return object->offBoard();
		});

}

//------------------------------------------------------------------------
void Board::clear()
{
	m_staticObjects.clear();
	m_currLevel.clear();
	m_tileSize = { 0,0 };
    m_boardHeight = 0;	//to initialize the values
	m_boardWidth = 0;
	m_board.setPosition({ BOARD_START_X ,BOARD_START_Y });
	m_board.setFillColor(sf::Color::White);
}
//------------------------------------------------------------------------
std::vector<std::unique_ptr<StaticObjects>>& Board::getStaticObjects()
{
	return m_staticObjects;

}

//------------------------------------------------------------------------
void Board::checkGift(const std::unique_ptr<StaticObjects>& object,
					  Controller& controller)
{
	Gift* giftPtr = dynamic_cast<Gift*>(object.get());

	if (giftPtr != nullptr)
	{
		if (giftPtr->isActive())
		{
			giftPtr->handleGift(controller);
		}
	}
}