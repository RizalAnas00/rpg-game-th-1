#include "Player.h"
#include <iostream>

#include "Calc.h"

Player::Player() :
    bulletSpeed(0.5f), speed(0.2f), maxFireRate(150.0f), fireRateTimer(0.0f)
{}

Player::~Player() {

}

void Player::Initialize()
{
    boundingRect.setFillColor(sf::Color::Transparent);
    boundingRect.setOutlineColor(sf::Color::White);
    boundingRect.setOutlineThickness(1);

    size = sf::Vector2i(64, 64);

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
        sprite.setPosition(sf::Vector2f(0, 0));

        //boundRect
        sprite.setScale(sf::Vector2f(2, 2));

        boundingRect.setSize(sf::Vector2f(size.x * sprite.getScale().x, size.y * sprite.getScale().y));
    }
    else {
        std::cout << "Failed to Load Image" << std::endl;
    }
}

void Player::Update(float deltaTime, Skeleton& skeleton)
{
    sf::Vector2f currPosition = sprite.getPosition();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::PageUp))
        sprite.setPosition(currPosition + sf::Vector2f(0, -1) * speed * deltaTime);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::PageDown))
        sprite.setPosition(currPosition + sf::Vector2f(0, 1) * speed * deltaTime);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Home))
        sprite.setPosition(currPosition + sf::Vector2f(-1, 0) * speed * deltaTime);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::End))
        sprite.setPosition(currPosition + sf::Vector2f(1, 0) * speed * deltaTime);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        sprite.setPosition(sf::Vector2f(540, 360));

    //------------------------------------ BULLETS SHOOTING -----------------------------------------
    fireRateTimer += deltaTime;
    std::cout << fireRateTimer << std::endl;

    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && fireRateTimer >= maxFireRate)
    {
        AllBullets.push_back(sf::RectangleShape(sf::Vector2f(30, 15)));

        //bullets postion
        int i = AllBullets.size() - 1;
        AllBullets[i].setPosition(sprite.getPosition());

        fireRateTimer = 0;

        //Use This if u want the bullets dont follow the enemy
        //sf::Vector2f bulletDirection (move this outside loop window) = skeletonSprite.getPosition() - AllBullets[i].getPosition();
        //bulletDirection = NormalizedVector(bulletDirection);

    }

    for (size_t i = 0; i < AllBullets.size(); i++)
    {
        sf::Vector2f bulletDirection = skeleton.sprite.getPosition() - AllBullets[i].getPosition();
        bulletDirection = Calc::NormalizedVector(bulletDirection);
        AllBullets[i].setFillColor(sf::Color::Yellow);
        AllBullets[i].setPosition(AllBullets[i].getPosition() + bulletDirection * bulletSpeed * deltaTime);

        if (Calc::CheckIsCollision(AllBullets[i].getGlobalBounds(), skeleton.sprite.getGlobalBounds()))
        {
            AllBullets.erase(AllBullets.begin() + i);
            std::cout << "COLLISION DETECTED" << std::endl;
        }

    }

    //rectangle--
    boundingRect.setPosition(sprite.getPosition());

    //BULLETS SHOOTING--------
}

void Player::Draw(sf::RenderWindow& window)
{
    window.draw(sprite);
    window.draw(boundingRect);

    //draw bullets
    for (size_t i = 0; i < AllBullets.size(); i++) {
        window.draw(AllBullets[i]);
    }
    //draw bullets
}
