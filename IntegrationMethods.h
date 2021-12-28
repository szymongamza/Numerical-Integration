#pragma once
double RectangularMethod(double a, double b, int n, double(*f)(double));

double TrapezoidalMethod(double a, double b, int n, double(*f)(double));

double ParabolicMethod(double a, double b, int n, double(*f)(double));

double GaussMethod(double a, double b, int n, double x[], double factor[], double(*f)(double));