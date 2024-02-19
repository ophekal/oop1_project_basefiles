#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "MovingObjects.h"
#include "Board.h"
#include "InfoBar.h"
#include "Mouse.h"

class Cat;
class Mouse;

class Controller
{
public:
	Controller(sf::Font& font, const sf::Texture& background);
	void run(sf::RenderWindow& window, const std::vector<sf::Texture>& objectsTextures,
		     const std::vector<sf::Texture>& backgroundsTextures);

private:
	
	Board m_board;
	InfoBar m_infoBar;
	
	int m_levelNum = 0;	//saves the level number

	//std::vector<std::unique_ptr<MovingObjects>> m_movingObjects;
	std::vector<std::string> m_playlist;

	int m_numOfCheese = 0;
	//Mouse m_mouse;
	std::unique_ptr<Mouse> m_mouse;
	std::vector<std::unique_ptr<Cat>> m_cats;

	void startGame(sf::RenderWindow& window, const std::vector<sf::Texture>& objectsTextures,
	            	const std::vector<sf::Texture>& backgroundsTextures);
	void printMovingObjects(sf::RenderWindow& window)const;
	void print(sf::RenderWindow& window, sf::Sprite& background);
};