#ifndef MAP_H
#define MAP_H

#include <SFML/Graphics.hpp>
#include <filesystem>

class Map {
	private:
		sf::VertexArray vertices {};
		sf::Texture texture {};

	public:

		void load(const std::filesystem::path& tilePath, sf::Vector2i tileSize, 
				const int* tiles, int width, int height);

		void draw(sf::RenderWindow& window);
};	

#endif 

