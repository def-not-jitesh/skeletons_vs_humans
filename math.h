#ifndef MATH_H
#define MATH_H

#include <SFML/Graphics.hpp>

namespace Math {

	// had a math class previously, but if the class has no member variables 
	// its better to just use a namespace instead 

	sf::Vector2f normalizeVector(const sf::Vector2f& vector);
	bool checkCollision(sf::FloatRect rect1, sf::FloatRect rect2);

}

#endif
