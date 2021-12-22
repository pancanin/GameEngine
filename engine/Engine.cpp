/*
 * Engine.cpp
 *
 *  Created on: Dec 22, 2021
 *      Author: ubuntu
 */
#include <iostream>

#include "SDL_surface.h"
#include "SDL_timer.h"

#include "Engine.h"
#include "sdlutils/Texture.h"

int32_t Engine::init() {
	MonitorWindowCfg config;
	config.name = "Hello, World!";
//	config.position.x = SDL_WINDOWPOS_UNDEFINED;
//	config.position.y = SDL_WINDOWPOS_UNDEFINED;
	config.w = 640;
	config.h = 480;

	if (EXIT_SUCCESS != _window.init(config)) {
		std::cerr << "_window.init() failed" << std::endl;
		return EXIT_FAILURE;
	}

	if (loadResources(_imageSurface) == EXIT_FAILURE) {
		std::cerr << "loadResources() failed" << std::endl;
		return EXIT_FAILURE;
	}

	if (_event.init() == EXIT_FAILURE) {
		std::cerr << "_event.init() failed" << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}

void Engine::deinit() {
	_event.deinit();
	Texture::deinit(_imageSurface);
	_window.deinit();
}

void Engine::start() {
	draw();
}

int32_t Engine::loadResources(SDL_Surface*& outImageSurface) {
	const std::string filePath = "../assets/hello.png";

	if (EXIT_SUCCESS != Texture::createSurfaceFromFile(filePath, outImageSurface)) {
		std::cerr << "createSurfaceFromFile() failed" << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}

void Engine::draw() {
	SDL_BlitSurface(_imageSurface, nullptr, _window.getWindowSurface(), nullptr);

	if (EXIT_SUCCESS != _window.update()) {
		std::cerr << "window.update() failed. Reason: " << SDL_GetError() << std::endl;
		return;
	}

	SDL_Delay(5000);
}


//while (true) {
//	while (event.poll()) {
//		if (event.touchEvent == TouchEvent::KEYBOARD_PRESS) {
//			std::cout << "key pressed: " << event.key << std::endl;
//		}
//	}
//}
