#pragma once

#include "SFML/Graphics.hpp"

void handleEvents(sf::Event event, sf::RenderWindow *window);
void handleTickEvents(sf::Time delta);