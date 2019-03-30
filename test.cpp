#include <iostream>
#include <ostream>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/OpenGL.hpp>
#include <imgui.h>
#include <imgui-SFML.h>

using std::cout;
using std::endl;

int main() {
	sf::RenderWindow window(sf::VideoMode(640, 480), "", sf::Style::Close);
	window.setVerticalSyncEnabled(true);
	ImGui::SFML::Init(window, true);

	sf::Color bgColor;
	float color[3] = { 0.f, 0.f, 0.f };
	char windowTitle[255] = "ImGui + SFML";

	window.setTitle(windowTitle);
	window.resetGLStates();
	sf::Clock deltaClock;

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			ImGui::SFML::ProcessEvent(event);

			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		ImGui::SFML::Update(window, deltaClock.restart());

		ImGui::Begin("Sample window");

		if (ImGui::ColorEdit3("Background color", color)) {
			bgColor.r = static_cast<sf::Uint8>(color[0] * 255.f);
			bgColor.g = static_cast<sf::Uint8>(color[1] * 255.f);
			bgColor.b = static_cast<sf::Uint8>(color[2] * 255.f);
		}

		ImGui::InputText("Window title", windowTitle, 255);

		if (ImGui::Button("Update window title")) {
			window.setTitle(windowTitle);
		}
		ImGui::End();

		window.clear(bgColor);
		ImGui::SFML::Render(window);
		window.display();
	}

	ImGui::SFML::Render(window);

	return 0;
}