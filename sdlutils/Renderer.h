/*
 * Renderer.h
 *
 *  Created on: Dec 23, 2021
 *      Author: ubuntu
 */

#ifndef SDLUTILS_RENDERER_H_
#define SDLUTILS_RENDERER_H_

#include <cstdint>

struct SDL_Renderer;
struct SDL_Texture;
struct SDL_Window;

class Renderer {
public:
	int32_t init(SDL_Window *window);
	void deinit();
	void clearScreen();
	void finishFrame();
	void renderTexture(SDL_Texture *texture);
  //forbid the copy/move constructors and assignment operators
private:
	SDL_Renderer *_sdlRenderer = nullptr;
};

#endif /* SDLUTILS_RENDERER_H_ */

