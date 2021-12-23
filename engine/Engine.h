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
#include "game/Game.h"

struct SDL_Surface;
struct EngineConfig;

class Engine {
public:
	int32_t init(const EngineConfig& config);
	void deinit();
	void start();
private:
	void mainLoop();
	void drawFrame();
	bool processFrame();
	void handleEvent();
	void limitFPS(int64_t microseconds);

	MonitorWindow _window;
	InputEvent _event;
	SDL_Surface* _screenSurface = nullptr;
	Game game;
};

#endif /* ENGINE_ENGINE_H_ */
