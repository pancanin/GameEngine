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

	if (loadResources() == EXIT_FAILURE) {
		std::cerr << "loadResources() failed" << std::endl;
		return EXIT_FAILURE;
	}

	if (_event.init() == EXIT_FAILURE) {
		std::cerr << "_event.init() failed" << std::endl;
		return EXIT_FAILURE;
	}

	_currentImage = _imageSurfaces[ALL_KEYS];

	return EXIT_SUCCESS;
}

void Engine::deinit() {
	_event.deinit();

	for (int32_t idx = 0; idx < COUNT; idx++) {
		Texture::deinit(_imageSurfaces[idx]);
	}

	_window.deinit();
}

void Engine::start() {
	mainLoop();
}

int32_t Engine::loadResources() {
	const std::string ROOT = "../assets/";
	const std::string EX = ".png";

	const std::array<std::string, COUNT> filePaths = {
			ROOT + "up" + EX,
			ROOT + "down" + EX,
			ROOT + "left" + EX,
			ROOT + "right" + EX,
			ROOT + "press_keys" + EX,
	};

	int32_t idx = 0;

	for (const auto& path : filePaths) {
		if (EXIT_SUCCESS != Texture::createSurfaceFromFile(path, _imageSurfaces[idx++])) {
			std::cerr << "createSurfaceFromFile() failed for file " << path << std::endl;
			return EXIT_FAILURE;
		}
	}

	return EXIT_SUCCESS;
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
	SDL_BlitSurface(_currentImage, nullptr, _window.getWindowSurface(), nullptr);

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
	if (_event.touchEvent == TouchEvent::KEYBOARD_PRESS) {
		switch (_event.key) {
			case Keyboard::KEY_UP:
				_currentImage = _imageSurfaces[UP];
				break;
			case Keyboard::KEY_DOWN:
				_currentImage = _imageSurfaces[DOWN];
				break;
			case Keyboard::KEY_LEFT:
				_currentImage = _imageSurfaces[LEFT];
				break;
			case Keyboard::KEY_RIGHT:
				_currentImage = _imageSurfaces[RIGHT];
				break;
			default:
				_currentImage = _imageSurfaces[ALL_KEYS];
				break;
		}
	} else {
		_currentImage = _imageSurfaces[ALL_KEYS];
	}
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
