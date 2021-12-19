/*
 * MonitorWindow.h
 *
 *  Created on: Dec 19, 2021
 *      Author: ubuntu
 */

#ifndef SDLUTILS_MONITORWINDOW_H_
#define SDLUTILS_MONITORWINDOW_H_

#include "utils/drawing/Rectangle.h"

#include <string>

struct SDL_Window;

struct MonitorWindowCfg {
	std::string name;
	int32_t x;
	int32_t y;
	int32_t w;
	int32_t h;
	int32_t flags;
};

class MonitorWindow {
public:
	MonitorWindow();
	virtual ~MonitorWindow();

	MonitorWindow(const MonitorWindow& other) = delete;
	MonitorWindow(MonitorWindow&& other) = delete;

	MonitorWindow& operator=(const MonitorWindow& other) = delete;
	MonitorWindow& operator=(MonitorWindow&& other) = delete;

	void init(const MonitorWindowCfg& config);
private:
	SDL_Window* _window = nullptr;
	Rectangle _windowRect;
};

#endif /* SDLUTILS_MONITORWINDOW_H_ */
