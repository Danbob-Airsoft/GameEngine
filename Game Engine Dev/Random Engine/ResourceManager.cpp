#include "pch.h"
#include "ResourceManager.h"

ResourceManager::ResourceManager()
{
    if (!PlayerTexture.loadFromFile("Sprites\\PlayerSprite.png"))
    {
        std::cout << "Failed to Load Player Texture" << std::endl;
    }
    if (!EnemyTexture.loadFromFile("Sprites\\EnemySprite.png"))
    {
        std::cout << "Failed to Load Enemy Texture" << std::endl;
    }
    if (!GrassTexture.loadFromFile("Sprites\\GrassTile.png"))
    {
        std::cout << "Failed to Load Grass Texture" << std::endl;
    }
    if (!WoodCrateTexture.loadFromFile("Sprites\\WoodCrate.png"))
    {
        std::cout << "Failed to Load Wooden Crate Texture" << std::endl;
    }
    if (!MetalCrateTexture.loadFromFile("Sprites\\MetalCrate.png"))
    {
        std::cout << "Failed to Load Metal Crate Texture" << std::endl;
    }
    if (!ProjectileTexture.loadFromFile("Sprites\\Projectile.png"))
    {
        std::cout << "Failed to Load Projectile Texture" << std::endl;
    }

    if (!ShotSound.loadFromFile("Audio\\ShotSound.wav")) 
    {
        std::cout << "Failed to load Shot Sound" << std::endl;
    }
    if (!MoveSound.loadFromFile("Audio\\MovementSound.wav"))
    {
        std::cout << "Failed to load Movement Sound" << std::endl;
    }
}
