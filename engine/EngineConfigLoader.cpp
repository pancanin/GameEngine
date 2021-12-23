/*
 * EngineConfigLoader.cpp
 *
 *  Created on: Dec 22, 2021
 *      Author: ubuntu
 */

#include "EngineConfigLoader.h"

namespace {
	constexpr auto WINDOW_WIDTH = 640;
	constexpr auto WINDOW_HEIGHT = 480;
	constexpr auto WINDOW_NAME = "Hardware Rendering";
}

static void populateMonitorConfig(MonitorWindowCfg& config) {
	config.name = WINDOW_NAME;
	//	config.position.x = SDL_WINDOWPOS_UNDEFINED;
	//	config.position.y = SDL_WINDOWPOS_UNDEFINED;
	config.w = WINDOW_WIDTH;
	config.h = WINDOW_HEIGHT;
}

EngineConfig EngineConfigLoader::load() {
	EngineConfig config;

	populateMonitorConfig(config.windowCfg);

	return config;
}
