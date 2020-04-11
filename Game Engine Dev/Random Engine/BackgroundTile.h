#pragma once
#include "SFML/Graphics.hpp"
#include "ResourceManager.h"

class BackgroundTile: public sf::Transformable
{
public:
	void CreateSprite(sf::RenderWindow* window, sf::Texture& TileTexture, int Xpos, int Ypos);
	void CreateBackgroundVector(sf::RenderWindow* window, ResourceManager* EngineResource);
	void DrawBackground(sf::RenderWindow* Window);
	sf::Sprite TileSprite;
	std::vector<sf::Sprite> BackgroundSprites;
	bool FirstLoad;
};

