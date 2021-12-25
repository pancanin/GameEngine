/*
 * AssetLoader.cpp
 *
 *  Created on: Dec 24, 2021
 *      Author: ubuntu
 */

#include "AssetLoader.h"

#include <iostream>

#include "SDL_image.h"

int32_t AssetLoader::createSurfaceFromFile(const std::string& filePath, SDL_Surface*& surface) {
	surface = IMG_Load(filePath.c_str());

	if (surface == nullptr) {
		std::cerr << "SDL_LoadBMP() failed. Reason: " << SDL_GetError() << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
