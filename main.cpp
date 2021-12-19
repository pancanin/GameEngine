#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <string>

#include <SDL.h>

#include "sdlutils/SDLLoader.h"

static int32_t loadResources(SDL_Surface*& outImageSurface) {
	const std::string filePath = "../assets/hello.bmp";
	outImageSurface = SDL_LoadBMP(filePath.c_str());

	if (outImageSurface == nullptr) {
		std::cerr << "SDL_LoadBMP() failed. Reason: " << SDL_GetError() << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}

static void draw(SDL_Surface* imageSurface, SDL_Surface* windowGlobalSurface, SDL_Window* window) {
	SDL_BlitSurface(imageSurface, nullptr, windowGlobalSurface, nullptr);

	if (EXIT_SUCCESS != SDL_UpdateWindowSurface(window)) {
		std::cerr << "SDL_UpdateWindowSurface() failed. Reason: " << SDL_GetError() << std::endl;
		return;
	}

	SDL_Delay(5000);
}

static int32_t init(SDL_Window*& outWindow, SDL_Surface*& outWindowGlobalSurface, SDL_Surface*& outImageSurface) {
	const std::string windowName = "Hello, World!";
	const int32_t windowX = SDL_WINDOWPOS_UNDEFINED;
	const int32_t windowY = SDL_WINDOWPOS_UNDEFINED;
	const int32_t windowWidth = 640;
	const int32_t windowHeight = 480;

	outWindow = SDL_CreateWindow(windowName.c_str(), windowX, windowY, windowWidth, windowHeight, SDL_WINDOW_SHOWN);

	if (outWindow == nullptr) {
		std::cerr << "SDL_CreateWindow() failed. Reason: " << SDL_GetError() << std::endl;
		return EXIT_FAILURE;
	}

	outWindowGlobalSurface = SDL_GetWindowSurface(outWindow);

	if (outWindowGlobalSurface == nullptr) {
		std::cerr << "SDL_GetWindowSurface() failed. Reason: " << SDL_GetError() << std::endl;
		return EXIT_FAILURE;
	}

	if (loadResources(outImageSurface) == EXIT_FAILURE) {
		std::cerr << "loadResources() failed" << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}

static void deinit(SDL_Surface*& outImageSurface, SDL_Window*& outWindow) {
	if (outImageSurface != nullptr) {
		SDL_FreeSurface(outImageSurface);
		outImageSurface = nullptr;
	}

	if (outWindow != nullptr) {
		SDL_DestroyWindow(outWindow);
		outWindow = nullptr;
	}
}

static int32_t runApplication() {
	SDL_Window* window = nullptr;
	SDL_Surface* windowGlobalSurface = nullptr;
	SDL_Surface* imageSurface = nullptr;

	if (EXIT_SUCCESS != init(window, windowGlobalSurface, imageSurface)) {
		std::cerr << "init() failed" << std::endl;

		return EXIT_FAILURE;
	}

	draw(imageSurface, windowGlobalSurface, window);

	deinit(imageSurface, window);

	return EXIT_SUCCESS;
}

int32_t main([[maybe_unused]]int32_t argc, [[maybe_unused]]char** argv) {
	if (EXIT_SUCCESS != SDLLoader::init()) {
		std::cerr << "SDLLoader::init() failed" << std::endl;

		return EXIT_FAILURE;
	}

	if (EXIT_SUCCESS != runApplication()) {
		std::cerr << "runApplication() failed" << std::endl;

		return EXIT_FAILURE;
	}

	SDLLoader::deinit();

	return EXIT_SUCCESS;
}
