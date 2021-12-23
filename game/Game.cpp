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
#include <unordered_map>

#include "sdlutils/Texture.h"
#include "sdlutils/InputEvent.h"

int32_t Game::loadResources(const std::unordered_map<Images, std::string>& imagePaths) {
	for (const auto& imagePath : imagePaths) {
		if (EXIT_SUCCESS != Texture::createSurfaceFromFile(imagePath.second, _imageSurfaces[imagePath.first])) {
			std::cerr << "createSurfaceFromFile() failed for file " << imagePath.second << std::endl;
			return EXIT_FAILURE;
		}
	}

	return EXIT_SUCCESS;
}

int32_t Game::init(const GameCfg& config) {
	if (loadResources(config.imagePaths) == EXIT_FAILURE) {
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
