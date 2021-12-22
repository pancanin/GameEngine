/*
 * Engine.h
 *
 *  Created on: Dec 22, 2021
 *      Author: ubuntu
 */

#ifndef ENGINE_ENGINE_H_
#define ENGINE_ENGINE_H_

#include <cstdint>

#include "sdlutils/MonitorWindow.h"
#include "sdlutils/InputEvent.h"

struct SDL_Surface;

class Engine {
public:
	int32_t init();
	void deinit();
	void start();
private:
	int32_t loadResources(SDL_Surface *&surface);
	void draw();

	MonitorWindow _window;
	InputEvent _event;
	SDL_Surface* _screenSurface = nullptr;
	SDL_Surface* _imageSurface = nullptr;
};

#endif /* ENGINE_ENGINE_H_ */
