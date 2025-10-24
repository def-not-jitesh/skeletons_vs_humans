#include "map.h"

Map::Map(sf::Texture& text) : texture(text), sprite(texture) {
	
	sprite.setPosition(sf::Vector2f({100.0f, 100.0f}));
}

void Map::draw(sf::RenderWindow& window) {
	window.draw(sprite);
}
