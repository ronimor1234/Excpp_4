// ID: 208018028, Mail: ronimordechai70@gmail.com
#include "Complex.hpp"
#include <cmath>
#include <sstream>
#include <iomanip>

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

// toString for complex
std::string Complex::to_string() const {
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(2) << real;
    if (imag >= 0)
        oss << " + " << std::fixed << std::setprecision(2) << imag << "i";
    else
        oss << " - " << std::fixed << std::setprecision(2) << -imag << "i";
    return oss.str();
}