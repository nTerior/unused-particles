#include "events.h"

#include "Settings.h"
#include <iostream>

bool isUp = false;
bool isDown = false;
bool isLeft = false;
bool isRight = false;

bool isMiddleMouseDown = false;
sf::Event::MouseMoveEvent prevMousePos;

void handleEvents(sf::Event event, sf::RenderWindow *window) {
	switch (event.type) {
	case sf::Event::KeyPressed:
		if (event.key.code == sf::Keyboard::Up) isUp = true;
		else if (event.key.code == sf::Keyboard::Down) isDown = true;
		if (event.key.code == sf::Keyboard::Left) isLeft = true;
		else if (event.key.code == sf::Keyboard::Right) isRight = true;
		break;
	case sf::Event::KeyReleased:
		if (event.key.code == sf::Keyboard::Up) isUp = false;
		else if (event.key.code == sf::Keyboard::Down) isDown = false;
		if (event.key.code == sf::Keyboard::Left) isLeft = false;
		else if (event.key.code == sf::Keyboard::Right) isRight = false;
		break;
	case sf::Event::MouseButtonPressed:
		if (event.mouseButton.button == sf::Mouse::Button::Middle) isMiddleMouseDown = true;
		break;
	case sf::Event::MouseButtonReleased:
		if (event.mouseButton.button == sf::Mouse::Button::Middle) isMiddleMouseDown = false;
		break;
	case sf::Event::MouseMoved:
		if (!isMiddleMouseDown) {
			prevMousePos = event.mouseMove;
			break;
		}
		Settings::originPos += sf::Vector2f{(float)(event.mouseMove.x - prevMousePos.x), (float)(event.mouseMove.y - prevMousePos.y)};
		prevMousePos = event.mouseMove;
		break;
	case sf::Event::MouseWheelScrolled:
		if (event.mouseWheelScroll.wheel != sf::Mouse::VerticalWheel) break;
		Settings::scale += 0.1 * Settings::scale * event.mouseWheelScroll.delta;
		break;
	}
}

void handleTickEvents(sf::Time delta) {
	float speed = 300 * delta.asSeconds(); // pixels per second

	if (isUp) {
		Settings::originPos.y -= speed;
	}
	else if (isDown) {
		Settings::originPos.y += speed;
	}

	if (isLeft) {
		Settings::originPos.x -= speed;
	}
	else if (isRight) {
		Settings::originPos.x += speed;
	}
}
