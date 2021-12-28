#include "Functions.h"
#include <math.h>

double Sinusoidal(double x) {
	double result;
	result = sin(x);
	return result;
}

double Quadratic(double x) {
	double result;
	result = (x * x) + (2 * x) + 5;
	return result;
}

double Exp(double x) {
	double result;
	result = exp(x);
	return result;
}