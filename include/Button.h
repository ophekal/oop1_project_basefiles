#pragma once
#include <SFML/Graphics.hpp>
#include "Macros.h"

class Button
{
public:
	Button();
	void updateSize(float width, float hight);
	void updateButton(const sf::Texture& background, float x, float y, const sf::Vector2f size);

	/*void updateButton(const sf::Font& font,const sf::Texture& background,
		              std::string type, float x, float y, int textSize);*/
	void printButton(sf::RenderWindow& window) const;
	sf::RectangleShape getRectangleButton()const;

private:
	sf::Text m_text;
	sf::RectangleShape m_rectangle;

	//sf::Sound m_buttonSound;	//the sound when a button is pressed
};