#include "enemy.h"
#include <iostream>

Enemy::Enemy(const sf::Texture& text) : texture(text), sprite(texture) {
	sprite.setPosition({400.0f, 300.0f});

	boundingRectangle.setFillColor(sf::Color::Transparent);
	boundingRectangle.setOutlineColor(sf::Color::Red);
	boundingRectangle.setOutlineThickness(1);

	boundingRectangle.setSize(sf::Vector2f{64.0f, 64.0f});

	boundingRectangle.setPosition(sprite.getPosition());
}

void Enemy::draw(sf::RenderWindow& window) {

	if (health <= 0) {
		return;
	}

	window.draw(sprite);

	window.draw(boundingRectangle);
}

const sf::Sprite& Enemy::getSprite() const {
	return sprite;
}

sf::Sprite& Enemy::getSprite() {
	return sprite;
}

const int Enemy::getHealth() {
	return health;
}

void Enemy::setHealth(int health) {
	this->health = health;
}
