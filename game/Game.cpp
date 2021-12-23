/*
 * Game.cpp
 *
 *  Created on: Dec 23, 2021
 *      Author: ubuntu
 */

#include "Game.h"

#include <string>
#include <array>
#include <iostream>

#include "sdlutils/Texture.h"
#include "sdlutils/InputEvent.h"

int32_t Game::loadResources() {
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

int32_t Game::init() {
	if (loadResources() == EXIT_FAILURE) {
		std::cerr << "loadResources() failed" << std::endl;
		return EXIT_FAILURE;
	}

	_currentImage = _imageSurfaces[ALL_KEYS];

	return EXIT_SUCCESS;
}

void Game::deinit() {
	for (int32_t idx = 0; idx < COUNT; idx++) {
		Texture::deinit(_imageSurfaces[idx]);
	}
}

void Game::draw(std::vector<SDL_Surface*>& surfacesForDrawing) {
	surfacesForDrawing.push_back(_currentImage);
}

void Game::handleEvent(const InputEvent& event) {
	if (event.touchEvent == TouchEvent::KEYBOARD_PRESS) {
		switch (event.key) {
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
