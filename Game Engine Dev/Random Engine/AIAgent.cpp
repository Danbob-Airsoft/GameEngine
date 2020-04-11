#include "pch.h"
#include "AIAgent.h"

AIAgent::AIAgent(sf::RenderWindow* Window, ResourceManager* EngineResources)
{
	srand(time(NULL));
	AgentSprite.setTexture(EngineResources->EnemyTexture);
	AgentSprite.setOrigin(AgentSprite.getTexture()->getSize().x / 2, AgentSprite.getTexture()->getSize().y / 2);
	AgentSprite.setRotation(0);
	AgentSprite.setScale(sf::Vector2f(1.0f, 1.0f));
	AgentSprite.setPosition(sf::Vector2f(rand() % (Window->getSize().x / 2), rand() % (Window->getSize().y / 2)));

	ShotSound.setBuffer(EngineResources->ShotSound);
	MoveSound.setBuffer(EngineResources->MoveSound);
	MoveSound.setVolume(20);
}

void AIAgent::PlaySound(sf::Sound& SoundToPlay)
{
	if (SoundToPlay.getStatus() != 2)
	{
		SoundToPlay.play();
	}
}

void AIAgent::Move()
{
	//Move Agent Forwards

	//Play Movement Sound
	PlaySound(MoveSound);
}

void AIAgent::Shoot()
{
	//Create Projectile

	//Add to Projectiles Vector

	//Play Sound
	PlaySound(ShotSound);
}

void AIAgent::Rotate()
{
	//Rotate Agent

}

void AIAgent::TakeDamage()
{
	std::cout << "HIT" << std::endl;
}

void AIAgent::Think()
{
	//Decide which to do
}
