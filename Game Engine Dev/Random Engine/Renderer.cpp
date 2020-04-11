#include "pch.h"
#include "Renderer.h"

sf::RenderWindow* Renderer::CreateWindow(BackgroundTile* Background, ResourceManager* EngineResource)
{
	sf::RenderWindow* NewWindow = new sf::RenderWindow(sf::VideoMode(1900, 1000), "The Random Engine");
	Background->CreateBackgroundVector(NewWindow, EngineResource);
	return NewWindow;
}

void Renderer::UpdateWindow(sf::RenderWindow* window, InputManager* EngineInput, Player* PlayerChar, ResourceManager* EngineResource, BackgroundTile* Background, sf::Time CurrentTime)
{
	//-------------------------------------- Clear the window -------------------------------
	window->clear();

	//-------------------------------------- Call Input Check -------------------------------
	EngineInput->PollEvents(window, PlayerChar, CurrentTime, Projectiles ,EngineResource, WorldObstacles);

	//-------------------------------------- Draw Background --------------------------------
	Background->DrawBackground(window);

	//-------------------------------------- Call Player Draw -----------------------------
	window->draw(PlayerChar->PlayerSprite, PlayerChar->getTransform());

	//-------------------------------------- Call Renderables Updates ----------------------

	//For each projectile in Projectiles vector
	for (int i = 0; i < Projectiles.size(); i++)
	{
		//Get Current Shell
		Projectile* Shell = Projectiles[i];
		if (!PlayerChar->GamePaused)
		{
			//Update Shell
			Shell->Think(window, AIAgents, WorldObstacles);
		}
		if (Shell->NeedsDestroying)
		{
			//Call Deconstructor
			Shell->~Projectile();
			//Remove from Vector
			Projectiles.erase(Projectiles.begin() + i);
			//Set Shell to Null

		}
		else 
		{
			//Draw Shell
			window->draw(Shell->ProjectileSprite, Shell->ProjectileSprite.getTransform());
		}
	}


	//For each AI in renderables
	for (int i = 0; i < AIAgents.size(); i++)
	{
		//Get Current AI
		AIAgent* CurrentAgent = AIAgents[i];

		if (!PlayerChar->GamePaused)
		{
			//Update Agent
			CurrentAgent->Think();
		}

		//Draw Agent
		window->draw(CurrentAgent->AgentSprite, CurrentAgent->AgentSprite.getTransform());

	}

	//---------------------------------------- Draw Obstacles -----------------------------------
	for (int i = 0; i < WorldObstacles.size(); i++) 
	{
		Obstacle* CurrentObstacle = WorldObstacles[i];
		window->draw(CurrentObstacle->ObstacleSprite, CurrentObstacle->ObstacleSprite.getTransform());
	}
}

void Renderer::DrawWindow(sf::RenderWindow* window)
{
	//Display new Window
	window->display();
}
