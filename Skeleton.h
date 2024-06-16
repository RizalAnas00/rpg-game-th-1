#pragma once
#include <SFML/Graphics.hpp>

class Skeleton
{
	private:
		sf::Texture texture;

		sf::RectangleShape boundingRect;

		sf::Vector2i size;

	public:
		sf::Sprite sprite;

	public:
		void Initialize();
		void Load();
		void Update();
		void Draw(sf::RenderWindow& window);

		Skeleton() = default;
};

