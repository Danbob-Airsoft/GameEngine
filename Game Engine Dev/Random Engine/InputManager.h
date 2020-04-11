#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Projectile.h"
#include "Obstacle.h"

const class InputManager
{
public:
	void PollEvents(sf::RenderWindow* window, Player* PlayerChar, sf::Time CurrentTime, std::vector<Projectile*> &Projectiles, ResourceManager* EngineResource,
		std::vector<Obstacle*> WorldObstacles);
private:
};

