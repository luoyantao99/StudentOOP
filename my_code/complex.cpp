#include <iostream>
#include <istream>
#include <iomanip>
#include "complex.h"

using namespace std;


Complex::Complex(double r, double i) : real(r), imag(i) {};


ostream& operator<< (ostream& os, const Complex& c) {
    /*
     * Outputting a `Complex` instance, while illustrating some of the
     * capabilities of I/O streams: `setprecision` gives us a fixed
     * number of decimal places, while `showpos` turns on the plus
     * sign for positive numbers.
     * */
    os << "Real: " << setprecision(3) << c.real << " Imaginary: " << showpos << c.imag << noshowpos;
    return os;
}


/*
 * Read a `Complex` number from an input stream.
 * */
istream& operator>> (istream& is, Complex& c) {
    is >> c.real >> c.imag;
    return is;
}


Complex::operator bool() const {
    if (real == 0 && imag == 0)
        return false;
    return true;
}

Complex& Complex::operator++() {
    ++real;
    return *this;
}

Complex Complex::operator++(int dummy) {
    Complex temp = *this;
    real++;
    return temp;
}


Complex& Complex::operator--() {
    --real;
    return *this;
}

Complex Complex::operator--(int dummy) {
    Complex temp = *this;
    real--;
    return temp;
}

double Complex::get_real() const {
    return real;
}

double Complex::get_imag() const {
    return imag;
}

Complex Complex::operator*(const int i) {
    real *= i;
    imag *= i;
    return *this;
}

Complex& Complex::operator+=(const Complex& c){
    real += c.get_real();
    imag += c.get_imag();
    return *this;
}

Complex& Complex::operator-=(const Complex& c){
    real -= c.get_real();
    imag -= c.get_imag();
    return *this;
}



bool operator== (const Complex& c1, const Complex& c2){
    return c1.get_imag() == c2.get_imag() && c1.get_real() == c2.get_real();
}

bool operator!= (const Complex& c1, const Complex& c2){
    return !(c1.get_imag() == c2.get_imag() && c1.get_real() == c2.get_real());
}


Complex operator+(const Complex& c1, const Complex& c2){
    Complex ret(c1.get_real() + c2.get_real(), c1.get_imag() + c2.get_imag());
    return ret;
}

Complex operator-(const Complex& c1, const Complex& c2){
    Complex ret(c1.get_real() - c2.get_real(), c1.get_imag() - c1.get_imag());
    return ret;
}
