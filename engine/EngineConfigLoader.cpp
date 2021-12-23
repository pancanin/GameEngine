/*
 * EngineConfigLoader.cpp
 *
 *  Created on: Dec 22, 2021
 *      Author: ubuntu
 */

#include "EngineConfigLoader.h"
#include "game/GameCfg.h"

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

static void populateGameConfig(GameCfg& config) {
	const std::string ROOT = "../assets/";
	const std::string EX = ".png";

	config.imagePaths[UP] = ROOT + "up" + EX;
	config.imagePaths[DOWN] = ROOT + "down" + EX;
	config.imagePaths[LEFT] = ROOT + "left" + EX;
	config.imagePaths[RIGHT] = ROOT + "right" + EX;
	config.imagePaths[ALL_KEYS] = ROOT + "press_keys" + EX;
	config.imagePaths[LAYER_2] = ROOT + "layer_2" + EX;
}

EngineConfig EngineConfigLoader::load() {
	EngineConfig config;

	populateMonitorConfig(config.windowCfg);
	populateGameConfig(config.gameCfg);

	return config;
}
