/*
 * SDLLoader.cpp
 *
 *  Created on: Dec 19, 2021
 *      Author: ubuntu
 */

#include "SDLLoader.h"

#include <cstdlib>
#include <iostream>

#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <SDL_mixer.h>

int32_t SDLLoader::init() {
	if (EXIT_SUCCESS != SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_AUDIO)) {
		std::cerr << "SDL_Init() failed. Reason: " << SDL_GetError() << std::endl;
		return EXIT_FAILURE;
	}

	constexpr int32_t imgFlags = IMG_INIT_PNG;
	if (!(IMG_Init(imgFlags) & imgFlags)) {
		std::cerr << "IMG_Init() failed. Reason: " << IMG_GetError() << std::endl;
		return EXIT_FAILURE;
	}

	if (EXIT_SUCCESS != TTF_Init()) {
		std::cerr << "TTF_Init() failed. Reason: " << SDL_GetError() << std::endl;
		return EXIT_FAILURE;
	}

	if (0 > Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048)) {
		std::cerr << "Mix_OpenAudio() failed. Reason: " << SDL_GetError() << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}

void SDLLoader::deinit() {
	TTF_Quit();
	IMG_Quit();
	Mix_Quit();
	SDL_Quit();
}
