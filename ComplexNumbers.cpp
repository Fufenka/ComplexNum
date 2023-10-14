#include <iostream>
#include <cmath>

using namespace std;

class ComplexNum {
private:
    double real;
    double imaginary;
public:
    ComplexNum(double r, double i) {
        real = r;
        imaginary = i;
    }
    
    double getRealPart() {
        return real;
    }

    double getImaginaryPart() {
        return imaginary;
    }

    void setRealPart(double r) {
        real = r;
    }

    void setImaginaryPart(double i) {
        real = i;
    }

    ComplexNum operator+(ComplexNum& other) {
        return ComplexNum(real + other.real, imaginary + other.imaginary);
    }

    ComplexNum operator-(ComplexNum& other) {
        return ComplexNum(real - other.real, imaginary - other.imaginary);
    }

    ComplexNum operator*(ComplexNum& other) {
        return ComplexNum(real * other.real - imaginary * other.imaginary,
                            real * other.imaginary + imaginary * other.real);
    }

    ComplexNum operator/(ComplexNum& other) {
        double A = other.real * other.real + other.imaginary * other.imaginary;
        double newReal = (real * other.real + imaginary * other.imaginary) / A;
        double newImaginary = (imaginary * other.real - real * other.imaginary) / A;
        return ComplexNum(newReal, newImaginary);
    }

    bool operator==(ComplexNum& other) {
        return real == other.real && imaginary == other.imaginary;
    }

    bool operator==(double num) {
        return real == num && imaginary == 0;
    }

    ComplexNum pow(int n) {
        if (n == 0) {
            return ComplexNum(1, 0);
        }
        else {
            ComplexNum result = *this;
            for (int i = 1; i < n; i++) {
                result = result * result;
            }
            return result;
        }
    }

    double module() {
        return sqrt(real * real + imaginary * imaginary);
    }

    friend ostream& operator<<(ostream& os, const ComplexNum& number) {
        os << number.real << (number.imaginary < 0 ? " - " : " + ") << abs(number.imaginary) << "i";
        return os;
    }
};

int main() {
    ComplexNum z1(4, -3), z2(4, -3);
    cout << "z1: " << z1.getRealPart() << ' ' << z1.getImaginaryPart() << endl;
    cout << "z2: " << z2.getRealPart() << ' ' << z2.getImaginaryPart() << endl;

    ComplexNum sum = z1 + z2;
    cout << "sum: " << sum.getRealPart() << ' ' << sum.getImaginaryPart() << endl;

    ComplexNum subtraction = z1 - z2;
    cout << "subtraction: " << subtraction.getRealPart() << ' ' << subtraction.getImaginaryPart() << endl;

    ComplexNum multiplication = z1 * z2;
    cout << "multiplication: " << multiplication.getRealPart() << ' ' << multiplication.getImaginaryPart() << endl;

    ComplexNum division = z1 / z2;
    cout << "division: " << division.getRealPart() << ' ' << division.getImaginaryPart() << endl;

    bool a = z1 == z2, b = z1 == 1, c = z1 == 1.0;
    cout << "comparing: " << "z1==z2? : " << a << ' ' << b << ' ' << c << endl;

    ComplexNum pow2 = z1.pow(2);
    cout << "power(2) : " << pow2.getRealPart() << ' ' << pow2.getImaginaryPart() << endl;

    double module = z1.module();
    cout << "module : " << z1.module() << endl;

    cout << z1;

}   