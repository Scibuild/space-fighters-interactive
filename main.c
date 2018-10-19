#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_error.h>
#include <stdbool.h>
#include "main.h"

void draw() {

}


int main(int argc, char* argv[]) {
	bool running = true;
	SDL_Event event;
	SDL_Window *window;

	if(SDL_Init(SDL_INIT_VIDEO) != 0) {
		printf("Could not initialize SDL: %s", SDL_GetError());
		return 1;
	}

	window = SDL_CreateWindow(
			"Space Fighters Interactive",
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			640,
			480,
			SDL_WINDOW_OPENGL
			);

	if(window == NULL) {
		printf("Could not initialize window: %s", SDL_GetError());
		return 1;
	}
	
	
	while(running) {

		draw();
		
		while(SDL_PollEvent(&event)) {
			if(event.type == SDL_QUIT) {
				running = false;
			}
		}
	}

	SDL_DestroyWindow(window);

	SDL_Quit();
	
	printf("Hello, world\n");
	return 0;
}


