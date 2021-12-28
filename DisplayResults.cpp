#include <iostream>

using namespace std;


void DisplayResult(double c, double e, double d, double startSection, double endSection, double endSectionSin, int numberOfSections) {

	cout << c << " | f(x) = sin(x) | Number of sections: " << numberOfSections << " | Sections from: " << startSection << " to: " << endSectionSin << endl;
	cout << e << " | f(x) = x^2+2x+5 | Number of sections: " << numberOfSections << " | Sections from: " << startSection << " to: " << endSection << endl;
	cout << d << " | f(x) = exp(x) | Number of sections: " << numberOfSections << " | Sections from: " << startSection << " to: " << endSection << endl << endl;
}

void DisplayResult(double c, double e, double d, double startSection, double endSection, double endSectionSin) {

	cout << c << " | f(x) = sin(x) | Sections from: " << startSection << " to: " << endSectionSin << endl;
	cout << e << " | f(x) = x^2+2x+5 | Sections from: " << startSection << " to: " << endSection << endl;
	cout << d << " | f(x) = exp(x) | Sections from: " << startSection << " to: " << endSection << endl << endl;
}