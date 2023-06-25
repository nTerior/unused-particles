#include "Grid.h"

const int gridSpacing = 100;

void renderGrid(sf::RenderWindow* window)
{
	sf::Vector2u size = window->getSize();
	
	int centerX = size.x / 2;
	int centerY = size.y / 2;

	for (int i = 0; i < centerX / gridSpacing + 1; i++) {
		sf::VertexArray vLineR(sf::LinesStrip, 2);
		sf::VertexArray vLineL(sf::LinesStrip, 2);
		vLineR[0].position = sf::Vector2f(centerX + gridSpacing * i, 0);
		vLineR[1].position = sf::Vector2f(centerX + gridSpacing * i, size.y);
		vLineL[0].position = sf::Vector2f(centerX - gridSpacing * i, 0);
		vLineL[1].position = sf::Vector2f(centerX - gridSpacing * i, size.y);

		vLineR[0].color = sf::Color(100, 100, 100);
		vLineR[1].color = sf::Color(100, 100, 100);
		vLineL[0].color = sf::Color(100, 100, 100);
		vLineL[1].color = sf::Color(100, 100, 100);
		window->draw(vLineR);
		window->draw(vLineL);
	}

	for (int i = 0; i < centerY / gridSpacing + 1; i++) {
		sf::VertexArray hLineR(sf::LinesStrip, 2);
		sf::VertexArray hLineL(sf::LinesStrip, 2);
		hLineR[0].position = sf::Vector2f(0, centerY + gridSpacing * i);
		hLineR[1].position = sf::Vector2f(size.x, centerY + gridSpacing * i);
		hLineL[0].position = sf::Vector2f(0, centerY - gridSpacing * i);
		hLineL[1].position = sf::Vector2f(size.x, centerY - gridSpacing * i);

		hLineR[0].color = sf::Color(100, 100, 100);
		hLineR[1].color = sf::Color(100, 100, 100);
		hLineL[0].color = sf::Color(100, 100, 100);
		hLineL[1].color = sf::Color(100, 100, 100);
		window->draw(hLineR);
		window->draw(hLineL);
	}
}
