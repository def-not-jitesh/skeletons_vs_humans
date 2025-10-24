#include "bullets.h"
#include "math.h"
#include "player.h"
#include "enemy.h"
#include <iostream>

void Bullets::update(const Player& player, const Enemy& enemy, float deltaTime, sf::Vector2i& mousePosition) {
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && fireRateTimer > maxFireRate)  {
		bulletsVec.push_back(sf::RectangleShape(sf::Vector2f({10.0f, 10.0f})));
		int index = bulletsVec.size() - 1;
		bulletsVec[index].setPosition(player.getSprite().getPosition());

		bulletDirection = sf::Vector2f(mousePosition) - bulletsVec[index].getPosition();
		
		fireRateTimer = 0;

	}
	
	if (!bulletsVec.empty()) {
		for (int i = bulletsVec.size() - 1; i >= 0; i--) {
			
			bulletDirection = Math::normalizeVector(bulletDirection);
			
			sf::Vector2f curPos = bulletsVec[i].getPosition();
			bulletsVec[i].setPosition(curPos + bulletDirection * bulletSpeed * deltaTime);

		}
	}
	
}

void Bullets::bulletEnemyCollision(Enemy& enemy) {

	if (enemy.getHealth() <= 0) {
		return;
	}
	
	if (bulletsVec.empty()) {
		return;
	}

	for (int i = bulletsVec.size() - 1; i >= 0; i--) {
		if (Math::checkCollision(bulletsVec[i].getGlobalBounds(), enemy.getSprite().getGlobalBounds())) {
			bulletsVec.erase(bulletsVec.begin() + i);
			enemy.setHealth(enemy.getHealth() - 5);

			std::cout << "enemy health: " << enemy.getHealth() << '\n';
		}
	}
}


void Bullets::setSpeed(float speed) {
	bulletSpeed = speed;
}

void Bullets::draw(sf::RenderWindow& window) {
	for (size_t i = 0; i < bulletsVec.size(); i++) {
		window.draw(bulletsVec[i]);
	}
}

void Bullets::setFireRate(float rate) {
	maxFireRate = rate;
}

float Bullets::getFireRateTimer() {
	return fireRateTimer;
}

void Bullets::setFireRateTimer(float timer) {
	fireRateTimer = timer; 
}
