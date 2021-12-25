/*
 * Texture.cpp
 *
 *  Created on: Dec 20, 2021
 *      Author: ubuntu
 */
#include <iostream>

#include "SDL_image.h"

#include "Texture.h"

void Texture::init(const SDL_Texture*& texture, const SDL_Surface*& surface) {
	_texture = texture;
	_surface = surface;
}

SDL_Texture* Texture::raw() const {
	return _texture;
}

void Texture::deinit() {
	if (_surface != nullptr) {
		SDL_FreeSurface(_surface);
		_surface = nullptr;
	}

	SDL_DestroyTexture(_texture);
}
