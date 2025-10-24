#ifndef FPS_H
#define FPS_H

#include <SFML/Graphics.hpp>

class Fps {
	public:

		Fps(const char* fontPath) : font(fontPath), text(font) {
			text.setCharacterSize(24);
		};

		void update(const float& deltaTime);
		void draw(sf::RenderWindow& window);

	private: 
		
		sf::Font font;
		sf::Text text;
		float timer {};
};

#endif 
