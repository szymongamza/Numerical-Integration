
#include <iostream>
#include <math.h>

#include "DisplayResults.h"
#include "Functions.h"
#include "IntegrationMethods.h"


using namespace std;


//Methods description can be found https://en.wikipedia.org/wiki/Numerical_integration
//"Numerical integration methods can generally be described as combining evaluations of the integrand to get an approximation to the integral."
//Program below uses 5 methods: rectangular, trapezoidal, Simpson's(parabolic) and Gauss–Legendre quadrature with use 2 and 4 number of points. Each of these methods has different accuracy. They're tested on 3 functions defined in Functions.cpp. Result:

int main()
{
	double c;
	double d;
	double e;
	double startSection = 0.5;
	double endSection = 5;
	double endSectionSin = 2.5;
	int numberOfSections = 4;

	cout << "RectangularMethod" << endl;

	c = RectangularMethod(startSection, endSectionSin, numberOfSections, Sinusoidal);
	e = RectangularMethod(startSection, endSection, numberOfSections, Quadratic);
	d = RectangularMethod(startSection, endSection, numberOfSections, Exp);

	DisplayResult(c, e, d, startSection, endSection, endSectionSin, numberOfSections);


	cout << "TrapezoidalMethod" << endl;

	c = TrapezoidalMethod(startSection, endSectionSin, numberOfSections, Sinusoidal);
	e = TrapezoidalMethod(startSection, endSection, numberOfSections, Quadratic);
	d = TrapezoidalMethod(startSection, endSection, numberOfSections, Exp);

	DisplayResult(c, e, d, startSection, endSection, endSectionSin, numberOfSections);;


	cout << "ParabolicMethod" << endl;

	c = ParabolicMethod(startSection, endSectionSin, numberOfSections, Sinusoidal);
	e = ParabolicMethod(startSection, endSection, numberOfSections, Quadratic);
	d = ParabolicMethod(startSection, endSection, numberOfSections, Exp);

	DisplayResult(c, e, d, startSection, endSection, endSectionSin, numberOfSections);


	cout << "GaussMethod 2" << endl;

	int n = 2;
	double x[4];
	x[0] = -sqrt(3) / 3;
	x[1] = sqrt(3) / 3;
	double factor[4];
	factor[0] = 1;
	factor[1] = 1;
	c = GaussMethod(startSection, endSectionSin, n, x, factor, Sinusoidal);
	e = GaussMethod(startSection, endSection, n, x, factor, Quadratic);
	d = GaussMethod(startSection, endSection, n, x, factor, Exp);

	DisplayResult(c, e, d, startSection, endSection, endSectionSin);


	cout << "GaussMethod 4" << endl;

	n = 4;
	x[0] = -(sqrt(525 + (70 * sqrt(30)))) / 35;
	x[1] = -(sqrt(525 - (70 * sqrt(30)))) / 35;
	x[2] = (sqrt(525 - (70 * sqrt(30)))) / 35;
	x[3] = (sqrt(525 + (70 * sqrt(30)))) / 35;
	factor[0] = (18 - sqrt(30)) / 36;
	factor[1] = (18 + sqrt(30)) / 36;
	factor[2] = (18 + sqrt(30)) / 36;
	factor[3] = (18 - sqrt(30)) / 36;

	c = GaussMethod(startSection, endSectionSin, n, x, factor, Sinusoidal);
	e = GaussMethod(startSection, endSection, n, x, factor, Quadratic);
	d = GaussMethod(startSection, endSection, n, x, factor, Exp);

	DisplayResult(c, e, d, startSection, endSection, endSectionSin);


	return 0;

}