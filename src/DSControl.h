#ifndef DSCONTROL_H
#define DSCONTROL_H

#include <vector>
#include <random>
#include "discretefourier.h"


class DSControl{
public:
	DSControl(int pointNum);
	std::vector<double> points;
	int currentPoint;
	
	std::random_device rd;
	std::mt19937 gen;
	std::uniform_real_distribution<> dis;


	void goToLeftPoint();
	void goToRightPoint();
	void addNewPoint();
	void removeLastPoint();
	void changeCurrentPointHeight(double deltaY);
};



#endif