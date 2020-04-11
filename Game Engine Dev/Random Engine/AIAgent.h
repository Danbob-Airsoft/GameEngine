#pragma once
#include <SFML/Graphics.hpp>
#include "ResourceManager.h"
#include <random>
#include <iostream>
#include <SFML/System/Time.hpp>
#include <SFML/Audio.hpp>

class AIAgent
{
public:
	sf::Sprite AgentSprite;

	AIAgent(sf::RenderWindow* Window, ResourceManager* EngineResources);

	sf::Time TimetoNextShot;
	sf::Time ShotCooldown;

	sf::Sound ShotSound;
	sf::Sound MoveSound;

	void Think();
	void PlaySound(sf::Sound& SoundToPlay);
	void Move();
	void Shoot();
	void Rotate();
	void TakeDamage();
};

