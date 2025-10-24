#include "fps.h"
#include <string>

void Fps::update(const float& deltaTime) {
	timer += deltaTime;

	if (timer >= 1000.0f) {
		int fps = static_cast<int>(1000.0f / deltaTime);
		text.setString(std::string("FPS: ") + std::string(std::to_string(fps)));
		timer = 0;
	}
}

void Fps::draw(sf::RenderWindow& window) {
	window.draw(text);
}
