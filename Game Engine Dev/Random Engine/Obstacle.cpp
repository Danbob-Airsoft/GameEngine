#include "pch.h"
#include "Obstacle.h"

Obstacle::Obstacle(ResourceManager* EngineResources, sf::RenderWindow* Window)
{
	ObstacleSprite.setTexture(EngineResources->WoodCrateTexture);
	ObstacleSprite.setOrigin(sf::Vector2f(ObstacleSprite.getTexture()->getSize().x / 2, ObstacleSprite.getTexture()->getSize().y / 2));
	ObstacleSprite.setRotation(0);
	float Size = rand() % 1 + 1;
	ObstacleSprite.setScale(sf::Vector2f(Size, Size));
	ObstacleSprite.setPosition(sf::Vector2f(rand() % (Window->getSize().x / 2), rand() % (Window->getSize().y / 2)));
}