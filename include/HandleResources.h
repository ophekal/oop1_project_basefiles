#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include <string.h>
#include <vector>
#include "Macros.h"

class HandleResources
{
public:
	static HandleResources& instance();

	const sf::Texture* getObjectTexture(IconType icon);
	const sf::Texture* getBackgroundTexture(Background icon);
	const sf::Texture* getInfoBarTextures(Bar icon);
	const sf::Font* getFont();
	//static HandleResources& getSounds();
	

private:
	HandleResources();   //update all the resources of the play
	//~HandleResources() = delete;   
	void updateObjectVector();
	void updateBackgroundVector();

	std::vector<sf::Texture> m_objectsTextures;
	std::vector<sf::Texture> m_backgroundsTextures;	//menu, infobar, window
	std::vector<sf::Texture> m_infoBarTextures;	//menu, infobar, window

	sf::Font m_font;				//holds the font
	//sf::Sound m_sounds[numOfSounds];	//hold the different sounds of the game
	//sf::SoundBuffer m_soundBuffer[numOfSounds];

};