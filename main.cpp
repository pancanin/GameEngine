#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <string>

#include "engine/Engine.h"
#include "sdlutils/SDLLoader.h"


static int32_t runApplication() {
	Engine engine;

	if (EXIT_SUCCESS != engine.init()) {
		std::cerr << "engine.init() failed." << std::endl;

		return EXIT_FAILURE;
	}

	engine.start();

	engine.deinit();

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
