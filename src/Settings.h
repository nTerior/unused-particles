#pragma once

#include "SFML/Graphics.hpp"

namespace Settings {
	extern sf::Font font;
	extern sf::Vector2f originPos;
	extern float scale; // -> scale pixels distance for 1 Real World Coordinate (Scale 1 would be 1:1 mapping
	extern float gridSpaces;
}