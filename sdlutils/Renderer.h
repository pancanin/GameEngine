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
struct Texture;

class Renderer {
public:
	Renderer(const Renderer& other) = delete;
	Renderer(Renderer&& other) = delete;

	Renderer& operator=(const Renderer& other) = delete;
	Renderer& operator=(Renderer&& other) = delete;

	int32_t init(SDL_Window *window);
	void deinit();
	void clearScreen();
	void finishFrame();
	void renderTexture(Texture* texture);
private:
	SDL_Renderer* _sdlRenderer = nullptr;
};

#endif /* SDLUTILS_RENDERER_H_ */

