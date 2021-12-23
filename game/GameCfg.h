/*
 * GameCfg.h
 *
 *  Created on: Dec 23, 2021
 *      Author: ubuntu
 */

#ifndef GAME_GAMECFG_H_
#define GAME_GAMECFG_H_

#include <unordered_map>
#include <string>

enum Images {
	UP, DOWN, LEFT, RIGHT, ALL_KEYS, LAYER_2, COUNT
};

struct GameCfg {
	std::unordered_map<Images, std::string> imagePaths;
};


#endif /* GAME_GAMECFG_H_ */
