/*
 * MonitorWindow.cpp
 *
 *  Created on: Dec 19, 2021
 *      Author: ubuntu
 */

#include "MonitorWindow.h"

#include <SDL_video.h>

#include <iostream>
#include <cstdlib>

MonitorWindow::MonitorWindow(): _windowRect(Rectangle::UNDEFINED) {}

int32_t MonitorWindow::init(const MonitorWindowCfg& config) {
	Point finalPos;

	if (config.position == Point::UNDEFINED) {
		finalPos.x = SDL_WINDOWPOS_UNDEFINED;
		finalPos.y = SDL_WINDOWPOS_UNDEFINED;
	} else {
		finalPos.x = config.position.x;
		finalPos.y = config.position.y;
	}

	_window = SDL_CreateWindow(
			config.name.c_str(),
			finalPos.x,
			finalPos.y,
			config.w, config.h,
			SDL_WINDOW_SHOWN);

	if (_window == nullptr) {
		std::cerr << "SDL_CreateWindow() failed. Reason: " << SDL_GetError() << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}

int32_t MonitorWindow::update() {
	if (EXIT_SUCCESS != SDL_UpdateWindowSurface(_window)) {
		std::cerr << "SDL_UpdateWindowSurface() failed. Reason: " << SDL_GetError() << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}

void MonitorWindow::deinit() {
	if (_window != nullptr) {
		SDL_DestroyWindow(_window);
		_window = nullptr;
	}
}

SDL_Surface* MonitorWindow::getWindowSurface() {
	SDL_Surface* windowGlobalSurface = SDL_GetWindowSurface(_window);

	if (windowGlobalSurface == nullptr) {
		std::cerr << "SDL_GetWindowSurface() failed. Reason: " << SDL_GetError() << std::endl;
		return nullptr;
	}

	return windowGlobalSurface;
}

MonitorWindow::~MonitorWindow() {
	deinit();
}
