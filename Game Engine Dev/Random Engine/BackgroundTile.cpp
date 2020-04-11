#include "pch.h"
#include "BackgroundTile.h"

void BackgroundTile::CreateSprite(sf::RenderWindow* window, sf::Texture& TileTexture, int Xpos, int Ypos)
{
	TileSprite.setTexture(TileTexture);
	TileSprite.setOrigin(TileTexture.getSize().x / 2, TileTexture.getSize().y / 2);
	TileSprite.setPosition(sf::Vector2f(Xpos, Ypos));
	TileSprite.setScale(1, 1);
	TileSprite.setRotation(0.0f);
}

void BackgroundTile::CreateBackgroundVector(sf::RenderWindow* window, ResourceManager* EngineResource)
{
	for (int xpos = 0; xpos <= (window->getSize().x / EngineResource->GrassTexture.getSize().x + 1); xpos++)
	{
		for (int ypos = 0; ypos <= (window->getSize().y / EngineResource->GrassTexture.getSize().y + 1); ypos++)
		{
			BackgroundTile* NewTile = new BackgroundTile;
			NewTile->CreateSprite(window, EngineResource->GrassTexture, xpos * 32, ypos * 32);
			BackgroundSprites.push_back(NewTile->TileSprite);
		}
	}
}

void BackgroundTile::DrawBackground(sf::RenderWindow* Window)
{
	//Draw Background sprites
	for (int Sprite = 0; Sprite < BackgroundSprites.size(); Sprite++)
	{
		sf::Sprite CurrentTile = BackgroundSprites.at(Sprite);
		Window->draw(CurrentTile, CurrentTile.getTransform());
	}
}
