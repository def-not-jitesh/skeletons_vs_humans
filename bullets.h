#ifndef BULLET_H
#define BULLET_H

#include <SFML/Graphics.hpp>
#include <vector>

struct Bullet {
	
	Bullet(float speed) {};
	
	float bulletSpeed {1.0f};
	sf::Vector2f bulletDirection {};
	sf::RectangleShape bulletShape {sf::Vector2f({10.0f, 10.f})};
};

class Enemy;
class Player;

class BulletsManager {
	public:

		void update(const Player& player, const Enemy& enemy, float deltaTime, sf::Vector2i& mousePosition);
		void draw(sf::RenderWindow& window);

		void setFireRate(float rate);
		void setFireRateTimer(float timer);
		float getFireRateTimer();

		void bulletEnemyCollision(Enemy& enemy);

	private:
		
		float maxFireRate {};
		float fireRateTimer {0.0f};
		std::vector<Bullet> bulletsVec {};

};

#endif
