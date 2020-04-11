// Random Engine.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include "pch.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Renderer.h"
#include "InputManager.h"
#include "Player.h"
#include "ResourceManager.h"
#include "AIAgent.h"
#include <chrono>
#include <SFML/System/Time.hpp>
#include "Obstacle.h"

int main()
{
	//-------------------------------------- Start Time ------------------------------
	sf::Clock ProgramClock;
	sf::Time CurrentTime;

	//---------------------------------------Manager setups----------------------------
	Renderer* EngineRenderer = new Renderer;
	BackgroundTile* Background = new BackgroundTile();
	InputManager* EngineInput = new InputManager;
	ResourceManager* EngineResources = new ResourceManager;

	//---------------------------------------Window Creation------------------------------
	sf::RenderWindow* window = EngineRenderer->CreateWindow(Background, EngineResources);

	//------------------------------------- Other Setup ----------------------------------
	Player* PlayerCharacter = new Player(EngineResources, window, CurrentTime);

	//------------------------------------- Create AI -----------------------------------
	for (int i = 0; i <= 5; i++) 
	{
		AIAgent* CurrentAgent = new AIAgent(window, EngineResources);
		EngineRenderer->AIAgents.push_back(CurrentAgent);
	}

	//------------------------------------ Create Obstacles -----------------------------
	for (int i = 0; i < 5; i++)
	{
		Obstacle* CurrentObstacle = new Obstacle(EngineResources, window);
		EngineRenderer->WorldObstacles.push_back(CurrentObstacle);
	}

	//---------------------------------Main Game Loop-------------------------------------
	while (true)
	{
		//Update Time
		CurrentTime = ProgramClock.getElapsedTime();

		//Update Window
		EngineRenderer->UpdateWindow(window, EngineInput, PlayerCharacter, EngineResources, Background, CurrentTime);

		//Display new Window
		EngineRenderer->DrawWindow(window);
	}
	return 0;
}
