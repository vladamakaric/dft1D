#include "DSControl.h"



DSControl::DSControl(int pointNum) : currentPoint(0), gen(rd()), dis(100,300){
	for (int i = 0; i < pointNum; i++){
		points.push_back(dis(gen));
	}
}

void DSControl::goToRightPoint(){ currentPoint = (currentPoint + 1) % points.size(); }
void DSControl::goToLeftPoint(){ currentPoint = (currentPoint - 1 + points.size()) % points.size(); }
void DSControl::addNewPoint(){
	points.push_back(dis(gen));
}

void DSControl::removeLastPoint(){
	points.pop_back();
}

void DSControl::changeCurrentPointHeight(double deltaY){
	points[currentPoint] += deltaY;
}