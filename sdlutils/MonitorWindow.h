/*
 * MonitorWindow.h
 *
 *  Created on: Dec 19, 2021
 *      Author: ubuntu
 */

#ifndef SDLUTILS_MONITORWINDOW_H_
#define SDLUTILS_MONITORWINDOW_H_

#include "utils/drawing/Rectangle.h"
#include "utils/drawing/Point.h"

#include <string>

struct SDL_Window;
struct SDL_Surface;

struct MonitorWindowCfg {
	std::string name;
	Point position = Point::UNDEFINED;
	int32_t w = 0;
	int32_t h = 0;
	int32_t flags = 0;
};

class MonitorWindow {
public:
	MonitorWindow();
	~MonitorWindow();

	MonitorWindow(const MonitorWindow& other) = delete;
	MonitorWindow(MonitorWindow&& other) = delete;

	MonitorWindow& operator=(const MonitorWindow& other) = delete;
	MonitorWindow& operator=(MonitorWindow&& other) = delete;

	int32_t init(const MonitorWindowCfg& config);
	int32_t update();
	void deinit();

	SDL_Surface* getWindowSurface();
private:
	SDL_Window* _window = nullptr;
	Rectangle _windowRect;
};

#endif /* SDLUTILS_MONITORWINDOW_H_ */
