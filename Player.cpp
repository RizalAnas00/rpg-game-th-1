#include "Player.h"
#include <iostream>

#include "Calc.h"

void Player::Initialize()
{
}

void Player::Load()
{
    if (texture.loadFromFile("GameTrial/Assets/Player/Texture/male_ss.png"))
    {
        std::cout << "Image Loaded SUCCESSFULLY" << std::endl;
        sprite.setTexture(texture);

        //X, Y, w, h
        int XIndex = 0;
        int YIndex = 0;

        sprite.setTextureRect(sf::IntRect(XIndex * 64, YIndex * 64, 64, 64));
        sprite.setScale(sf::Vector2f(2, 2));
    }
    else {
        std::cout << "Failed to Load Image" << std::endl;
    }
}

void Player::Update(Skeleton& skeleton)
{
    sf::Vector2f currPosition = sprite.getPosition();
    float speed = 0.4f; // Kecepatan default

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::RShift)) {
        speed += 0.2f; // Kecepatan saat Shift ditekan
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::PageUp))
        sprite.setPosition(currPosition + sf::Vector2f(0, -speed));

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::PageDown))
        sprite.setPosition(currPosition + sf::Vector2f(0, speed));

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Home))
        sprite.setPosition(currPosition + sf::Vector2f(-speed, 0));

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::End))
        sprite.setPosition(currPosition + sf::Vector2f(speed, 0));

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        sprite.setPosition(sf::Vector2f(540, 360));

    //BULLETS SHOOTING-----
    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
    {
        AllBullets.push_back(sf::RectangleShape(sf::Vector2f(30, 15)));

        //bullets postion
        int i = AllBullets.size() - 1;
        AllBullets[i].setPosition(sprite.getPosition());

        //Use This if u want the bullets dont follow the enemy
        //sf::Vector2f bulletDirection (move this outside loop window) = skeletonSprite.getPosition() - AllBullets[i].getPosition();
        //bulletDirection = NormalizedVector(bulletDirection);

    }

    for (size_t i = 0; i < AllBullets.size(); i++)
    {
        sf::Vector2f bulletDirection = skeleton.sprite.getPosition() - AllBullets[i].getPosition();
        bulletDirection = Calc::NormalizedVector(bulletDirection);
        AllBullets[i].setPosition(AllBullets[i].getPosition() + bulletDirection * bulletSpeed);

    }

    //BULLETS SHOOTING--------
}

void Player::Draw(sf::RenderWindow& window)
{
    window.draw(sprite);

    //draw bullets
    for (size_t i = 0; i < AllBullets.size(); i++) {
        window.draw(AllBullets[i]);
    }
    //draw bullets
}
