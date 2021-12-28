
#include <iostream>
#include <math.h>

#include "DisplayResults.h"
#include "Functions.h"


using namespace std;


//Methods description can be found https://en.wikipedia.org/wiki/Numerical_integration
//"Numerical integration methods can generally be described as combining evaluations of the integrand to get an approximation to the integral."
//Program below uses 3 methods: rectangular, trapezoidal and Simpson's. Each of them has different accuracy. They are tested below on 3 functions defined in Functions.cpp

double RectangularMethod(double a, double b, int n, double(*f)(double)) {
	double s = (b - a) / n;
	double result;
	double sum = 0;
	for (int i = 0; i < n; i++) {
		sum = sum + f(a + (i * s) + (s / 2));
	}
	result = s * sum;
	return result;
}

double TrapezoidalMethod(double a, double b, int n, double(*f)(double)) {
	double s = (b - a) / n;
	double sum = 0;
	for (int i = 0; i < n; i++) {
		sum = sum + ((((a + s * i) + s) - (a + s * i)) / 2) * (f(a + s * i) + f((a + s * i) + s));
	}
	return sum;
}

double ParabolicMethod(double a, double b, int n, double(*f)(double)) {
	double s = (b - a) / n;
	double sum = 0;
	for (int i = 0; i < n; i++) {
		sum = sum + ((((a + s * i) + s) - (a + s * i)) / 6) * ((f(a + s * i) + (4 * f(((a + s * i) + ((a + s * i) + s)) / 2)) + f((a + s * i) + s)));
	}
	return sum;
}

double GaussMethod(double a, double b, int n, double x[], double factor[], double(*f)(double)) {
	double t;
	double result;
	double temp = 0;
	for (int i = 0; i < n; i++) {
		t = ((a + b) / 2) + ((b - a) / 2) * x[i];
		temp = temp + factor[i] * f(t);
	}
	result = ((b - a) / 2) * temp;
	return result;
}


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