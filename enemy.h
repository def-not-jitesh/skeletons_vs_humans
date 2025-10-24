#ifndef ENEMY_H
#define ENEMY_H

#include "bullets.h"

#include <SFML/Graphics.hpp>
#include <string>

class Enemy {
	private:
		sf::Texture texture;
		sf::Sprite sprite;

		int health {100};

	public:
		sf::RectangleShape boundingRectangle;

		Enemy(const sf::Texture& texture);
		void draw(sf::RenderWindow& window);

		const sf::Sprite& getSprite() const;
		sf::Sprite& getSprite();

		const int getHealth();
		void setHealth(int health);

		friend void Bullets::update(const Player&, const Enemy&, float deltaTime, sf::Vector2i& mousePosition);
};

#endif
