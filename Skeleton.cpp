#include "Skeleton.h"
#include <iostream>

void Skeleton::Initialize()
{
    boundingRect.setFillColor(sf::Color::Transparent);
    boundingRect.setOutlineColor(sf::Color::Yellow);
    boundingRect.setOutlineThickness(1);

    size = sf::Vector2i(64, 64);
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
        sprite.setPosition(sf::Vector2f(500, 500));

        sprite.setScale(sf::Vector2f(2, 2));

        boundingRect.setSize(sf::Vector2f(size.x * sprite.getScale().x, size.y * sprite.getScale().y));
    }
    else {
        std::cout << "Failed to Load Image" << std::endl;
    }
}

void Skeleton::Update()
{
    boundingRect.setPosition(sprite.getPosition());

}

void Skeleton::Draw(sf::RenderWindow& window)
{
    window.draw(boundingRect);
    window.draw(sprite);
}
