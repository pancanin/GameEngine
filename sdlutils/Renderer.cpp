/*
 * Renderer.cpp
 *
 *  Created on: Dec 23, 2021
 *      Author: ubuntu
 */

#include "Renderer.h"

#include <iostream>

#include <SDL_render.h>

#include "sdlutils/Texture.h"

//SDL_CreateRenderer() //pass SDL_RENDERER_ACCELERATED as flags
//SDL_SetRenderDrawColor()
//SDL_DestroyRenderer()
//SDL_RenderClear()
//SDL_RenderCopy()
//SDL_RenderPresent()

int32_t Renderer::init(SDL_Window *window) {
	constexpr auto AUTO_DETECT_DRIVER_FLAG = -1;
	_sdlRenderer = SDL_CreateRenderer(window, AUTO_DETECT_DRIVER_FLAG, SDL_RENDERER_ACCELERATED);

	if (_sdlRenderer == nullptr) {
		std::cerr << "SDL_CreateRenderer() failed. Reason: " << SDL_GetError() << std::endl;
		return EXIT_FAILURE;
	}

	if (EXIT_SUCCESS != SDL_SetRenderDrawColor(_sdlRenderer, 0, 0, 0, SDL_ALPHA_OPAQUE)) {
		std::cerr << "SDL_SetRenderDrawColor() failed. Reason: " << SDL_GetError() << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
void Renderer::deinit() {
	if (_sdlRenderer != nullptr) {
		SDL_DestroyRenderer(_sdlRenderer);
		_sdlRenderer = nullptr;
	}
}

void Renderer::clearScreen() {
	if (EXIT_SUCCESS != SDL_RenderClear(_sdlRenderer)) {
		std::cerr << "SDL_RenderClear() failed. Reason: " << SDL_GetError() << std::endl;
		return;
	}
}

void Renderer::finishFrame() {
	SDL_RenderPresent(_sdlRenderer);
}
void Renderer::renderTexture(Texture* texture) {
	SDL_RenderCopy(_sdlRenderer, texture->raw(), nullptr, nullptr);
}
