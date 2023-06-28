#include "Hud.h"

#include "imgui.h"

void renderHud(sf::Time deltaTime) {
	ImGui::DockSpaceOverViewport(NULL, ImGuiDockNodeFlags_PassthruCentralNode);

	ImGui::Begin("Setings");
	ImGui::Text("FpS: %.0f", 1 / deltaTime.asSeconds());
	ImGui::End();
}

