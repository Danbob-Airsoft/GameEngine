#include "pch.h"
#include "Player.h"

Player::Player(ResourceManager* EngineResources, sf::RenderWindow* Window, sf::Time CurrentTime)
{
    setPosition(200.0f, 200.0f);
    PlayerSprite.setPosition(200.0f,200.0f);
    PlayerSprite.setTexture(EngineResources->PlayerTexture);
    PlayerSprite.setOrigin(sf::Vector2f(PlayerSprite.getTexture()->getSize().x / 2, PlayerSprite.getTexture()->getSize().y / 2));
    PlayerSprite.setScale(sf::Vector2f(1.0f, 1.0f));
    MoveSpeed = 2;
    RotationSpeed = 4;
    GamePaused = false;
    TimetoNextShot = CurrentTime;
    ShotCooldown = sf::seconds(2.0f);


    //Audio Setup
    ShotSound.setBuffer(EngineResources->ShotSound);
    MoveSound.setBuffer(EngineResources->MoveSound);
    MoveSound.setVolume(20);

}

void Player::Update(sf::Keyboard::Key Key, sf::RenderWindow* Window, std::vector<Obstacle*> WorldObstacles)
{
    PlayerSprite.setPosition(getPosition());
    //Check if paused
    if (GamePaused == false) 
    {
        switch (Key)
        {
            //----------------------------- Unknown Key -----------------------------
        case sf::Keyboard::Unknown:
            break;

            //------------------------------- Movement --------------------------------
        case sf::Keyboard::W:
            //Store current position
            CurrentPosition = getPosition();
            //Move Forward
            setPosition(getPosition() - (MoveSpeed * FindForwardVector()));
            PlaySound(MoveSound);

            //Check if outside barrier
            if (getPosition().x < (0 + PlayerSprite.getTexture()->getSize().x / 4) 
                || getPosition().y < (0 + PlayerSprite.getTexture()->getSize().y / 4) 
                || getPosition().x > (Window->getSize().x / 2) - (PlayerSprite.getTexture()->getSize().x / 3)
                || getPosition().y > (Window->getSize().y / 2) - (PlayerSprite.getTexture()->getSize().y / 3))
            {
                setPosition(CurrentPosition);
            }
            //Otherwise check position against world obstacles
            else 
            {
                for (int i = 0; i < WorldObstacles.size(); i++) 
                {
                    Obstacle* CurrentObstacle = WorldObstacles[i];
                    if (CurrentObstacle->ObstacleSprite.getGlobalBounds().intersects(PlayerSprite.getGlobalBounds())) 
                    {
                        setPosition(CurrentPosition);
                    }
                }
            }

            break;

        case sf::Keyboard::A:
            Rotate(-RotationSpeed);
            PlaySound(MoveSound);
            break;

        case sf::Keyboard::S:
            //Store current position
            CurrentPosition = getPosition();
            //Move Backwards
            setPosition(PlayerSprite.getPosition() + (MoveSpeed * FindForwardVector()));
            PlaySound(MoveSound);
            //Check if outside barrier
            if (getPosition().x < (0 + PlayerSprite.getTexture()->getSize().x / 2) || getPosition().y < (0 + PlayerSprite.getTexture()->getSize().y / 2) ||
                getPosition().x >(Window->getSize().x - PlayerSprite.getTexture()->getSize().x / 2)
                || getPosition().y >(Window->getSize().y - PlayerSprite.getTexture()->getSize().y / 2))
            {
                setPosition(CurrentPosition);
            }
            break;

        case sf::Keyboard::D:
            Rotate(RotationSpeed);
            PlaySound(MoveSound);
            break;

            //------------------------------- Alternate Movement -------------------------------
        case sf::Keyboard::Up:
            //Store current position
            CurrentPosition = PlayerSprite.getPosition();
            //Move Forward
            PlayerSprite.setPosition(PlayerSprite.getPosition() - (MoveSpeed * FindForwardVector()));
            PlaySound(MoveSound);
            //Check if outside barrier
            if (getPosition().x < (0 + PlayerSprite.getTexture()->getSize().x / 4)
                || getPosition().y < (0 + PlayerSprite.getTexture()->getSize().y / 4)
                || getPosition().x >(Window->getSize().x / 2) - (PlayerSprite.getTexture()->getSize().x / 3)
                || getPosition().y >(Window->getSize().y / 2) - (PlayerSprite.getTexture()->getSize().y / 3))
            {
                PlayerSprite.setPosition(CurrentPosition);
            }
            break;

        case sf::Keyboard::Down:
            //Store current position
            CurrentPosition = PlayerSprite.getPosition();
            //Move Backwards
            PlayerSprite.setPosition(PlayerSprite.getPosition() + (MoveSpeed * FindForwardVector()));
            PlaySound(MoveSound);
            //Check if outside barrier
            if (PlayerSprite.getPosition().x < 0 || PlayerSprite.getPosition().y < 0 ||
                PlayerSprite.getPosition().x > Window->getSize().x || PlayerSprite.getPosition().y > Window->getSize().y)
            {
                PlayerSprite.setPosition(CurrentPosition);
            }
            break;

        case sf::Keyboard::Left:
            Rotate(-RotationSpeed);
            PlaySound(MoveSound);
            break;

        case sf::Keyboard::Right:
            Rotate(RotationSpeed);
            PlaySound(MoveSound);
            break;

        }
    }

    //------------------------Game Paused --------------------------------
    //Must be checked outside switchcase as it can be done when game is paused
    if (Key == sf::Keyboard::P) 
    {
        if (GamePaused == false) 
        {
            std::cout << "Game Paused" << std::endl;
            GamePaused = true;
        }
        else
        {
            std::cout << "Game Resumed" << std::endl;
            GamePaused = false;
        }
    }
}

sf::Vector2f Player::FindForwardVector()
{
    sf::Vector2f Forward;

    Forward.x = sin(PlayerSprite.getRotation() * M_PI /180);
    Forward.y = -cos(PlayerSprite.getRotation() * M_PI / 180);

    return Forward;
}

void Player::Shoot(sf::Time CurrentTime, std::vector<Projectile*> &Projectiles, ResourceManager* EngineResource, sf::RenderWindow* Window)
{
    if (CurrentTime >= TimetoNextShot) 
    {
        sf::Vector2f CannonLocation = (getPosition() + FindForwardVector());

        Projectile* NewProjectile = new Projectile(EngineResource, CannonLocation);
        //Set Projectile forward vector
        NewProjectile->ForwardVector = FindForwardVector();
        //Add to Projectiles Vector to be drawn each frame
        Projectiles.push_back(NewProjectile);
        //Increase time to next shot
        TimetoNextShot = CurrentTime + ShotCooldown;
        //Play Sound
        PlaySound(ShotSound);
    }
}


void Player::Rotate(float Rotation)
{
    PlayerSprite.rotate(Rotation);
}

void Player::PlaySound(sf::Sound &SoundToPlay)
{
    if (SoundToPlay.getStatus() != 2)
    {
        SoundToPlay.play();
    }
}



