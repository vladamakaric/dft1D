#ifndef DISCRETE_FOURIER_H
#define DISCRETE_FOURIER_H

#include <iostream>
#include <vector>
#include <array>

class DFourier{
private:
	double period;
	double nPoints;
	std::vector<double> phaseShifts;
	std::vector<double> amplitudes;
	std::array<double, 2> getZcoeff(int k, std::vector<double> &inputPoints);
public:
	DFourier(std::vector<double> &inputPoints, double period);
	double getY(double x);
};



#endif