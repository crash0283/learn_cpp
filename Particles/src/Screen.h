/*
 * Screen.h
 *
 *  Created on: Mar 6, 2015
 *      Author: chrisrasch
 */

#ifndef SCREEN_H_
#define SCREEN_H_

#include <SDL.h>

namespace cmr {

class Screen {
public:
	const static int SCREEN_WIDTH = 1280;
	const static int SCREEN_HEIGHT = 720;
private:
	SDL_Window *m_window;
	SDL_Renderer *m_renderer;
	SDL_Texture *m_texture;
	Uint32 *m_buffer1;
	Uint32 *m_buffer2;
public:
	Screen();
	bool init();
	bool processEvents();
	void close();
	void clear();
	void update();
	void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
	void boxBlur();


};

} /* namespace cmr */

#endif /* SCREEN_H_ */

