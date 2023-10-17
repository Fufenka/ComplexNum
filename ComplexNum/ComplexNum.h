#ifndef COMPLEXNUM_H
#define COMPLEXNUM_H
#include <iostream>

using namespace std;

class ComplexNum {
private:
    double real;
    double imaginary;
public:
    ComplexNum(double real = 0.0, double imaginary = 0.0) : real(real), imaginary(imaginary) {}

    double getRealPart() const;

    double getImaginaryPart() const;

    void setRealPart(double r);

    void setImaginaryPart(double i);

    ComplexNum operator+(const ComplexNum& other) const;

    ComplexNum operator-(const ComplexNum& other) const;

    ComplexNum operator*(const ComplexNum& other) const;

    ComplexNum operator/(const ComplexNum& other) const;

    bool operator==(const ComplexNum& other) const;

    bool operator==(double num) const;

    ComplexNum pow(int n) const;

    double module() const;

    void display();
};

#endif