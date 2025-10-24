#ifndef BULLET_H
#define BULLET_H

#include <SFML/Graphics.hpp>
#include <vector>

class Enemy;
class Player;

class Bullets {
	public:

		void update(const Player& player, const Enemy& enemy, float deltaTime, sf::Vector2i& mousePosition);
		void draw(sf::RenderWindow& window);

		void setSpeed(float speed);
		void setFireRate(float rate);
		void setFireRateTimer(float timer);
		float getFireRateTimer();

		void bulletEnemyCollision(Enemy& enemy);

	private:
		
		float maxFireRate {};
		float fireRateTimer {0.0f};
		std::vector<sf::RectangleShape> bulletsVec {};
		float bulletSpeed {};

		sf::Vector2f bulletDirection;
		// this doesnt work, will need another class to represent a bullet

};

#endif
