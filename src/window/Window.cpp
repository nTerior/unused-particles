#include "Window.h"

#include "display/Grid.h"
#include "hud/Hud.h"
#include "events/events.h"
#include "Settings.h"

#include "imgui.h"
#include "imgui-SFML.h"

#include "fonts/roboto.h"

#include "SFML/System.hpp"

Window::Window() : m_Window(sf::RenderWindow(sf::VideoMode(1200, 720), "unused-particles")) { 
	m_Window.setVerticalSyncEnabled(true);
	Settings::originPos = sf::Vector2f{ 1200.f, 720.f } / 2.f;
}

void Window::renderLoop(sf::RenderWindow* window)
{
	ImGui::SFML::Init(*window);

	ImGui::CreateContext();

	ImGuiIO& io = ImGui::GetIO();
	io.Fonts->Clear();
	io.Fonts->AddFontFromMemoryTTF(roboto_data, roboto_size, 20);
	io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
	ImGui::SFML::UpdateFontTexture();

	window->setActive(true);

	sf::Clock delta;
	while (window->isOpen()) {
		auto deltaTime = delta.restart();
		ImGui::SFML::Update(*window, deltaTime);
		// ImGui Stuff
		renderHud(deltaTime);

		window->clear(sf::Color::Black);
		// draw stuff
		renderGrid(window);

		ImGui::SFML::Render(*window);
		window->display();
	}
	window->setActive(false);
}

void Window::startRenderLoop()
{
	m_Window.setActive(false);

	sf::Thread thread(&Window::renderLoop, &m_Window);
	thread.launch();

	sf::Event event;
	sf::Clock clock;
	while (m_Window.isOpen()) {
		// event handling
		while (m_Window.pollEvent(event)) {
			ImGui::SFML::ProcessEvent(m_Window, event);
			if (event.type == sf::Event::Closed)
				m_Window.close();
			if (event.type == sf::Event::Resized) {
				sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
				m_Window.setView(sf::View(visibleArea));
			}
			handleEvents(event);
		}

		handleTickEvents(clock.restart());
	}

	ImGui::SFML::Shutdown();
}
