#pragma once
#include <SFML/Graphics.hpp>
#include "Button.h"

//---------------------------------------------------------------------------------------

Button::Button()
    :m_rectangle(sf::Vector2f(400.f, 150.f))
{
}

//---------------------------------------------------------------------------------------

void Button::updateButton(const sf::Font& font, std::string type, float x, float y)
{
    //Set the position and color of the rectangle
    m_rectangle.setPosition(x,y);
    m_rectangle.setFillColor(sf::Color::White);
    m_text.setFont(font);
    m_text.setString(type);
    m_text.setCharacterSize(48);
    m_text.setFillColor(sf::Color::Black);

    // Set the position of the text to be centered within the rectangle
    sf::FloatRect textBounds = m_text.getLocalBounds();
    float textX = x + (m_rectangle.getSize().x - textBounds.width) / 2;
    float textY = y + (m_rectangle.getSize().y - textBounds.height) / 2;
    m_text.setPosition(textX, textY);
}

//---------------------------------------------------------------------------------------

void Button::printButton(sf::RenderWindow& window) const
{
    window.draw(m_rectangle);
    window.draw(m_text);
}

//-------------------------------------------------------------
sf::RectangleShape Button::getRectangleButton()const
{
    return m_rectangle;
}
