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
	SDL_FillRect(screenSurface, NULL, SDL_MapRGB( screenSurface->format,0x00,0x00,0x00 ));
	SDL_BlitSurface(playerSurface, NULL, screenSurface, NULL);
	SDL_UpdateWindowSurface(window);
}

bool init() {
	
	if(SDL_Init(SDL_INIT_VIDEO) != 0) {
		printf("Could not initialize SDL: %s", SDL_GetError());
		return false;
	}

	window = SDL_CreateWindow(
			"Space Fighters Interactive",
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			640,
			480,
			SDL_WINDOW_SHOWN
			);

	if(window == NULL) {
		printf("Could not initialize window: %s", SDL_GetError());
		return false;
	}
	return true;
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

	SDL_FreeSurface(playerSurface);
	playerSurface = NULL;
	SDL_DestroyWindow(window);
	window = NULL;
	SDL_Quit();
}

SDL_Surface* loadSurface(const char location[]) {
	SDL_Surface* surface = SDL_LoadBMP(location);		
	if(surface == NULL) {
		printf("Could not load image %s\nerror: %s", location, SDL_GetError());
	}
	return surface;
}

void loadMedia() {
	playerSurface = loadSurface("assets/player.bmp");
}

int main(int argc, char* argv[]) {

	if(!init()) {
		return 1;
	}	
	loadMedia();

	mainLoop();

	endProgram();
	
	
	return 0;
}


