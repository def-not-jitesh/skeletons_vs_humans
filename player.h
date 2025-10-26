#ifndef PLAYER_H
#define PLAYER_H

#include "bullets.h"

#include <SFML/Graphics.hpp>
#include <string>

class Player {
	private:
		sf::Sprite sprite;
		float changeTimer {0.0f};
		float maxChangeTime {0.1f};
		int spriteIndex = 0;
		int maxSpriteIndex = 8;
		
		float speed = 0.5;

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
