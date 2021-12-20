#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <string>

#include <SDL.h>
#include <SDL_image.h>

#include "sdlutils/SDLLoader.h"
#include "sdlutils/MonitorWindow.h"
#include "sdlutils/Texture.h"

static int32_t loadResources(SDL_Surface*& outImageSurface) {
	const std::string filePath = "../assets/hello.png";

	if (EXIT_SUCCESS != Texture::createSurfaceFromFile(filePath, outImageSurface)) {
		std::cerr << "createSurfaceFromFile() failed" << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}

static void draw(MonitorWindow& window, SDL_Surface* imageSurface) {
	SDL_BlitSurface(imageSurface, nullptr, window.getWindowSurface(), nullptr);

	if (EXIT_SUCCESS != window.update()) {
		std::cerr << "window.update() failed. Reason: " << SDL_GetError() << std::endl;
		return;
	}

	SDL_Delay(5000);
}

static int32_t init(MonitorWindow& outWindow, SDL_Surface*& outImageSurface) {
	MonitorWindowCfg config;
	config.name = "Hello, World!";
	config.position.x = SDL_WINDOWPOS_UNDEFINED;
	config.position.y = SDL_WINDOWPOS_UNDEFINED;
	config.w = 640;
	config.h = 480;

	if (EXIT_SUCCESS != outWindow.init(config)) {
		std::cerr << "outWindow.init() failed" << std::endl;
		return EXIT_FAILURE;
	}

	if (loadResources(outImageSurface) == EXIT_FAILURE) {
		std::cerr << "loadResources() failed" << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}

static void deinit(SDL_Surface*& outImageSurface, MonitorWindow& window) {
	Texture::deinit(outImageSurface);

	window.deinit();
}

static int32_t runApplication() {
	MonitorWindow window;
	SDL_Surface* imageSurface = nullptr;

	if (EXIT_SUCCESS != init(window, imageSurface)) {
		std::cerr << "init() failed" << std::endl;

		return EXIT_FAILURE;
	}

	draw(window, imageSurface);

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
