#ifndef PLAYER_H
#define PLAYER_H

#include "bullets.h"

#include <SFML/Graphics.hpp>
#include <string>

class Player {
	private:
		sf::Texture texture;
		sf::Sprite sprite;
	public:
		sf::RectangleShape boundingRectangle;

		Player(const sf::Texture& texture);
		void update(float deltaTime);

		void draw(sf::RenderWindow& window);

		const sf::Sprite& getSprite() const;
		sf::Sprite& getSprite();

		friend void BulletsManager::update(const Player&, const Enemy&, float deltaTime, sf::Vector2i& mousePosition);

};

#endif  
