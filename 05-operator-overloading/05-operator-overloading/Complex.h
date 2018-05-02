#pragma once
#include <iostream>

class Complex
{
private:
	double real;
	double imaginary;

public:
	Complex();
	Complex(double real, double imaginary);
	Complex(const Complex &other);
	
	const double getReal() const;
	const double getImaginary() const;

	bool operator==(const Complex &other);
	Complex operator*() const;

	~Complex();
};

std::ostream &operator<<(std::ostream &out, const Complex &other);
Complex operator+(const Complex &one, const Complex &two);
Complex operator+(const Complex &one, double d);
Complex operator+(double d, const Complex &one);
