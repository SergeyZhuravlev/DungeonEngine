#include <dungeng/engine.hpp>
#include <SDL.h>
#include <stdio.h>
#include <boost/any.hpp>
#ifdef WIN32
#include <windows.h>
#endif

int main(int argc, char** argv) {
#ifdef WIN32
	AllocConsole();
	FILE* fDummy;
	freopen_s(&fDummy, "CONIN$", "r", stdin);
	freopen_s(&fDummy, "CONOUT$", "w", stderr);
	freopen_s(&fDummy, "CONOUT$", "w", stdout);
#endif
	fprintf(stdout, "hello world");
	SDL_Window* window = NULL;
	SDL_Surface* screenSurface = NULL;
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
	fprintf(stderr, "could not initialize sdl2: %s\n", SDL_GetError());
	return 1;
	}
	window = SDL_CreateWindow(
				"hello_sdl2",
				SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
				640, 480,
				SDL_WINDOW_SHOWN
				);
	if (window == NULL) {
	fprintf(stderr, "could not create window: %s\n", SDL_GetError());
	return 1;
	}
	screenSurface = SDL_GetWindowSurface(window);
	SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0x00, 0xFF, 0xFF));
	SDL_UpdateWindowSurface(window);
	SDL_Delay(2000);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}