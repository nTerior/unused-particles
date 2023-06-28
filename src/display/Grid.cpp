#include "Grid.h"

#include "Settings.h"

#include <cmath>
#include <sstream>
#include <iomanip>
#include <iostream>

enum ScaleDrawPos {
	ZERO,
	TOP_LEFT,
	BOTTOM_RIGHT
};

float floorToNearest(float f, int spaces) {
	auto exp = std::pow(10, spaces);

	f *= exp;
	f = std::floorf(f);
	f /= exp;
	return f;
}

sf::Vector2f floorToNearest(sf::Vector2f f, int spaces) {
	auto exp = std::pow(10, spaces);

	f *= (float)exp;
	f.x = std::floorf(f.x);
	f.y = std::floorf(f.y);
	f /= (float)exp;
	return f;
}

sf::Vector2f gridToWindow(sf::Vector2f v, sf::Vector2f origin) {
	v.y *= -1;
	return (v * Settings::scale + origin);
}

sf::Vector2f windowToGrid(sf::Vector2f v, sf::Vector2f origin) {
	v = (v - origin) / Settings::scale;
	v.y *= -1;
	return v;
}

std::string formatFloat(float f, int prec) {
	if (prec < 0) prec = 0;
	std::stringstream stream;
	stream << std::fixed << std::setprecision(prec) << f;
	return stream.str();
}


const sf::Color color(100, 100, 100, 255);
const sf::Color colorEmphasis(200, 200, 200, 255);

void renderGrid(sf::RenderWindow* window)
{
	sf::Vector2f size = (sf::Vector2f)window->getSize();
	int spaces = Settings::gridSpaces;

	sf::Vector2f wanted { 1, 1 };
	auto mappedPos = (Settings::originPos + wanted) * Settings::scale;

	auto topLeft = windowToGrid({ 0.f, 0.f }, Settings::originPos);
	auto bottomRight = windowToGrid(size, Settings::originPos);

	auto topLeftGridNumber = floorToNearest(topLeft, spaces);
	auto bottomRightGridNumber = floorToNearest(bottomRight, spaces);
	ScaleDrawPos vertScalePos = Settings::originPos.y >= size.y - 25 ? ScaleDrawPos::BOTTOM_RIGHT : Settings::originPos.y <= 0 ? ScaleDrawPos::TOP_LEFT : ScaleDrawPos::ZERO;
	ScaleDrawPos horScalePos = Settings::originPos.x >= size.x - 25 ? ScaleDrawPos::BOTTOM_RIGHT : Settings::originPos.x <= 0 ? ScaleDrawPos::TOP_LEFT : ScaleDrawPos::ZERO;

	sf::Text num;
	num.setFont(Settings::font);
	num.setColor(sf::Color(255, 255, 255, 255));
	num.setCharacterSize(20);
	// vertical grid
	float numPosY = vertScalePos == ScaleDrawPos::ZERO ? Settings::originPos.y : vertScalePos == ScaleDrawPos::BOTTOM_RIGHT ? size.y - 25 : 0;
	for (float i = topLeftGridNumber.x - 1 / pow(10, spaces); i <= bottomRightGridNumber.x + 1 / pow(10, spaces); i += 1 / pow(10, spaces)) {
		auto x = gridToWindow({ i, 0 }, Settings::originPos).x;

		sf::Vertex line[2];
		line[0].color = i == 0 ? colorEmphasis : color;
		line[0].position = { x, 0 };

		line[1].color = i == 0 ? colorEmphasis : color;
		line[1].position = { x, size.y };
		window->draw(line, 2, sf::Lines);

		num.setPosition({ x + 5, numPosY });
		num.setString(formatFloat(i, spaces));
		window->draw(num);
	}

	// horizontal grid#
	float numPosX = horScalePos == ScaleDrawPos::ZERO ? Settings::originPos.x + 5 : horScalePos == ScaleDrawPos::BOTTOM_RIGHT ? size.x - 25 : 0;
	for (float i = bottomRightGridNumber.y - 1 / pow(10, spaces); i <= topLeftGridNumber.y + 1 / pow(10, spaces); i += 1 / pow(10, spaces)) {
		auto y = gridToWindow({ 0, i }, Settings::originPos).y;

		sf::Vertex line[2];
		line[0].color = i == 0 ? colorEmphasis : color;
		line[0].position = { 0, y };

		line[1].color = i == 0 ? colorEmphasis : color;
		line[1].position = { size.x, y };
		window->draw(line, 2, sf::Lines);

		num.setPosition({ numPosX, y });
		num.setString(formatFloat(i, spaces));
		num.setString(formatFloat(i, spaces));
		window->draw(num);
	}

	sf::CircleShape origin{5};
	origin.setPosition(Settings::originPos - sf::Vector2f{5, 5});
	window->draw(origin);
}
