/*
 * Texture.h
 *
 *  Created on: Dec 20, 2021
 *      Author: ubuntu
 */

#ifndef SDLUTILS_TEXTURE_H_
#define SDLUTILS_TEXTURE_H_

#include <string>

struct SDL_Surface;

class Texture {
public:
	Texture() = delete;
	~Texture() = delete;

	static int32_t createSurfaceFromFile(const std::string& filePath, SDL_Surface*& surface);
	static void deinit(SDL_Surface*& surface);
};

#endif /* SDLUTILS_TEXTURE_H_ */
