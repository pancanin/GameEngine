/*
 * MonitorWindowCfg.h
 *
 *  Created on: Dec 22, 2021
 *      Author: ubuntu
 */

#ifndef CONFIG_MONITORWINDOWCFG_H_
#define CONFIG_MONITORWINDOWCFG_H_

#include <string>

#include "utils/drawing/Point.h"

enum WindowFlags {
	WINDOW_SHOWN = 4,
	WINDOW_FULLSCREEN_DESKTOP = 4097
};

struct MonitorWindowCfg {
	std::string name;
	Point position = Point::UNDEFINED;
	int32_t w = 0;
	int32_t h = 0;
	int32_t flags = 0;
};

#endif /* CONFIG_MONITORWINDOWCFG_H_ */
