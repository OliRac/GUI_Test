#include <iostream>
#include <ostream>
#include <string>
#include <SDL.h>

using namespace std;

const int WIDTH = 640;
const int HEIGHT = 480;

void logSDLError(ostream &os, const string &msg) {
	os << msg << " error: " << SDL_GetError() << std::endl;
}

int main(int argc, char * argv []) {
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		cout << "SDL Initialization error" << SDL_GetError;
	}
	else {
		cout << "SDL Initialized properly";
	}


	SDL_Window *window = SDL_CreateWindow("Hello World!", 100, 100, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);

	if (!window) {
		logSDLError(cout, "Window");
	}

	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	if (!renderer) {
		logSDLError(cout, "Renderer");
	}

	SDL_Event e;
	bool quit = false;


	while (!quit) {
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_KEYDOWN) {
				quit = true;
			}
		}
	}

	return 0;
}