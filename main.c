#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_error.h>
#include <stdbool.h>
#include "main.h"

SDL_Window *window = NULL;
SDL_Surface* screenSurface = NULL;
SDL_Surface* playerSurface = NULL;

void draw(SDL_Window *window) {
	screenSurface = SDL_GetWindowSurface(window);
	SDL_FillRect(screenSurface, NULL, SDL_MapRGB( screenSurface->format,0x00,0xFF,0x00 ));
	SDL_UpdateWindowSurface(window);
}

bool init() {
	
	if(SDL_Init(SDL_INIT_VIDEO) != 0) {
		printf("Could not initialize SDL: %s", SDL_GetError());
		return true;
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
		return true;
	}
	return false;
}

void mainLoop() {
	bool running = true;
	SDL_Event event;

	while(running) {

		draw(window);
		
		while(SDL_PollEvent(&event)) {
			if(event.type == SDL_QUIT) {
				running = false;
			}
		}
	}
}

void endProgram() {

	SDL_DestroyWindow(window);
	SDL_Quit();
}

int main(int argc, char* argv[]) {

	if(init()) {
		return 1;
	}	

	mainLoop();

	endProgram();
	
	
	return 0;
}


