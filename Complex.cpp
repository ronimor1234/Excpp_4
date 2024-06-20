// ID: 208018028, Mail: ronimordechai70@gmail.com
#include "Complex.hpp"
#include <cmath>
#include "Complex.hpp"
#include <cmath>
#include <iostream>
#include <iomanip>
#include <sstream>

// Constructor
Complex::Complex(double r, double i) : real(r), imag(i) {}

// Addition
Complex Complex::operator+(const Complex& other) const {
    return Complex(real + other.real, imag + other.imag);
}

// Subtraction
Complex Complex::operator-(const Complex& other) const {
    return Complex(real - other.real, imag - other.imag);
}

// Multiplication
Complex Complex::operator*(const Complex& other) const {
    return Complex(real * other.real - imag * other.imag, real * other.imag + imag * other.real);
}

// Division
Complex Complex::operator/(const Complex& other) const {
    double denom = other.real * other.real + other.imag * other.imag;
    return Complex((real * other.real + imag * other.imag) / denom, (imag * other.real - real * other.imag) / denom);
}

// Equality
bool Complex::operator==(const Complex& other) const {
    return real == other.real && imag == other.imag;
}

// Inequality
bool Complex::operator!=(const Complex& other) const {
    return !(*this == other);
}

// toString
std::string Complex::toString() const {
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(2); // Set precision here
    oss << real;
    if (imag >= 0) {
        oss << " + " << imag << "i";
    } else {
        oss << " - " << -imag << "i";
    }
    return oss.str();
}

// Overload operator<< to output Complex objects
std::ostream& operator<<(std::ostream& os, const Complex& value) {
    os << "(" << value.real << ", " << value.imag << "i)";
    return os;
}