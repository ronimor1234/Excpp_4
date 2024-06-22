// ID: 208018028, Mail: ronimordechai70@gmail.com
#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include <cmath>

class Complex {
public:
    double real; // Real part of the complex number
    double imag; // Imaginary part of the complex number

    // Constructors
    Complex(double r = 0, double i = 0);

    // Operator to compare two Complex objects based on their magnitude -norm
    // std::hypot(lhs.real, lhs.imag) calculates sqrt(lhs.real^2 + lhs.imag^2)
    bool operator<(const Complex& other) const {
        return std::hypot(real, imag) < std::hypot(other.real, other.imag);
    }

    // Operator to compare two Complex objects based on their magnitude -norm
    // std::hypot(lhs.real, lhs.imag) calculates sqrt(lhs.real^2 + lhs.imag^2)
    bool operator>(const Complex& other) const {
        return std::hypot(real, imag) > std::hypot(other.real, other.imag);
    }

    // Operator to compare two Complex objects for equality
    bool operator==(const Complex& other) const;

    // Converts the complex number to a string representation
    std::string toString() const;

    // Friend function to overload the output stream operator <<
    friend std::ostream& operator<<(std::ostream& os, const Complex& value);

    // Getter function for the real part
    double get_real() const {
        return real;
    }

    // Getter function for the imaginary part
    double get_imag() const {
        return imag;
    }
};

#endif // COMPLEX_HPP
