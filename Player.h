#pragma once
#include <SFML/Graphics.hpp>
#include "Skeleton.h"
#include <iostream>

class Player
{
private:
	sf::Texture texture;
	//--Bullets
	std::vector<sf::RectangleShape> AllBullets;
	float bulletSpeed = 0.95f;
	//--bullets

	sf::RectangleShape boundingRect;

	sf::Vector2i size; 
	
public:
	sf::Sprite sprite;

public:
	void Initialize();
	void Load();
	void Update(Skeleton& skeleton);
	void Draw(sf::RenderWindow& window);

	Player() = default;
};

