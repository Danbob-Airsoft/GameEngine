#pragma once
#include "ResourceManager.h"
#include "SFML/Graphics.hpp"

class Obstacle
{
public:
	Obstacle(ResourceManager* EngineResources, sf::RenderWindow* Window);

	sf::Sprite ObstacleSprite;
};

