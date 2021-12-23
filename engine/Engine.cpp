/*
 * Engine.cpp
 *
 *  Created on: Dec 22, 2021
 *      Author: ubuntu
 */
#include <iostream>
#include <array>

#include "SDL_surface.h"
#include "SDL_timer.h"

#include "Engine.h"
#include "sdlutils/Texture.h"
#include "utils/thread/ThreadUtils.h"
#include "utils/time/Time.h"
#include "engine/config/EngineConfig.h"

int32_t Engine::init(const EngineConfig& config) {
	if (EXIT_SUCCESS != _window.init(config.windowCfg)) {
		std::cerr << "_window.init() failed" << std::endl;
		return EXIT_FAILURE;
	}

	if (_event.init() == EXIT_FAILURE) {
		std::cerr << "_event.init() failed" << std::endl;
		return EXIT_FAILURE;
	}

	if (game.init() == EXIT_FAILURE) {
		std::cerr << "game.init() failed" << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}

void Engine::deinit() {
	game.deinit();

	_event.deinit();

	_window.deinit();
}

void Engine::start() {
	mainLoop();
}

void Engine::mainLoop() {
	Time time;

	while (true) {
		time.getElapsed();
		const bool shouldExit = !processFrame();

		if (shouldExit) {
			break;
		}

		int64_t timePassed = time.getElapsed().toMicroseconds();

		limitFPS(timePassed);
	}
}

void Engine::drawFrame() {
	std::vector<SDL_Surface*> surfacesForDrawing;
	game.draw(surfacesForDrawing);

	for (const auto& surface : surfacesForDrawing) {
		SDL_BlitSurface(surface, nullptr, _window.getWindowSurface(), nullptr);
	}

	if (EXIT_SUCCESS != _window.update()) {
		std::cerr << "window.update() failed. Reason: " << SDL_GetError() << std::endl;
		return;
	}
}

bool Engine::processFrame() {
	while (_event.poll()) {
		if (_event.hasExitEvent()) {
			return false;
		}

		handleEvent();
	}

	drawFrame();

	return true;
}

void Engine::handleEvent() {
	game.handleEvent(_event);
}

void Engine::limitFPS(int64_t elapsedTime) {
	const int64_t maxFrames = 30;
	const int64_t timeForFrameMicro = 1000000 / maxFrames;
	const int64_t sleepTime = timeForFrameMicro - elapsedTime;

	if (sleepTime <= 0) {
		return;
	}

	ThreadUtils::sleepFor(sleepTime);
}
