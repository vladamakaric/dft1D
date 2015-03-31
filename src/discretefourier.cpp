#include "discretefourier.h"
#include <cmath>

using namespace std;

#define PI 3.1415926

std::array<double, 2> DFourier::getZcoeff(int k, std::vector<double> &inputPoints){
	double ReZ = 0;
	double ImZ = 0;

	double radsPerStep = (2 * PI) / nPoints;

	for (int i = 0; i < nPoints; i++){
		ReZ += inputPoints[i]*cos(radsPerStep*k*i);
		ImZ += inputPoints[i]*sin(radsPerStep*k*i);
	}

	return array < double, 2 > {{ ReZ / nPoints, ImZ / nPoints }};
}

DFourier::DFourier(std::vector<double> &inputPoints, double period) : period(period){
	nPoints = inputPoints.size();

	for (int i = 0; i < nPoints; i++){

		auto Z = getZcoeff(i, inputPoints);
		double amplitude = sqrt(Z[0] * Z[0] + Z[1] * Z[1]);
		double phaseShift = 0;
		
		if (amplitude)
			phaseShift = atan2(Z[1], Z[0]);

		phaseShifts.push_back(phaseShift);
		amplitudes.push_back(amplitude);
	}
}

double DFourier::getY(double x){
	double y = 0;
	double angularFreq = (2 * PI) / period;

	
	
	for (int i = 0; i < nPoints - nPoints/2; i++){
		y += amplitudes[i] * cos(angularFreq*i*x - phaseShifts[i]);
	}

	return y;
}
