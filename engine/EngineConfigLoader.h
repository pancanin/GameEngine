/*
 * EngineConfigLoader.h
 *
 *  Created on: Dec 22, 2021
 *      Author: ubuntu
 */

#ifndef ENGINE_ENGINECONFIGLOADER_H_
#define ENGINE_ENGINECONFIGLOADER_H_

#include "engine/config/EngineConfig.h"

class EngineConfigLoader {
public:
	EngineConfigLoader() = delete;
	~EngineConfigLoader() = default;

	static EngineConfig load();
};

#endif /* ENGINE_ENGINECONFIGLOADER_H_ */
