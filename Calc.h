#pragma once
#include <SFML/Graphics.hpp>

class Calc
{
public:
	static sf::Vector2f NormalizedVector(sf::Vector2f vector);
	static bool CheckIsCollision(sf::FloatRect rect1, sf::FloatRect rect2);
};

