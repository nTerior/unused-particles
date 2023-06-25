#pragma once

#include <SFML/Graphics.hpp>

class Window {
public:
	Window();

	void startRenderLoop();

private:
	sf::RenderWindow m_Window;
	static void renderLoop(sf::RenderWindow* window);
};