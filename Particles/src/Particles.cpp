//============================================================================
// Name        : Particles.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <SDL.h>
#include "Screen.h"
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "Swarm.h"

using namespace std;
using namespace cmr;

int main() {

	srand(time(NULL));

	Screen screen;

	if (screen.init() == false)
	{
		cout << "Error initializing SDL" << endl;
	}

	Swarm swarm;


	while (true)
	{
		//Update particles
		//Draw particles
		int elapsed = SDL_GetTicks();

		//screen.clear();
		swarm.update(elapsed);

		unsigned char green = (1 + sin(elapsed * 0.0001)) * 128;
		unsigned char red = (1 + sin(elapsed * 0.0002)) * 128;
		unsigned char blue = (1 + sin(elapsed * 0.0003)) * 128;

		const CreatingParticles *const pParticles = swarm.getParticles();

		for (int i = 0; i < Swarm::NPARTICLES; i++)
		{
			CreatingParticles particle = pParticles[i];

			int x = (particle.m_x + 1) * (Screen::SCREEN_WIDTH/2);
			int y = particle.m_y * Screen::SCREEN_WIDTH/2 + Screen::SCREEN_HEIGHT/2;

			screen.setPixel(x,y,red,green,blue);
		}

		screen.boxBlur();

		//Draw the screen

		screen.update();

		//Check for messages/events
		if (!screen.processEvents())
		{
			break;
		}
	}


	screen.close();

	return 0;
}
