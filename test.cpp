#include <iostream>
#include "SDL.h"

using namespace std;

int main(int argc, char * argv []) {
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		cout << "SDL Initialization error" << SDL_GetError;
	}
	else {
		cout << "SDL Initialized properly";
	}

	return 0;
}