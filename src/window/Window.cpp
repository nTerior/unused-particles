#include "Window.h"

#include "display/Grid.h"

#include "imgui.h"
#include "imgui-SFML.h"

#include "fonts/roboto.h"

#include "SFML/System.hpp"

Window::Window() : m_Window(sf::RenderWindow(sf::VideoMode(1200, 720), "unused-particles")) {
	m_Window.setVerticalSyncEnabled(true);
}

void Window::renderLoop(sf::RenderWindow* window)
{
	ImGui::SFML::Init(*window);

	ImGui::CreateContext();

	ImGuiIO& io = ImGui::GetIO();
	io.Fonts->Clear();
	io.Fonts->AddFontFromMemoryCompressedTTF(roboto_compressed_data, roboto_compressed_size, 20);
	io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
	ImGui::SFML::UpdateFontTexture();

	window->setActive(true);
	sf::Clock delta;
	while (window->isOpen()) {
		ImGui::SFML::Update(*window, delta.restart());
		// ImGui Stuff
		ImGui::ShowDemoWindow();

		window->clear(sf::Color::Black);
		// draw stuff
		renderGrid(window);

		ImGui::SFML::Render(*window);
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
			ImGui::SFML::ProcessEvent(m_Window, event);
			if (event.type == sf::Event::Closed)
				m_Window.close();
			if (event.type == sf::Event::Resized) {
				sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
				m_Window.setView(sf::View(visibleArea));
			}
		}
	}

	ImGui::SFML::Shutdown();
}
