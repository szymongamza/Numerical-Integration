#include "IntegrationMethods.h"

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
