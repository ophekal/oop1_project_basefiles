
#include "Controller.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Cat.h"
#include "Mouse.h"
#include "Cheese.h"
#include "HandleResources.h"
#include "MovingObjects.h"
#include "Clock.h"


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

	sf::Sprite background;
	updateGameBackground(window,background);

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
			updateMouseScore();
			m_levelNum++;
			startGame(window, background);
			if (m_gameOver)
			{
				return;
			}
		}
		printFeedback(*HandleResources::instance().getScreenTexture(S_WIN), window, background);
		return;
	}

}
//------------------------------------------------------------------------
void Controller::updateGameBackground(const sf::RenderWindow& window,sf::Sprite& background)
{
	//setting the background of the game
	const sf::Texture* gameBackground = HandleResources::instance().getBackgroundTexture(B_GAME);
	background.setTexture(*gameBackground);
	sf::Vector2u textureSize = (*gameBackground).getSize();

	// Scale the background sprite to fit the window
	background.setScale((float)(window.getSize().x) / textureSize.x,
		(float)(window.getSize().y) / textureSize.y);
}
//------------------------------------------------------------------------
void Controller::startGame(sf::RenderWindow& window, const sf::Sprite& background)
{
	//clock for handeling movements
	sf::Clock clock= m_clock.getClock();

	int numOfCheese = Cheese::getCount();
	updateInfoBar();

	//tracks time of the level
	m_clock.setClock(m_levelTime, m_levelOver);

	int numOfCats = Cat::getCount();
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
				if (m_gameOver)
				{
					return;
				}
				break;
			}
		}
		const auto deltaTime = clock.restart();
		moveMouse(deltaTime);
		moveCats(deltaTime);
		updateInfoBar();
		
		numOfCheese = Cheese::getCount();
		if (checkGameStatus(numOfCheese, numOfCats,window,background))
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
void Controller::print(sf::RenderWindow& window,const sf::Sprite& background)
{
	window.clear();
	window.draw(background);
	m_infoBar.printInfoBar(window);
	m_clock.printClock(window, m_levelOver);//pass the curr time
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
			if (catPtr->isFreeze())
			{
				sf::Time elapsedTime = m_clock.getClock().getElapsedTime() - catPtr->getFreezeStartTime();

				//sf::Time elapsedTime = clock.getElapsedTime() - catPtr->getFreezeStartTime();
				if (elapsedTime >= sf::seconds(4.0f))
				{
					catPtr->setCatFreeze(false);
				}
			}
			else 
			{
				m_cats[i]->movement(deltaTime, m_board.getRectangle(), m_mouse, m_board.getStaticObjects());
				if (m_cats[i]->positionChange())
				{
					checkMovingObjectCollision(m_cats[i]);
					m_board.checkStaticObjectCollision(m_cats[i], *this);
					m_cats[i]->move(deltaTime);
				}
			}
		}

	}
}
//------------------------------------------------------------------------
void Controller::incTime()
{
	m_clock.incTime();
}
//------------------------------------------------------------------------
void Controller::incLife()
{
	Mouse* mousePtr = dynamic_cast<Mouse*>(m_mouse.get());

	if (mousePtr != nullptr)
	{
		mousePtr->setLives(1);
	}	
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
		catPtr->setFreezeStartTime(m_clock.getClock().getElapsedTime());
		//catPtr->setFreezeStartTime(clock.getClock().getElapsedTime());
	}

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
bool Controller::checkGameStatus(int numOfCheese, int numOfCats, sf::RenderWindow& window,
	                             const sf::Sprite& background)
{
	if (m_mouseDead)
	{
		Mouse* mousePtr = dynamic_cast<Mouse*>(m_mouse.get());

		if (mousePtr != nullptr)
		{
			if ((mousePtr->getLives()) == 0)
			{
				handleExit(window, background);
				return true;
			}
		}

		//return to the init postion of the moving objects
		handleDeadMouse(window, background);
		return false;
	}
	if(checkLevelStatus(numOfCheese, numOfCats,window, background))
	{
		return true;
	}
	return false;
}
//-----------------------------------------------------------------------
bool Controller::checkLevelStatus(int numOfCheese, int numOfCats, sf::RenderWindow& window,
	                              const sf::Sprite& background)
{
	if (numOfCheese == 0) //to the next level
	{
		printFeedback(*HandleResources::instance().getScreenTexture(S_GOODJOB),window, background);
		Mouse* mousePtr = dynamic_cast<Mouse*>(m_mouse.get());
		if (mousePtr != nullptr)
		{
			m_totalScore = mousePtr->getScore();
			m_totalScore += 25;  
			m_totalScore += (5 * numOfCats);
		}
		m_board.clear();
		m_cats.clear();
		return true;
	}

	if (m_levelOver)
	{
		// start the level again
		handleLevelOver(window, background);
		return true;
	}

	return false;
}
//-----------------------------------------------------------------------
void Controller::handleDeadMouse(sf::RenderWindow& window, const sf::Sprite& background)
{
	// print sprite that tell that the player lost because the cat eat him 
	printFeedback(*HandleResources::instance().getScreenTexture(S_TRYAGAIN),window, background);
	//function that return the mouse and cat to their first location
	initMovingObjects();
	m_mouseDead = false;
}
//-----------------------------------------------------------------------
void Controller::handleLevelOver(sf::RenderWindow& window, const sf::Sprite& background)
{
	// print sprite that tell that the level end because the time end,
	printFeedback(*HandleResources::instance().getScreenTexture(S_TRYAGAIN),window, background);
	Mouse* mousePtr = dynamic_cast<Mouse*>(m_mouse.get());

	if (mousePtr != nullptr)
	{
		mousePtr->setLives(-1);
	}
	// load the same level again with all the objects
	m_board.updateBoard(m_cats, m_mouse,m_levelTime);
}
//----------------------------------------------------------------------

