#pragma once
#define _USE_MATH_DEFINES
#include "SFML/Graphics.hpp"
#include <math.h>
#include <cmath>
#include "ResourceManager.h"
#include <SFML/System/Time.hpp>
#include "Projectile.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include "Obstacle.h"

class Player: public sf::Transformable
{
public:
	sf::Sprite PlayerSprite;
	
	float MoveSpeed;
	float RotationSpeed;

	bool GamePaused;

	Player(ResourceManager* EngineResources, sf::RenderWindow* Window, sf::Time CurrentTime);
	void Update(sf::Keyboard::Key Key, sf::RenderWindow* Window, std::vector<Obstacle*> WorldObstacles);
	void Shoot(sf::Time CurrentTime, std::vector<Projectile*> &Projectiles, ResourceManager* EngineResource, sf::RenderWindow* Window);
	void Rotate(float Rotation);
	void PlaySound(sf::Sound &SoundToPlay);

	sf::Time TimetoNextShot;
	sf::Time ShotCooldown;

	sf::Sound ShotSound;
	sf::Sound MoveSound;

	sf::Vector2f CurrentPosition;


private:
	sf::Vector2f FindForwardVector();
};

