/*
 * Texture.h
 *
 *  Created on: Dec 20, 2021
 *      Author: ubuntu
 */

#ifndef SDLUTILS_TEXTURE_H_
#define SDLUTILS_TEXTURE_H_

struct SDL_Texture;
struct SDL_Surface;

class Texture {
public:
	void init(const SDL_Texture*& texture, const SDL_Surface*& surface);
	void deinit();

	SDL_Texture* raw() const;
private:
	SDL_Texture* _texture;
	SDL_Surface* _surface;
};

#endif /* SDLUTILS_TEXTURE_H_ */
