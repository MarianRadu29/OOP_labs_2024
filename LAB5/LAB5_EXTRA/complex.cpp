#include "complex.h"
#include<iostream>
Complex::Complex() : Complex(0, 0) {
}

Complex::Complex(double real, double imag) {
    real_data = real;
    imag_data = imag;
}

bool Complex::is_real() const {
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

Complex operator+(const Complex& l, const Complex& r)
{   
    Complex rezultat(l.real() + r.real(), l.imag() + r.imag());
    return rezultat;
}

Complex operator+(const Complex& l, double r)
{
    Complex rezultat(l.real() + r, l.imag());
    return rezultat;
}

Complex operator+(double l, const Complex& r)
{
    Complex rezultat(r.real() + l, r.imag());
    return rezultat;
}

Complex operator-(const Complex& l, const Complex& r)
{
    Complex rezultat(l.real() - r.real(), l.imag() - r.imag());
    return rezultat;
}

Complex operator-(const Complex& l, double r)
{
    Complex rezultat(l.real() - r, l.imag());
    return rezultat;
}

Complex operator-(double l, const Complex& r)
{
    Complex rezultat(l - r.real(),r.imag());
    return rezultat;
}

Complex operator*(const Complex& l, const Complex& r)//(a+bi)(c+di) = ac + adi + bci - bd = (ac - bd)  + (ad + bc)i
{
    Complex rezultat(l.real()*r.real() - l.imag()*r.imag() , l.real() * r.imag() + l.imag()*r.real());
    return rezultat;
}

Complex operator*(const Complex& l, double r)
{
    Complex rezultat(l.real() * r, l.imag()*r);
    return rezultat;
}

Complex operator*(double l, const Complex& r)
{
    Complex rezultat(l * r.real(), l*r.imag());
    return rezultat;
}

Complex operator-(const Complex& obj)
{
    Complex rezultat(obj.real() - 2 * obj.real(), obj.imag() - 2 * obj.imag());
    return rezultat;
}

bool operator==(const Complex& l, const Complex& r)
{
    if (l.real() == r.real() && l.imag() == r.imag())
        return true;
    else
        return false;
}
bool operator!=(const Complex& l, const Complex& r)
{
    if (l.real() != r.real() || l.imag() != r.imag())
        return true;
    else
        return false;
}

std::ostream& operator<<(std::ostream& out, const Complex& complex)
{   
    if (complex.real() != 0)
    {
        if (complex.imag() > 0)
            out << complex.real() << " + " << complex.imag() << 'i';
        if (complex.imag() < 0)
            out << complex.real() << " - " << abs(complex.imag()) << 'i';
        if (complex.imag() == 0)
            out << complex.real();
    }
    else
    {
        if (complex.imag() > 0)
            out << complex.imag() << 'i';
        if (complex.imag() < 0)
            out << complex.imag() << 'i';
        if (complex.imag() == 0)
            out << complex.real();
    }
    return out;
}

Complex& Complex::operator()(double real, double imag)
{
    Complex rezultat(real, imag);
    return rezultat;
}


//op++ postfixed MUST use op++ prefixed
Complex& Complex::operator++()//preincrementare b = 5 , a = ++b => a = 6 si b = 6
{   
    this->real_data++;
    return (*this);
}
Complex Complex::operator++(int val)//postincrementare b = 5 , a = b++ => a = 5 si b = 6
{   
    Complex rezultat = *this; 
    ++(*this); 
    return rezultat; 
}
Complex& Complex::operator--()
{
    this->real_data--;
    return (*this);
}
Complex Complex::operator--(int val)
{
    Complex rezultat = *this;
    --(*this);
    return rezultat;
}
