#include "player.h"
#include <iostream>

Player::Player(const sf::Texture& text) : sprite(text) {
	sprite.setPosition({0.0f, 0.0f});
	sprite.setTextureRect(sf::IntRect({0, 0}, {64, 64}));

	boundingRectangle.setFillColor(sf::Color::Transparent);
	boundingRectangle.setOutlineColor(sf::Color::Red);
	boundingRectangle.setOutlineThickness(1);

	boundingRectangle.setSize(sf::Vector2f{64.0f, 64.0f});
}

void Player::update(float deltaTime) {
	
	sf::Vector2f position = sprite.getPosition();
	changeTimer += deltaTime;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
		if (changeTimer >= maxChangeTime) {

			if (spriteIndex > maxSpriteIndex)
				spriteIndex = 0;
			sprite.setTextureRect(sf::IntRect({spriteIndex * 64, 64}, {64, 64}));
			spriteIndex++;

			changeTimer = 0.0f;
		}

		if (position.x <= 0) {
			position.x = 799;
			sprite.setPosition(position);
			
		} else {	
			sprite.move(sf::Vector2f({-1.0f, 0.0f}) * speed * deltaTime);
		}

	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
		
		if (changeTimer >= maxChangeTime) {

			if (spriteIndex > maxSpriteIndex)
				spriteIndex = 0;
			sprite.setTextureRect(sf::IntRect({spriteIndex * 64, 0}, {64, 64}));
			spriteIndex++;

			changeTimer = 0.0f;
		}

		if (position.y <= 0) {
			position.y = 599;
			sprite.setPosition(position);	
		} else {
			sprite.move(sf::Vector2f({0.0f, -1.0f}) * speed * deltaTime);
		}
		
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
		if (changeTimer >= maxChangeTime) {

			if (spriteIndex > maxSpriteIndex)
				spriteIndex = 0;
			sprite.setTextureRect(sf::IntRect({spriteIndex * 64, 128}, {64, 64}));

			spriteIndex++;

			changeTimer = 0.0f;
		}

		if (position.y >= 599) {
			position.y = 1;
			sprite.setPosition(position);
		} else {
			sprite.move(sf::Vector2f({0.0f, 1.0f}) * speed * deltaTime);
		}
	}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {

		if (changeTimer >= maxChangeTime) {

			if (spriteIndex > maxSpriteIndex) 
				spriteIndex = 0;
			sprite.setTextureRect(sf::IntRect({spriteIndex * 64, 192}, {64, 64}));
			spriteIndex++;

		changeTimer = 0.0f;
	}

		if (position.x >= 799) {
			position.x = 1;
			sprite.setPosition(position);	
		} else {
			sprite.move(sf::Vector2f({1.0f, 0.0f}) * speed * deltaTime);
		}
	}

	boundingRectangle.setPosition(sprite.getPosition());

}

void Player::draw(sf::RenderWindow& window) {
	window.draw(sprite);
	window.draw(boundingRectangle);
}

const sf::Sprite& Player::getSprite() const {
	return sprite;
}

sf::Sprite& Player::getSprite() {
	return sprite;
}


