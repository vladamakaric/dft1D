#ifndef FOURIER_GUI_H
#define FOURIER_GUI_H
#include "discretefourier.h"
#include "DSControl.h"
#include <SDL2/SDL.h>


class FourierGUI{
	bool recompute;
	DSControl dscontrol;
	DFourier *dfourier;
public:
	FourierGUI(int npoints);
	void draw(SDL_Renderer* gRenderer);
	void handleEvents(SDL_Event &e);

};


#endif
