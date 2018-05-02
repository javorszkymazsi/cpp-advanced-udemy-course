#include "stdafx.h"
#include "Complex.h"


Complex::Complex() : real(0), imaginary(0)
{
}

Complex::Complex(double real, double imaginary) : real(real), imaginary(imaginary)
{
}

Complex::Complex(const Complex &other)
{
	*this = other;
}

const double Complex::getReal() const
{
	return real;
}

const double Complex::getImaginary() const
{
	return imaginary;
}

bool Complex::operator==(const Complex &other)
{
	return (real == other.real && imaginary == other.imaginary);
}

Complex Complex::operator*() const
{
	return Complex(real, -imaginary);
}

Complex::~Complex()
{
}

std::ostream &operator<<(std::ostream &out, const Complex &other)
{
	out << "(" << other.getReal() << ", " << other.getImaginary() << ")";
	return out;
}

Complex operator+(const Complex &one, const Complex &two)
{
	return Complex(one.getReal() + two.getReal(), one.getImaginary() + two.getImaginary());
}

Complex operator+(const Complex &one, double d)
{
	return Complex(one.getReal() + d, one.getImaginary());
}

Complex operator+(double d, const Complex &one)
{
	return Complex(one.getReal() + d, one.getImaginary());
}