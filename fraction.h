#pragma once

#include <string>

class Fraction
{
public:
    Fraction(int numerator, int denominator = 1);

    int num, den;
    int order();
    int gcf();
    void simplify();
    Fraction operator*(Fraction f);
    Fraction operator/(Fraction f);
    Fraction operator+(Fraction f);
    Fraction operator-(Fraction f);
    void operator*=(Fraction f);
    void operator/=(Fraction f);
    void operator+=(Fraction f);
    void operator-=(Fraction f);
    operator int();
    operator float();
    operator double();

    std::string to_string();
    
    static Fraction approximate(float f, float tolerance = 0.01);
    static Fraction approximate(double f, double tolerance = 0.01);
};

std::string to_string(Fraction f);