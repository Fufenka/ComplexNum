#include "ComplexNum.h"

double ComplexNum::getRealPart() {
	return real;
}

double ComplexNum::getImaginaryPart() {
	return imaginary;
}

void ComplexNum::setRealPart(double r) {
	real = r;
}

void ComplexNum::setImaginaryPart(double i) {
	imaginary = i;
}

ComplexNum ComplexNum::operator+(ComplexNum& other) {
	return ComplexNum(real + other.real, imaginary + other.imaginary);
}

ComplexNum ComplexNum::operator-(ComplexNum& other) {
	return ComplexNum(real - other.real, imaginary - other.imaginary);
}

ComplexNum ComplexNum::operator*(ComplexNum& other) {
	return ComplexNum(real * other.real - imaginary * other.imaginary,
		real * other.imaginary + imaginary * other.real);
}

ComplexNum ComplexNum::operator/(ComplexNum& other) {
	double A = other.real * other.real + other.imaginary * other.imaginary;
	double newReal = (real * other.real + imaginary * other.imaginary) / A;
	double newImaginary = (imaginary * other.real - real * other.imaginary) / A;
	return ComplexNum(newReal, newImaginary);
}

bool ComplexNum::operator==(ComplexNum& other) {
	return (real == other.real && imaginary == other.imaginary);
}

bool ComplexNum::operator==(double num) {
	ComplexNum cnum = *this;
	return cnum.module() == num;
}

ComplexNum ComplexNum::pow1(int n) {
	double r = 1.0;

	for (int i = 0; i < n; i++) {
		r *= module();
	}
	double theta = atan2(imaginary, real) * n;

	double newReal = r * std::cos(theta);
	double newImaginary = r * std::sin(theta);

	return ComplexNum(newReal, newImaginary);
}


double ComplexNum::module() {
	return sqrt(real * real + imaginary * imaginary);
}

void ComplexNum::display() {
	cout << real << (imaginary < 0 ? " - " : " + ") << abs(imaginary) << "i" << std::endl;
}
