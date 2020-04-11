#include "pch.h"
#include "Projectile.h"

Projectile::Projectile(ResourceManager* EngineResource, sf::Vector2f SpawnPoint)
{
	ProjectileSprite.setTexture(EngineResource->ProjectileTexture);
	ProjectileSprite.setOrigin(sf::Vector2f(ProjectileSprite.getTexture()->getSize().x / 2, ProjectileSprite.getTexture()->getSize().y / 2));
	ProjectileSprite.setPosition(sf::Vector2f(SpawnPoint));
	ProjectileSprite.setScale(sf::Vector2f(1.0f, 1.0f));
	NeedsDestroying = false;
}

Projectile::~Projectile()
{
	NeedsDestroying = NULL;


}

void Projectile::Think(sf::RenderWindow* Window, std::vector<AIAgent*> AIAgents, std::vector<Obstacle*> WorldObstacles)
{
	//Move Forward
	ProjectileSprite.setPosition(ProjectileSprite.getPosition() - (ForwardVector * 0.5f));

	//Check if overlapping with AI
	for(int i = 0; i < AIAgents.size(); i++)
	{
		AIAgent* Agent = AIAgents[i];
		if (ProjectileSprite.getGlobalBounds().intersects(Agent->AgentSprite.getGlobalBounds())) 
		{
			//Damage Agent
			Agent->TakeDamage();

			//Set Shell to be destroyed
			NeedsDestroying = true;

			//Stop Looping
			break;
		}
	}

	//Check for collisions with world obstacles
	for (int i = 0; i < WorldObstacles.size(); i++) 
	{
		Obstacle* CurrentObstacle = WorldObstacles[i];
		if (ProjectileSprite.getGlobalBounds().intersects(CurrentObstacle->ObstacleSprite.getGlobalBounds())) 
		{
			NeedsDestroying = true;
			break;
		}
	}

	//Check if outside boundaries
	if (ProjectileSprite.getPosition().x < 0 || ProjectileSprite.getPosition().y < 0 || 
		ProjectileSprite.getPosition().x > Window->getSize().x || ProjectileSprite.getPosition().y > Window->getSize().y)
	{
		//If so, Set to be destroyed
		NeedsDestroying = true;
	}
}
