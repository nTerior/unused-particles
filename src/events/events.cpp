#include "events.h"

#include "Settings.h"

bool isUp = false;
bool isDown = false;
bool isLeft = false;
bool isRight = false;

void handleEvents(sf::Event event) {
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
	}
}

void handleTickEvents(sf::Time delta) {
	float speed = 200 * delta.asSeconds(); // pixels per second

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
