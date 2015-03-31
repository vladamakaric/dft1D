#include "FourierGUI.h"
#include "global.h"


FourierGUI::FourierGUI(int npoints) : dscontrol(npoints){
	dfourier = new DFourier(dscontrol.points, SCREEN_WIDTH);
}
void FourierGUI::draw(SDL_Renderer* gRenderer){

	if (recompute)
	{
		delete dfourier;
		dfourier = new DFourier(dscontrol.points, SCREEN_WIDTH);
	}

	recompute = false;

	int npoints = dscontrol.points.size();
	SDL_SetRenderDrawColor(gRenderer, 0x00, 0xFF, 0x00, 0xFF);
	

	double pointDx = SCREEN_WIDTH / npoints;

	for (int i = 0; i < npoints; i++)
		SDL_RenderDrawLine(gRenderer, pointDx*i, SCREEN_HEIGHT, pointDx*i, SCREEN_HEIGHT - dscontrol.points[i]);

	int nOfLineSegs = 100;
	SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0xFF, 0xFF);
	double dx = (double)SCREEN_WIDTH / nOfLineSegs;
	double prevY = dfourier->getY(0);
	for (int i = 0; i < nOfLineSegs; i++){
		double curY = dfourier->getY(dx*(i + 1));
		SDL_RenderDrawLine(gRenderer,  dx*i, SCREEN_HEIGHT - prevY,   dx*(i + 1), SCREEN_HEIGHT - curY);
		prevY = curY;
	}
	
	SDL_SetRenderDrawColor(gRenderer, 0x00, 0xFF, 0xFF, 0xFF);

	double x = dscontrol.currentPoint*pointDx;
	double y = SCREEN_HEIGHT - dscontrol.points[dscontrol.currentPoint];

	double r = 10;

	SDL_Rect outlineRect = { x - r,  (y - r), r*2, r*2 };

	SDL_RenderDrawRect(gRenderer, &outlineRect);

}

void FourierGUI::handleEvents(SDL_Event &e){
	
	double dy = 10;
	if (e.type == SDL_KEYDOWN)
	{
		switch (e.key.keysym.sym)
		{
			case SDLK_UP:
				dscontrol.changeCurrentPointHeight(dy);
				recompute = true;
				break;

			case SDLK_DOWN:
				dscontrol.changeCurrentPointHeight(-dy);
				recompute = true;
				break;

			case SDLK_LEFT:
				dscontrol.goToLeftPoint();
				break;

			case SDLK_RIGHT:
				dscontrol.goToRightPoint();
				break;
			case SDLK_SPACE:
				dscontrol.addNewPoint();
				recompute = true;
				break;

			case SDLK_BACKSPACE:
				dscontrol.removeLastPoint();
				recompute = true;
				break;
		}
	}
}
		
