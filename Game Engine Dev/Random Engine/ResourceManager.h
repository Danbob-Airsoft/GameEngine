#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class ResourceManager
{
public:
	sf::Texture PlayerTexture;
	sf::Texture EnemyTexture;
	sf::Texture GrassTexture;
	sf::Texture WoodCrateTexture;
	sf::Texture MetalCrateTexture;
	sf::Texture ProjectileTexture;

	sf::SoundBuffer MoveSound;
	sf::SoundBuffer ShotSound;

	ResourceManager();
};

