
#include "Controller.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Cat.h"
#include "Mouse.h"
#include "Cheese.h"
#include "HandleResources.h"
#include "MovingObjects.h"
//------------------------------------------------------------------------
//-------------------------------------------------------------------------

void Controller::run(sf::RenderWindow& window)
{
	// open streams for reading from file playlist
	auto line = std::string();
	auto file = std::ifstream("playlist.txt");
	if (!file.is_open())
	{
		std::cerr << "can't open file\n";
		exit(EXIT_FAILURE);
	}

	while (window.isOpen())
	{

		// going through all the level files
		while (std::getline(file, line))
		{
			auto levelFile = std::ifstream(line);
			if (!levelFile.is_open())
			{
				std::cerr << "can't open file\n";
				exit(EXIT_FAILURE);
			}

			m_board.readTheLevel(levelFile);    //the board game is ready
			m_board.updateBoard(m_cats,m_mouse,m_levelTime); //function that also updates the moving objects                  
			m_levelNum++;
			startGame(window);
			if (m_gameOver)
			{
				return;
			}
		}
	}

}
//------------------------------------------------------------------------
void Controller::startGame(sf::RenderWindow& window)
{
	//setting the background of the game
	sf::Sprite background;
	const sf::Texture* gameBackground = HandleResources::instance().getBackgroundTexture(B_GAME);
	background.setTexture(*gameBackground);
	sf::Vector2u textureSize = (*gameBackground).getSize();

	// Scale the background sprite to fit the window
	background.setScale((float)(window.getSize().x) / textureSize.x,
		                (float)(window.getSize().y) / textureSize.y);

	sf::Clock clock;
	int numOfCheese = Cheese::getCount();
	//m_infoBar.setInfoBar(m_levelNum,m_levelTime);
	while (numOfCheese != 0/* && !m_levelOver*/) // m_levelOver =if the time of the level end 
	{
		print(window, background);

		if (auto event = sf::Event{}; window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::MouseButtonReleased:
				handleClick(event.mouseButton,window);
				break;
			}
		}
		const auto deltaTime = clock.restart();
		moveMouse(deltaTime);
		moveCats(deltaTime);
		
		numOfCheese = Cheese::getCount();
		if (checkGameStatus(numOfCheese))
		{
			break;
		}
	}

}
//-----------------------------------------------------------------
void Controller::checkMovingObjectCollision(const std::unique_ptr<MovingObjects>& object)
{
	//checking if collided with cats
	for (auto index = 0; index < m_cats.size(); index++)
	{
		if (object->checkCollision(*m_cats[index]))
		{
			object->collisionHandling(*m_cats[index]);
			break;
		}
	}

	std::erase_if(m_cats, [](const auto& object) {
		return object->offBoard();
		});

	if (object->checkCollision(*m_mouse))
	{
		object->collisionHandling(*m_mouse);
	}

	if (m_mouse->offBoard())
	{
		m_mouseDead = true;
	}
}

//------------------------------------------------------------------------

void Controller::printMovingObjects(sf::RenderWindow& window)const
{
	for (size_t index = 0; index < m_cats.size(); index++)
	{
		m_cats[index]->draw(window);
	}

	m_mouse->draw(window);		
}
//------------------------------------------------------------------------
void Controller::print(sf::RenderWindow& window,sf::Sprite& background)
{
	window.clear();
	window.draw(background);
	m_infoBar.printInfoBar(window);
	m_board.printBoard(window);
	printMovingObjects(window);
	window.display();
}

//--------------------------------------------------------------------------
void Controller::moveMouse(sf::Time deltaTime)
{
	const sf::RectangleShape& boardRectangle = m_board.getRectangle();
	m_mouse->movement(deltaTime, boardRectangle,m_mouse,m_board.getStaticObjects());
	if (m_mouse->positionChange())
	{
		checkMovingObjectCollision(m_mouse);
		m_board.checkStaticObjectCollision(m_mouse, *this);
		m_mouse->move(deltaTime);
	}
}

