
#include "Controller.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Cat.h"
#include "Mouse.h"
#include "Cheese.h"
#include "HandleResources.h"

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
			m_board.updateBoard(m_cats,m_mouse); //function that also updates the moving objects                  
			m_levelNum++;
			startGame(window);
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

	while (Cheese::getCount != 0 && !m_levelOver) // and if the time of the level end 
	{
		print(window, background);

		if (auto event = sf::Event{}; window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
				//case sf::Event::MouseButtonReleased:
					//handleClick(event.mouseButton);
				//	break;
			}
		}
		const auto deltaTime = clock.restart();

		moveMouse(deltaTime);
		moveCats(deltaTime);
		
		//std::cout << "num of cheese that stay? " << Cheese::getCount() << std::endl;
		if (Cheese::getCount() == 0)
		{
			m_board.clear();
			m_cats.clear();
			break;
		}
	}


	if (m_levelOver)
	{

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
		m_levelOver = true;
	}
}

//------------------------------------------------------------------------

void Controller::printMovingObjects(sf::RenderWindow& window)const
{
	for (size_t index = 0; index < m_cats.size(); index++)
	{
		if (!(m_cats[index]->isCovered()))
		{
			m_cats[index]->draw(window);
		}
		
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
	m_mouse->movement(deltaTime, boardRectangle);
	if (m_mouse->positionChange())
	{
		checkMovingObjectCollision(m_mouse);
		m_board.checkStaticObjectCollision(m_mouse);
		m_mouse->move(deltaTime);
	}
}

//--------------------------------------------------------------------------
void Controller::moveCats (sf::Time deltaTime)
{
	for (int i = 0; i < (int)m_cats.size(); i++)
	{
		m_cats[i]->movement(deltaTime,m_board.getRectangle());
		if (m_cats[i]->positionChange())
		{
			checkMovingObjectCollision(m_cats[i]);
			m_board.checkStaticObjectCollision(m_cats[i]);
			m_cats[i]->move(deltaTime);
		}
	}
}