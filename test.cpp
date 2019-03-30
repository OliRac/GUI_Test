#include <iostream>
#include <ostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

using std::cout;
using std::endl;

int main(int argc, char * argv []) {
	sf::RenderWindow window(sf::VideoMode(200,200), "Hello world!", sf::Style::Close);
	window.setVerticalSyncEnabled(true);

	sf::CircleShape shape(100.f);

	sf::Color color = sf::Color::Green;
	shape.setFillColor(color);

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}

			if (event.type == sf::Event::MouseButtonPressed) {

				if (event.mouseButton.button == sf::Mouse::Left) {
					color = sf::Color::Blue;
					cout << "Well, it's blue now." << endl;
				}

				if (event.mouseButton.button == sf::Mouse::Right) {
					color = sf::Color::White;
					cout << "Now it's white." << endl;
				}

				if (event.mouseButton.button == sf::Mouse::Middle) {
					color = sf::Color::Black;
					cout << "Where did it go? :(" << endl;
				}
			}

			if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::Up) {
					if (color.r < 255) {
						color.r++;
					}
				}
				
				if (event.key.code == sf::Keyboard::Down) {
					if (color.r > 0) {
						color.r--;
					}
				}

				cout << "Red: " << int(color.r) << endl;
			}
		}

		shape.setFillColor(color);
		window.clear();
		window.draw(shape);
		window.display();
	}

	return 0;
}