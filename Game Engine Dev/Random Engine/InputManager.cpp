#include "pch.h"
#include "InputManager.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"

void InputManager::PollEvents(sf::RenderWindow* window, Player* PlayerChar, sf::Time CurrentTime, std::vector<Projectile*> &Projectiles, ResourceManager* EngineResource,
	std::vector<Obstacle*> WorldObstacles)
{
	sf::Event event;
	//Check for Window Closed
	while (window->pollEvent(event))
	{
		//Check Keyboard events
		if (event.type == sf::Event::KeyPressed) 
		{
			PlayerChar->Update(event.key.code, window, WorldObstacles);
		}

		//Check Mouse Events
		else if(event.type == sf::Event::MouseButtonPressed)
		{
			if (event.mouseButton.button == sf::Mouse::Left) 
			{
				PlayerChar->Shoot(CurrentTime, Projectiles, EngineResource, window);
			}
		}

		//Check if window closed
		else if (event.type == sf::Event::Closed)
		{
			window->close();
		}
	}
}
