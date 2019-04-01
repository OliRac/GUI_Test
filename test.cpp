#include <iostream>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/OpenGL.hpp>
#include <imgui.h>
#include <imgui-SFML.h>
#include <thread>

using namespace std;

class TextData {
public:
	static const int CHAR_SIZE = 255;
	TextData() {}
	~TextData() {}
	string windowText = "";
};

void action1(TextData * data) {
	sf::RenderWindow window(sf::VideoMode(640, 480), "", sf::Style::Close);
	window.setVerticalSyncEnabled(true);

	ImGui::SFML::Init(window);
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

		ImGui::Begin("Second Window");

		if (data->windowText != "") {
			ImGui::Text(data->windowText.c_str());
		}

		ImGui::End();

		window.clear(bgColor);
		ImGui::SFML::Render(window);
		window.display();
	}

	ImGui::SFML::Shutdown();
}

void action2(TextData * data) {
	cout << "Type something" << endl;

	 getline(cin, data->windowText);

	 cout << "Check the GUI!";
}

int main() {
	TextData * data = new TextData();

	thread first(action1, data);
	thread second(action2, data);

	first.join();
	second.join();

	delete data;

	return 0;
}