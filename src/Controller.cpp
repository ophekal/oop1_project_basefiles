
#include "Controller.h"
#include <SFML/Graphics.hpp>
#include <iostream>
//------------------------------------------------------------------------

Controller::Controller(sf::Font& font)
	:m_infoBar(font)
{

}
//-------------------------------------------------------------------------

void Controller::run(sf::RenderWindow& window,const std::vector<sf::Texture>& objectsTextures,
	                const std::vector<sf::Texture>& backgroundsTextures)
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
		m_board.updateBoard(m_movingObjects, objectsTextures, backgroundsTextures,m_numOfCheese); //function that also updates the moving objects
		/*checkMembers(); */                    
		m_levelNum++;
		startGame();
	}

}