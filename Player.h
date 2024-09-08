#pragma once
#include <SFML/Graphics.hpp>
#include "Skeleton.h"
#include <iostream>

class Player
{
private:
	sf::Texture texture;
	float speed;

	//--Bullets
	std::vector<sf::RectangleShape> AllBullets;
	float bulletSpeed;
	float maxFireRate;
	float fireRateTimer;

	//--bullets

	sf::RectangleShape boundingRect;

	sf::Vector2i size; 
	
public:
	sf::Sprite sprite;

public:
	Player();
	~Player();

	void Initialize();
	void Load();
	void Update(float deltaTime, Skeleton& skeleton);
	void Draw(sf::RenderWindow& window);

};

