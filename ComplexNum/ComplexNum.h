#ifndef COMPLEXNUM_H
#define COMPLEXNUM_H
#include <iostream>

using namespace std;

class ComplexNum {
private:
    double real;
    double imaginary;
public:
    ComplexNum(double real, double imaginary) : real(real), imaginary(imaginary) {}

    double getRealPart();

    double getImaginaryPart();

    void setRealPart(double r);

    void setImaginaryPart(double i);

    ComplexNum operator+(ComplexNum& other);

    ComplexNum operator-(ComplexNum& other);

    ComplexNum operator*(ComplexNum& other);

    ComplexNum operator/(ComplexNum& other);

    bool operator==(ComplexNum& other);

    bool operator==(double num);

    ComplexNum pow1(int n);

    double module();

    void display();
};

#endif