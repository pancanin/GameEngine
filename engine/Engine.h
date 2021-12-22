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

enum Images {
  UP, DOWN, LEFT, RIGHT, ALL_KEYS, COUNT
};


class Engine {
public:
	int32_t init();
	void deinit();
	void start();
private:
	int32_t loadResources();

	void mainLoop();
	void drawFrame();
	bool processFrame();
	void handleEvent();
	void limitFPS(int64_t microseconds);

	MonitorWindow _window;
	InputEvent _event;
	SDL_Surface* _screenSurface = nullptr;
	SDL_Surface* _imageSurfaces[COUNT] {};
	SDL_Surface* _currentImage = nullptr;
};

#endif /* ENGINE_ENGINE_H_ */
