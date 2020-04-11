#include "pch.h"
#include "Obstacle.h"

Obstacle::Obstacle(ResourceManager* EngineResources, sf::RenderWindow* Window)
{
	ObstacleSprite.setTexture(EngineResources->WoodCrateTexture);
	ObstacleSprite.setOrigin(sf::Vector2f(ObstacleSprite.getTexture()->getSize().x / 2, ObstacleSprite.getTexture()->getSize().y / 2));
	ObstacleSprite.setRotation(0);
	ObstacleSprite.setScale(sf::Vector2f(1.0f, 1.0f));
	ObstacleSprite.setPosition(sf::Vector2f(rand() % (Window->getSize().x / 2), rand() % (Window->getSize().y / 2)));
}