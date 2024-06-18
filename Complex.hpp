// // ID: 208018028, Mail: ronimordechai70@gmail.com
#ifndef COMPLEX_HPP
#define COMPLEX_HPP
#include <string>

class Complex {
public:
    double real;
    double imag;

    Complex(double r = 0, double i = 0);

    Complex operator+(const Complex& other) const;
    Complex operator-(const Complex& other) const;
    Complex operator*(const Complex& other) const;
    Complex operator/(const Complex& other) const;

    bool operator==(const Complex& other) const;
    bool operator!=(const Complex& other) const;
    std::string to_string() const;
};

#endif // COMPLEX_HPP

