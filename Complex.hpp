// // ID: 208018028, Mail: ronimordechai70@gmail.com
#ifndef COMPLEX_HPP
#define COMPLEX_HPP
#include <string>
#include <iostream>
#include <iomanip>
#include <cmath>

class Complex {
public:
    double real;
    double imag;

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

    // Complex operator+(const Complex& other) const;
    // Complex operator-(const Complex& other) const;
    // Complex operator*(const Complex& other) const;
    // Complex operator/(const Complex& other) const;

    bool operator==(const Complex& other) const;
    // bool operator!=(const Complex& other) const;
    std::string toString() const;
    friend std::ostream& operator<<(std::ostream& os, const Complex& value);
};

#endif // COMPLEX_HPP