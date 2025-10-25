#include "bullets.h"
#include "enemy.h"
#include "player.h"
#include "math.h"
#include "fps.h"
#include "map.h"

#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>
#include <string>
#include <iostream>

int main() {
	
	sf::RenderWindow window(sf::VideoMode({800, 640}), "My Game");
	window.setFramerateLimit(60);
	
	sf::Texture playerTexture;
	if (!playerTexture.loadFromFile("/home/A/docs/game_dev/textures/lpc_entry/png/walkcycle/BODY_skeleton.png", false, sf::IntRect({0, 128}, {64, 64}))) {
		std::cout << "unable to load player texture\n";
	} else {
		std::cout << "player texture loaded\n";
	}

	sf::Texture enemyTexture;
	if (!enemyTexture.loadFromFile("/home/A/docs/game_dev/textures/lpc_entry/png/walkcycle/BODY_male.png", false, sf::IntRect({0, 128}, {64, 64}))) {
		std::cout << "unable to load enemy texture\n";
	} else {
		std::cout << "enemy texture loaded\n";
	}

	
	Player player(playerTexture);
	Enemy enemy(enemyTexture);
	Map map;

	Bullets bulletObj;
	bulletObj.setSpeed(1.0f);
	bulletObj.setFireRate(200.0f);

	sf::Clock clock;

	Fps fpshow("/home/A/docs/game_dev/skeletons_vs_humans/assets/fonts/EvilEmpire-lx5R0.ttf"); 

	constexpr std::array tiles = {
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,
    0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,
    0,1,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,0,1,0,
    0,1,0,2,2,0,3,3,0,0,0,0,0,0,0,3,3,0,2,2,0,0,0,1,0,
    0,1,0,0,0,0,3,3,0,0,0,0,0,0,0,3,3,0,0,0,0,0,0,1,0,
    0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,
    0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,
    0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,
    0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,
    0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,
    0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,
    0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,
    0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,
    0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,
    0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,
    0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,
    0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
	};
	
	map.load("/home/A/docs/game_dev/skeletons_vs_humans/assets/tiles/tiles.png", {32, 32}, tiles.data(), 25, 20);

	while (window.isOpen()) {	

		sf::Time elapsedTime = clock.restart(); // delta time for this frame, basically how long it took to run this frame(basically the while loop)
		float deltaTime = elapsedTime.asMilliseconds();
		
		while (auto event = window.pollEvent()) {
			if (event->is<sf::Event::Closed>()) {
				window.close();
			}
		}
		
		fpshow.update(deltaTime);
		player.update(deltaTime);
		
		bulletObj.setFireRateTimer(bulletObj.getFireRateTimer() + deltaTime);

		sf::Vector2i mousePos = sf::Mouse::getPosition(window); // should get mousePosition only once every frame 

		bulletObj.update(player, enemy, deltaTime, mousePos);

		bulletObj.bulletEnemyCollision(enemy);

		if (enemy.getHealth() > 9) {
			if (Math::checkCollision(player.getSprite().getGlobalBounds(), enemy.getSprite().getGlobalBounds())) 
				std::cout << "collision" << '\n';
		}

		window.clear(sf::Color::Black);

		map.draw(window);

		player.draw(window);
		
		enemy.draw(window);

		fpshow.draw(window);

		bulletObj.draw(window);
		
		window.display();
	}	

	return 0;
}
