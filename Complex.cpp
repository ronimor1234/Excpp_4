// ID: 208018028, Mail: ronimordechai70@gmail.com
#include "Complex.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>

// Constructor
Complex::Complex(double r, double i) : real(r), imag(i) {}

// Operator to compare two Complex objects for equality
bool Complex::operator==(const Complex& other) const {
    return real == other.real && imag == other.imag;
}

// Converts the complex number to a string representation
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

// Friend function to overload the output stream operator <<
std::ostream& operator<<(std::ostream& os, const Complex& value) {
    os << "(" << value.real << ", " << value.imag << "i)";
    return os;
}
