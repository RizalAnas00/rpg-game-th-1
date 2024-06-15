#include "Skeleton.h"
#include <iostream>

void Skeleton::Initialize()
{
}

void Skeleton::Load()
{
    if (texture.loadFromFile("GameTrial/Assets/Enemy/Skeleton/Texture/skeleton_spritesheet.png"))
    {
        std::cout << "ENEMY LOADED SUCCESSFULLY" << std::endl;
        sprite.setTexture(texture);

        //X, Y, w, h
        int XIndex = 0;
        int YIndex = 0;

        sprite.setTextureRect(sf::IntRect(XIndex * 64, YIndex * 64, 64, 64));
        sprite.setScale(sf::Vector2f(2, 2));

        sprite.setPosition(sf::Vector2f(500, 500));
    }
    else {
        std::cout << "Failed to Load Image" << std::endl;
    }
}

void Skeleton::Update()
{
}

void Skeleton::Draw(sf::RenderWindow& window)
{

    window.draw(sprite);
}
