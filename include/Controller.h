#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "MovingObjects.h"
#include "Board.h"
#include "InfoBar.h"
#include "Clock.h"

class Controller
{
public:
	Controller() = default;
	void run(sf::RenderWindow& window, bool& musicOn);
	void incTime();
	void incLife();
	void freezeCat();
	void killCat();

private:
	
	Board m_board;
	InfoBar m_infoBar;
	Clock m_clock;

	int m_levelNum = 0;	
	float m_levelTime=0;
	std::vector<std::unique_ptr<MovingObjects>> m_cats;
	std::unique_ptr<MovingObjects> m_mouse;
	std::vector<std::string> m_playlist;
	bool m_levelOver = false;
	bool m_mouseDead = false;
	bool m_gameOver = false;
	int m_totalScore = 0;
	int m_prevLevelsScore = 0;
	
	void startGame(sf::RenderWindow& window, const sf::Sprite& background, bool& musicOn);
	void handleWindow(sf::RenderWindow& window, std::string& line,
		              std::ifstream& file, const sf::Sprite& backgroud, bool& musicOn);
	void handleDeadMouse(sf::RenderWindow& window, const sf::Sprite& background);
	void printMovingObjects(sf::RenderWindow& window)const;
	void print(sf::RenderWindow& window, const sf::Sprite& background);
	void printFeedback(const sf::Texture& feedback, sf::RenderWindow& window,
		               const sf::Sprite& background, GameSound sound)const;
	bool checkGameStatus(int numOfCheese, int numOfCats, sf::RenderWindow& window,
		                 const sf::Sprite& background, bool& musicOn);
	bool checkLevelStatus(int numOfCheese, int numOfCats, sf::RenderWindow& window,
		                  const sf::Sprite& background, bool& musicOn);
	void updateGameBackground(const sf::RenderWindow& window, sf::Sprite& background);
	void moveMouse(sf::Time deltaTime);
	void moveCats(sf::Time deltaTime);
	void checkMovingObjectCollision(const std::unique_ptr<MovingObjects>& object);
	void findCat(int& indexToChange)const;
	void initMovingObjects();
	void handleLevelOver(sf::RenderWindow& window, const sf::Sprite& background, bool& musicOn);
	void handleExit(sf::RenderWindow& window, const sf::Sprite& background);
	void handleClick(const sf::Event::MouseButtonEvent& event, const sf::RenderWindow& window, bool& musicOn);
	void updateInfoBar(bool& musicOn);
	void updateMouseScore();
	void printFinalScore(sf::RenderWindow& window);
};