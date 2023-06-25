#include "Window.h"

#include "display/Grid.h"

Window::Window() : m_Window(sf::RenderWindow(sf::VideoMode(1200, 720), "unused-particles")) {
	m_Window.setVerticalSyncEnabled(true);
}

void Window::renderLoop(sf::RenderWindow* window)
{
	window->setActive(true);
	while (window->isOpen()) {
		window->clear(sf::Color::Black);
		// draw stuff
		renderGrid(window);
		window->display();
	}
}

void Window::startRenderLoop()
{
	m_Window.setActive(false);

	sf::Thread thread(&Window::renderLoop, &m_Window);
	thread.launch();

	sf::Event event;
	while (m_Window.isOpen()) {
		// event handling
		while (m_Window.pollEvent(event)) {
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				m_Window.close();
		}
	}
}
