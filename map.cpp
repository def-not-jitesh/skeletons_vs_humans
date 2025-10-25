#include "map.h"
#include <iostream>

void Map::load(const std::filesystem::path& tilePath, sf::Vector2i tileSize, 
				const int* tiles, int width, int height) {
	
	if (!texture.loadFromFile(tilePath)) {
		std::cout << "unable to load texture\n";
		return;
	}

	vertices.setPrimitiveType(sf::PrimitiveType::Triangles);
	vertices.resize(width * height * 6);

	for (int i = 0; i < width; ++i) {
		for (int j = 0; j < height; ++j) {
			
			int tileNumber = tiles[i + j*width];

			int tu = tileNumber % (texture.getSize().x / tileSize.x);
                	int tv = tileNumber / (texture.getSize().x / tileSize.x);

			sf::Vertex* triangles = &vertices[(i + j * width) * 6];
			
 		triangles[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
                triangles[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
                triangles[2].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);
                triangles[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);
                triangles[4].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
                triangles[5].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);

                // define the 6 matching texture coordinates
                triangles[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
                triangles[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
                triangles[2].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
                triangles[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
                triangles[4].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
                triangles[5].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);

		}
	}
}



void Map::draw(sf::RenderWindow& window) {
	window.draw(vertices, &texture);
}
