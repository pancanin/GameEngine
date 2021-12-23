/*
 * Game.h
 *
 *  Created on: Dec 23, 2021
 *      Author: ubuntu
 */

#ifndef GAME_GAME_H_
#define GAME_GAME_H_

#include <cstdint>
#include <vector>

struct SDL_Surface;
struct InputEvent;

class Game {
public:
	int32_t init();
	void deinit();
	void draw(std::vector<SDL_Surface*>& surfacesForDrawing);
	void handleEvent(const InputEvent& event);
private:
	int32_t loadResources();

	enum Images {
	  UP, DOWN, LEFT, RIGHT, ALL_KEYS, COUNT
	};

	SDL_Surface* _imageSurfaces[COUNT] {};
	SDL_Surface* _currentImage = nullptr;
};

#endif /* GAME_GAME_H_ */
