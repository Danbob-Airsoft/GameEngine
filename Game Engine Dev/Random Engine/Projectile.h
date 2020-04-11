#pragma once
#include <SFML/Graphics.hpp>
#include "ResourceManager.h"
#include "AIAgent.h"
#include "Obstacle.h"

class Projectile
{
public:
	sf::Sprite ProjectileSprite;

	Projectile(ResourceManager* EngineResource, sf::Vector2f SpawnPoint);

	~Projectile();

	void Think(sf::RenderWindow* Window, std::vector<AIAgent*> AIAgents, std::vector<Obstacle*> WorldObstacles);

	sf::Vector2f ForwardVector;
	bool NeedsDestroying;
};

