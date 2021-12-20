/*
 * Texture.cpp
 *
 *  Created on: Dec 20, 2021
 *      Author: ubuntu
 */
#include <iostream>

#include "SDL_image.h"

#include "Texture.h"

int32_t Texture::createSurfaceFromFile(const std::string& filePath, SDL_Surface*& outImageSurface) {
	outImageSurface = IMG_Load(filePath.c_str());

	if (outImageSurface == nullptr) {
		std::cerr << "SDL_LoadBMP() failed. Reason: " << SDL_GetError() << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}

void Texture::deinit(SDL_Surface*& surface) {
	if (surface != nullptr) {
		SDL_FreeSurface(surface);
		surface = nullptr;
	}
}
