/*
 * SDLLoader.h
 *
 *  Created on: Dec 19, 2021
 *      Author: ubuntu
 */

#ifndef SDLUTILS_SDLLOADER_H_
#define SDLUTILS_SDLLOADER_H_

#include <cstdint>

class SDLLoader {
public:
	SDLLoader() = delete;
	virtual ~SDLLoader() = default;

	static int32_t init();

	static void deinit();
};

#endif /* SDLUTILS_SDLLOADER_H_ */