void Controller::handleExit(sf::RenderWindow& window, const sf::Sprite& background)
{
	m_gameOver = true;
	printFeedback(*HandleResources::instance().getScreenTexture(S_GAMEOVER),window, background);
}
//----------------------------------------------------------------------

void Controller::handleClick(const sf::Event::MouseButtonEvent& event,
	                         const sf::RenderWindow& window)
{
	auto location = window.mapPixelToCoords({ event.x,event.y });

	m_infoBar.handleClick(location,m_gameOver);

}
//------------------------------------------------------------------------
void Controller::updateInfoBar()
{
	Mouse* mousePtr = dynamic_cast<Mouse*>(m_mouse.get());
	int keys = 0;
	int lives = 0;

	if (mousePtr != nullptr)
	{
		keys = mousePtr->getKeys();
		m_totalScore = mousePtr->getScore();
		lives = mousePtr->getLives();
	}
	m_infoBar.setInfoBar(m_levelNum, m_totalScore, keys, lives);
}
//------------------------------------------------------------------------
void Controller::updateMouseScore()
{
	Mouse* mousePtr = dynamic_cast<Mouse*>(m_mouse.get());
	if (mousePtr != nullptr)
	{
		mousePtr->setScore(m_totalScore);
	}
}
//------------------------------------------------------------------------

void Controller::printFeedback(const sf::Texture& feedback, 
	                           sf::RenderWindow& window,
	                           const sf::Sprite& background)const
{
	// Create a sprite using the feedback texture
	sf::Sprite sprite(feedback);
	sprite.setPosition(window.getSize().x / 2.0f - sprite.getLocalBounds().width / 2.0f,
		window.getSize().y / 2.0f - sprite.getLocalBounds().height / 2.0f);

	// Clear the window
	window.clear();

	// Draw the sprite onto the window
	window.draw(background);
	window.draw(sprite);

	// Display the content of the window
	window.display();
	sf::sleep(sf::seconds(1));
}