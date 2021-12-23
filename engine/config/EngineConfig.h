/*
 * EngineConfig.h
 *
 *  Created on: Dec 22, 2021
 *      Author: ubuntu
 */

#ifndef ENGINE_CONFIG_ENGINECONFIG_H_
#define ENGINE_CONFIG_ENGINECONFIG_H_

#include <cstdint>

#include "sdlutils/config/MonitorWindowCfg.h"
#include "game/GameCfg.h"

struct EngineConfig {
	MonitorWindowCfg windowCfg;
	GameCfg gameCfg;
};


#endif /* ENGINE_CONFIG_ENGINECONFIG_H_ */
