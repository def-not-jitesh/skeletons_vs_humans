#include "bullets.h"
#include "math.h"
#include "player.h"
#include "enemy.h"
#include <iostream>

void BulletsManager::update(const Player& player, const Enemy& enemy, float deltaTime, sf::Vector2i& mousePosition) {
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && fireRateTimer > maxFireRate)  {
		bulletsVec.push_back(Bullet(1.0f));
		int index = bulletsVec.size() - 1;
		bulletsVec[index].bulletShape.setPosition(player.getSprite().getPosition());

		bulletsVec[index].bulletDirection = sf::Vector2f(mousePosition) - bulletsVec[index].bulletShape.getPosition();
		
		fireRateTimer = 0;

	}
	
	if (!bulletsVec.empty()) {
		for (int i = bulletsVec.size() - 1; i >= 0; i--) {
			
			bulletsVec[i].bulletDirection = Math::normalizeVector(bulletsVec[i].bulletDirection);
			
			sf::Vector2f curPos = bulletsVec[i].bulletShape.getPosition();
			bulletsVec[i].bulletShape.setPosition(curPos + bulletsVec[i].bulletDirection * bulletsVec[i].bulletSpeed * deltaTime);

		}
	}
	
}

void BulletsManager::bulletEnemyCollision(Enemy& enemy) {

	if (enemy.getHealth() <= 0) {
		return;
	}
	
	if (bulletsVec.empty()) {
		return;
	}

	for (int i = bulletsVec.size() - 1; i >= 0; i--) {
		if (Math::checkCollision(bulletsVec[i].bulletShape.getGlobalBounds(), enemy.getSprite().getGlobalBounds())) {
			bulletsVec.erase(bulletsVec.begin() + i);
			enemy.setHealth(enemy.getHealth() - 5);

			std::cout << "enemy health: " << enemy.getHealth() << '\n';
		}
	}
}

void BulletsManager::draw(sf::RenderWindow& window) {
	for (size_t i = 0; i < bulletsVec.size(); i++) {
		window.draw(bulletsVec[i].bulletShape);
	}
}

void BulletsManager::setFireRate(float rate) {
	maxFireRate = rate;
}

float BulletsManager::getFireRateTimer() {
	return fireRateTimer;
}

void BulletsManager::setFireRateTimer(float timer) {
	fireRateTimer = timer; 
}
