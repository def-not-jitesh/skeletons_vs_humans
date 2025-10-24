
#include "math.h"
#include <cmath>

sf::Vector2f Math::normalizeVector(const sf::Vector2f& vector) {
	sf::Vector2f normalizedVector;
	float magnitude = std::sqrt(vector.x * vector.x + vector.y * vector.y);

	normalizedVector.x = vector.x/magnitude;
	normalizedVector.y = vector.y/magnitude;

	return normalizedVector;
}

bool Math::checkCollision(sf::FloatRect rect1, sf::FloatRect rect2) {
	if (rect1.position.x + rect1.size.x > rect2.position.x
	    && rect2.position.x + rect2.size.x > rect1.position.x
	    && rect2.position.y + rect2.size.y > rect1.position.y 
	    && rect1.position.y + rect1.size.y > rect2.position.y)
		return true;

	return false;
}


