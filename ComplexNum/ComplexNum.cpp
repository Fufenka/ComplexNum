#include "ComplexNum.h"

double ComplexNum::getRealPart() const{
	return real;
}

double ComplexNum::getImaginaryPart() const{
	return imaginary;
}

void ComplexNum::setRealPart(double r) {
	real = r;
}

void ComplexNum::setImaginaryPart(double i) {
	imaginary = i;
}

ComplexNum ComplexNum::operator+(const ComplexNum& other) const{
	return ComplexNum(real + other.real, imaginary + other.imaginary);
}

ComplexNum ComplexNum::operator-(const ComplexNum& other) const {
	return ComplexNum(real - other.real, imaginary - other.imaginary);
}

ComplexNum ComplexNum::operator*(const ComplexNum& other) const {
	return ComplexNum(real * other.real - imaginary * other.imaginary,
		real * other.imaginary + imaginary * other.real);
}

ComplexNum ComplexNum::operator/(const ComplexNum& other) const {
	double A = other.real * other.real + other.imaginary * other.imaginary;
	if (fabs(A - 0.0 < E)) {
		throw std::runtime_error("Division by zero");
	}
	double newReal = (real * other.real + imaginary * other.imaginary) / A;
	double newImaginary = (imaginary * other.real - real * other.imaginary) / A;
	return ComplexNum(newReal, newImaginary);
}

bool ComplexNum::operator==(const ComplexNum& other) const {
	return (fabs(real - other.real) < E && fabs(imaginary - other.imaginary) < E);
}

bool ComplexNum::operator==(double num) const {
	return fabs(real - num) < E;
}

ComplexNum ComplexNum::pow(int n) const {
	double r = 1.0;

	for (int i = 0; i < n; i++) {
		r *= module();
	}
	double theta = atan2(imaginary, real) * n;

	double newReal = r * std::cos(theta);
	double newImaginary = r * std::sin(theta);

	return ComplexNum(newReal, newImaginary);
}


double ComplexNum::module() const {
	return sqrt(real * real + imaginary * imaginary);
}

void ComplexNum::display() {
	std::cout << real << (imaginary < 0 ? " - " : " + ") << abs(imaginary) << "i" << std::endl;
}
