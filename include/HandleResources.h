#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include <string.h>
#include <vector>

class HandleResources
{
public:
	HandleResources();   //update all the resources of the play

private:
	void updateObjectVector();
	void updateBackgroundVector();

	std::vector<sf::Texture> m_objectsTextures;
	std::vector<sf::Texture> m_backgroundsTextures;	//menu, infobar, window

	sf::Font m_font;				//holds the font
	//sf::Sound m_sounds[numOfSounds];	//hold the different sounds of the game
	//sf::SoundBuffer m_soundBuffer[numOfSounds];

};