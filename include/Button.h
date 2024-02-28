#pragma once
#include <SFML/Graphics.hpp>
#include "Macros.h"

class Button
{
public:
	Button();
	void updateButton(const sf::Texture& background, float x, float y, const sf::Vector2f size);
	void printButton(sf::RenderWindow& window) const;
	sf::RectangleShape& getRectangleButton();
	void setText(const std::string& text);

private:
	sf::Text m_text;
	sf::RectangleShape m_rectangle;
};