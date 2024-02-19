
#include "Controller.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Cat.h"
#include "Mouse.h"
//------------------------------------------------------------------------

Controller::Controller(sf::Font& font, const sf::Texture& background)
	:m_infoBar(font, background)
{

}
//-------------------------------------------------------------------------

void Controller::run(sf::RenderWindow& window,const std::vector<sf::Texture>& objectsTextures,
	                const std::vector<sf::Texture>& backgroundsTextures)
{
	while (window.isOpen())
	{
		// open streams for reading from file playlist
		auto line = std::string();
		auto file = std::ifstream("playlist.txt");
		if (!file.is_open())
		{
			std::cerr << "can't open file\n";
			exit(EXIT_FAILURE);
		}

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
			m_board.updateBoard(m_cats,m_mouse, objectsTextures, backgroundsTextures, m_numOfCheese); //function that also updates the moving objects                  
			m_levelNum++;
			startGame(window, objectsTextures, backgroundsTextures);
		}
	}

}
//------------------------------------------------------------------------
void Controller::startGame(sf::RenderWindow& window, const std::vector<sf::Texture>& objectsTextures,
	                       const std::vector<sf::Texture>& backgroundsTextures)
{
	//we need to start the clock;
	sf::Sprite background;
	background.setTexture(backgroundsTextures[1]);
	sf::Vector2u textureSize = backgroundsTextures[1].getSize();

	// Scale the background sprite to fit the window
	background.setScale((float)(window.getSize().x) / textureSize.x,
		                (float)(window.getSize().y) / textureSize.y);

	sf::Clock clock;
	//const auto deltaTime = clock.restart();

	while (m_numOfCheese != 0) // and if the time of the level end 
	{
		const auto deltaTime = clock.restart();
		print(window, background);

		if (auto event = sf::Event{}; window.waitEvent(event))
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

		m_mouse->movement(deltaTime);
		moveCats(deltaTime);
	}
}
	//if (auto event = sf::Event{}; window.pollEvent(event))
	//{
	//	switch (event.type)
	//	{
	//	case sf::Event::Closed:
	//		m_window.close();
	//		break;
	//	case sf::Event::MouseButtonReleased:
	//		if (m_reloadButton.contain(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
	//			controller.newLevel();
	//		else if (m_musicButton.contain(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
	//		{
	//			if (m_gameSound.getStatus() == m_gameSound.Playing)
	//				m_gameSound.stop();
	//			else
	//				m_gameSound.play();
	//		}
	//		break;
	//	}
	//}

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
void Controller::moveCats (sf::Time deltaTime)
{
	for (int i = 0; i < (int)m_cats.size(); i++)
	{
		m_cats[i]->movement(deltaTime);
	}
}