//--------------------------------------------------------------------------
void Controller::moveCats (sf::Time deltaTime)
{
	for (int i = 0; i < (int)m_cats.size(); i++)
	{
		Cat* catPtr = dynamic_cast<Cat*>(m_cats[i].get());

		if (catPtr != nullptr)
		{
			if (!(catPtr->isFreeze()))
			{
				m_cats[i]->movement(deltaTime, m_board.getRectangle(), m_mouse, m_board.getStaticObjects());
				if (m_cats[i]->positionChange())
				{
					checkMovingObjectCollision(m_cats[i]);
					m_board.checkStaticObjectCollision(m_cats[i], *this);
					std::cout << deltaTime.asSeconds()<< std::endl;
					m_cats[i]->move(deltaTime);
				}
			}
		}

	}
}
//------------------------------------------------------------------------
void Controller::incTime()
{
	m_infoBar.incTime();
}
//------------------------------------------------------------------------
void Controller::incLife()
{
	m_infoBar.incLife();
}
//-----------------------------------------------------------------------
void Controller::freezeCat()
{
	int indexToFreeze = 0;
	findCat(indexToFreeze);
	Cat* catPtr = dynamic_cast<Cat*>(m_cats[indexToFreeze].get());

	if (catPtr != nullptr)
	{
		catPtr->setCatFreeze(true);
	}
	
	// freeze for 3 sec the cat in the index that update

}
//-----------------------------------------------------------------------
void Controller::killCat()
{
	int indexToDelete = 0;
	findCat(indexToDelete);
	m_cats[indexToDelete]->setOffBoard(true);
}

//------------------------------------------------------------------------

void Controller::findCat(int& indexToChange)const
{
	float maxDistance = 0,
		currDistance;
	
	for (auto index = 0; index < m_cats.size(); index++)
	{
		currDistance = m_mouse->distance(m_mouse->getPosition(), m_cats[index]->getPosition());
		if (currDistance > maxDistance)
		{
			maxDistance = currDistance;
			indexToChange = index;
		}
	}

}
//------------------------------------------------------------------------

void Controller::initMovingObjects()
{
	m_mouse->updatePosition(m_mouse->getInitPosition());
	m_mouse->setOffBoard(false);
	for (auto index = 0; index < m_cats.size(); index++)
	{
		m_cats[index]->updatePosition(m_cats[index]->getInitPosition());
	}

}
//-----------------------------------------------------------------------
bool Controller::checkGameStatus(int numOfCheese)
{
	if (m_mouseDead)
	{
		Mouse* mousePtr = dynamic_cast<Mouse*>(m_mouse.get());

		if (mousePtr != nullptr)
		{
			if ((mousePtr->getLives()) == 0)
			{
				handleExit();
				return true;
			}
		}

		//return to the init postion of the moving objects
		handleDeadMouse();
		return false;
	}
	if(checkLevelStatus(numOfCheese))
	{
		return true;
	}
}
//-----------------------------------------------------------------------
bool Controller::checkLevelStatus(int numOfCheese)
{
	//std::cout << "num of cheese that stay? " << Cheese::getCount() << std::endl;
	if (numOfCheese == 0) //to the next level
	{
		m_board.clear();
		m_cats.clear();
		// calc the score to the next level and print sprite that tell that the level end 
		return true;
	}

	if (m_levelOver)
	{
		// start the level again
		handleLevelOver();
		return true;
	}

	return false;
}
//-----------------------------------------------------------------------
void Controller::handleDeadMouse()
{
	// print sprite that tell that the player lost because the cat eat him 

	//function that return the mouse and cat to their first location
	initMovingObjects();
	m_mouseDead = false;
}
//-----------------------------------------------------------------------
void Controller::handleLevelOver()
{
	// print sprite that tell that the level end because the time end,
	Mouse* mousePtr = dynamic_cast<Mouse*>(m_mouse.get());

	if (mousePtr != nullptr)
	{
		mousePtr->setLives();
	}
	// load the same level again with all the objects
	m_board.updateBoard(m_cats, m_mouse,m_levelTime);
}
//----------------------------------------------------------------------

void Controller::handleExit()
{
	m_gameOver = true;
	// print sprite 
}
//----------------------------------------------------------------------

void Controller::handleClick(const sf::Event::MouseButtonEvent& event,const sf::RenderWindow& window)
{
	auto location = window.mapPixelToCoords({ event.x,event.y });

	m_infoBar.handleClick(location,m_gameOver);

}