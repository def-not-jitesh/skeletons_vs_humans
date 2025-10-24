#ifndef MAP_H
#define MAP_H

#include <SFML/Graphics.hpp>


class Map {
	private:
		sf::Texture texture {};
		sf::Sprite sprite;

	public:

		Map(sf::Texture& text);
		
		void update();

		void draw(sf::RenderWindow& window);
};	

#endif 

