#pragma once
#include <SFML/Graphics.hpp>
#include "Button.h"


Button::Button()
    :m_rectangle(sf::Vector2f(200.f, 100.f))
{
}

void Button::updateButton(const sf::Font& font, std::string type, float x, float y)
{
    //Set the position and color of the rectangle
    m_rectangle.setPosition(x,y);
    m_rectangle.setFillColor(sf::Color::White);
    m_text.setFont(font);
    m_text.setString(type);
    m_text.setCharacterSize(24);
    m_text.setFillColor(sf::Color::Black);

    // Set the position of the text (relative to the rectangle)
    m_text.setPosition(130.f, 120.f);

}

void Button::printButton(sf::RenderWindow& window) const
{
    window.draw(m_text);
}
