#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <string>

#include <SDL.h>

SDL_Window* window = nullptr;
SDL_Surface* windowGlobalSurface = nullptr;
SDL_Surface* imageSurface = nullptr;


static int32_t loadResources() {
	const std::string filePath = "../assets/hello.bmp";
	imageSurface = SDL_LoadBMP(filePath.c_str());

	if (imageSurface == nullptr) {
		std::cerr << "SDL_LoadBMP() failed. Reason: " << SDL_GetError() << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}

static void draw() {
	SDL_BlitSurface(imageSurface, nullptr, windowGlobalSurface, nullptr);

	if (EXIT_SUCCESS != SDL_UpdateWindowSurface(window)) {
		std::cerr << "SDL_UpdateWindowSurface() failed. Reason: " << SDL_GetError() << std::endl;
		return;
	}

	SDL_Delay(5000);
}

static int32_t init() {
	if (EXIT_SUCCESS != SDL_Init(SDL_INIT_VIDEO)) {
		std::cerr << "SDL_Init() failed. Reason: " << SDL_GetError() << std::endl;
		return EXIT_FAILURE;
	}

	const std::string windowName = "Hello, World!";
	const int32_t windowX = SDL_WINDOWPOS_UNDEFINED;
	const int32_t windowY = SDL_WINDOWPOS_UNDEFINED;
	const int32_t windowWidth = 640;
	const int32_t windowHeight = 480;

	window = SDL_CreateWindow(windowName.c_str(), windowX, windowY, windowWidth, windowHeight, SDL_WINDOW_SHOWN);

	if (window == nullptr) {
		std::cerr << "SDL_CreateWindow() failed. Reason: " << SDL_GetError() << std::endl;
		return EXIT_FAILURE;
	}

	windowGlobalSurface = SDL_GetWindowSurface(window);

	if (windowGlobalSurface == nullptr) {
		std::cerr << "SDL_GetWindowSurface() failed. Reason: " << SDL_GetError() << std::endl;
		return EXIT_FAILURE;
	}

	if (loadResources() == EXIT_FAILURE) {
		std::cerr << "loadResources() failed" << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}

static void deinit() {
	if (imageSurface != nullptr) {
		SDL_FreeSurface(imageSurface);
		imageSurface = nullptr;
	}

	if (window != nullptr) {
		SDL_DestroyWindow(window);
		window = nullptr;
	}

	SDL_Quit();
}

int32_t main([[maybe_unused]]int32_t argc, [[maybe_unused]]char** argv) {
	if (EXIT_SUCCESS != init()) {
		std::cerr << "init() failed" << std::endl;

		return EXIT_FAILURE;
	}

	draw();

	deinit();

	return EXIT_SUCCESS;
}
