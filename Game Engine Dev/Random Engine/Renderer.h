#pragma once
#include <SFML/Graphics.hpp>
#include "InputManager.h"
#include "Player.h"
#include "ResourceManager.h"
#include <iostream>
#include "Backgroundtile.h"
#include <vector>
#include "Projectile.h"
#include "AIAgent.h"
#include <SFML/System/Time.hpp>
#include "Obstacle.h"

class Renderer
{
public:
	sf::RenderWindow* CreateWindow(BackgroundTile* Background, ResourceManager* EngineResource);
	void UpdateWindow(sf::RenderWindow* window, InputManager* EngineInput, Player* PlayerChar, ResourceManager* EngineResource, BackgroundTile* Background, sf::Time CurrentTime);
	void DrawWindow(sf::RenderWindow* window);

	std::vector<Projectile*> Projectiles;
	std::vector<AIAgent*> AIAgents;
	std::vector<Obstacle*> WorldObstacles;

	sf::RenderWindow* window;
};

