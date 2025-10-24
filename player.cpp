#include "player.h"
#include <iostream>

Player::Player(const sf::Texture& text) : texture(text), sprite(texture) {
	sprite.setPosition({0.0f, 0.0f});

	boundingRectangle.setFillColor(sf::Color::Transparent);
	boundingRectangle.setOutlineColor(sf::Color::Red);
	boundingRectangle.setOutlineThickness(1);

	boundingRectangle.setSize(sf::Vector2f{64.0f, 64.0f});
}

void Player::update(float deltaTime) {

	sf::Vector2f position = sprite.getPosition();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {

		if (position.x <= 0) {
			position.x = 799;
			sprite.setPosition(position);
			
		} else {	
			sprite.move(sf::Vector2f({-1.0f, 0.0f}) * deltaTime);
		}

	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
		if (position.y <= 0) {
			position.y = 599;
			sprite.setPosition(position);	
		} else {
			sprite.move(sf::Vector2f({0.0f, -1.0f}) * deltaTime);
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
		if (position.y >= 599) {
			position.y = 1;
			sprite.setPosition(position);
		} else {
			sprite.move(sf::Vector2f({0.0f, 1.0f}) * deltaTime);
		}
	}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
		if (position.x >= 799) {
			position.x = 1;
			sprite.setPosition(position);	
		} else {
			sprite.move(sf::Vector2f({1.0f, 0.0f}) * deltaTime);
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
