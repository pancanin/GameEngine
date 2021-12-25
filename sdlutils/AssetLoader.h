/*
 * AssetLoader.h
 *
 *  Created on: Dec 24, 2021
 *      Author: ubuntu
 */

#ifndef SDLUTILS_ASSETLOADER_H_
#define SDLUTILS_ASSETLOADER_H_

#include <cstdint>
#include <string>

struct SDL_Surface;

class AssetLoader {
public:
	AssetLoader() = delete;
	~AssetLoader() = default;

	static int32_t createSurfaceFromFile(const std::string& filePath, SDL_Surface*& surface);
};

#endif /* SDLUTILS_ASSETLOADER_H_ */
