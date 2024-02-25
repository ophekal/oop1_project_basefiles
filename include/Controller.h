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
	Controller() = default;
	void run(sf::RenderWindow& window);

private:
	
	Board m_board;
	InfoBar m_infoBar;
	
	int m_levelNum = 0;	//saves the level number

	std::vector<std::unique_ptr<MovingObjects>> m_cats;
	std::unique_ptr<MovingObjects> m_mouse;
	std::vector<std::string> m_playlist;
	bool m_levelOver = false;
	//int m_numOfCheese = 0;
	
	void startGame(sf::RenderWindow& window);
	void printMovingObjects(sf::RenderWindow& window)const;
	void print(sf::RenderWindow& window, sf::Sprite& background);
	void moveMouse(sf::Time deltaTime);
	void moveCats(sf::Time deltaTime);
	void checkMovingObjectCollision(const std::unique_ptr<MovingObjects>& object);


};