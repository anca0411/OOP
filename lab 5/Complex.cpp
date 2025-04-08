#include "complex.h"

Complex::Complex() : Complex(0, 0){ }

Complex::Complex(double real, double imag)
{
    real_data = real;
    imag_data = imag;
}

bool Complex::is_real() const
{
    return imag() == 0;
}

double Complex::real() const {
    return real_data;
}

double Complex::imag() const {
    return imag_data;
}

double Complex::abs() const {
    return sqrt(real() * real() + imag() * imag());
}

Complex Complex::conjugate() const {
    return { real(), -imag() };
}
Complex& Complex::operator()(double real, double imag)
{
    real_data = real;
    imag_data = imag;
    return *this;
}
Complex& Complex::operator--()
{
    real_data--;
    return *this;
}
Complex Complex::operator--(int)
{
    Complex temp = *this;
    real_data--;
    return temp;
}
Complex& Complex::operator++()
{
    real_data++;
    return *this;
}
Complex Complex::operator++(int)
{
    Complex temp = *this;
    real_data--;
    return temp;
}
Complex operator+(const Complex& l, const Complex& r)
{
    Complex c(l.real() + r.real(), l.imag() + r.imag());
    return c;
}
Complex operator+(const Complex& l, double r)
{
    Complex c(l.real() + r, l.imag());
        return c;
}
Complex operator+(double l, const Complex& r)
{
    Complex c(l + r.real(), r.imag());
    return c;
}
Complex operator-(const Complex& l, const Complex& r)
{
    Complex c(l.real() - r.real(), l.imag() - r.imag());
    return c;
}
Complex operator-(const Complex& l, double r)
{
    Complex c(l.real() - r, l.imag());
        return c;
}
Complex operator-(double l, const Complex& r)
{
    Complex c(l - r.real(), r.imag());
    return c;
}
Complex operator*(const Complex& l, const Complex& r)
{
    Complex c(l.real() * r.real() - l.imag() * r.imag(), l.real() * r.imag() + l.imag() * r.real());
    return c;
}
Complex operator*(const Complex& l, double r)
{
    Complex c(l.real() * r, l.imag()*r);
        return c;
}
Complex operator*(double l, const Complex& r)
{
    Complex c(l * r.real(), l*r.imag());
    return c;
}
Complex operator-(const Complex& obj)
{
    Complex c(-obj.real(), -obj.imag());
    return c;
}
bool operator==(const Complex& l, const Complex& r)
{
    if (l.real() == r.real() && l.imag() == r.imag())
        return true;
    return false;
}
bool operator==(double l, const Complex& r)
{
    return (l == r.real() || 0 == r.imag());
}
bool operator==(const Complex& l,double r)
{
    return (l.real() == r || l.imag() == 0);
}
bool operator!=(const Complex& l, const Complex& r)
{
    if (l.real() != r.real() || l.imag() != r.imag())
        return true;
    return false;
}
bool operator!=(double l, const Complex& r)
{
    return (l != r.real() || 0 != r.imag());
}
bool operator!=(Complex& l, double r)
{
    return (l.real() != r || l.imag() != 0);
}

std::ostream& operator<<(std::ostream& out, const Complex& complex)
{
    out << complex.real() << ' ' << complex.imag()<<'i';
    return out;
}