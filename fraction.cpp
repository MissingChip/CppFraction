#include <stdio.h>
#include <math.h>

#include "fraction.h"

using namespace std;

Fraction::Fraction(int numerator, int denominator){
    num = numerator;
    den = denominator;
    if(denominator < 0){
        den = -den;
        num = -num;
    }
    if(denominator == 0){
        fprintf(stderr, "Fraction %d/%d", num, den);
    }
}

int Fraction::order(){
    return max(abs(num), abs(den));
}
int Fraction::gcf(){
    int a = min(abs(num), abs(den));
    for(int i=a; i>0; i++){
        if(num % i == 0 && den % i == 0){
            return i;
        }
    }
    return 0;
}

void Fraction::simplify(){
    int g = gcf();
    num /= g;
    den /= g;
}

void Fraction::operator*=(Fraction f){
    num*=f.num;
    den*=f.den;
}
void Fraction::operator/=(Fraction f){
    num *= f.den;
    den *= f.num;
}
void Fraction::operator+=(Fraction f){
    num = num*f.den+f.num*den;
    den = den*f.den;
}
void Fraction::operator-=(Fraction f){
    num = num*f.den-f.num*den;
    den = den*f.den;
}

Fraction Fraction::operator*(Fraction f){
    return Fraction(num*f.num, den*f.den);
}
Fraction Fraction::operator/(Fraction f){
    return Fraction(num*f.den, den*f.num);
}
Fraction Fraction::operator+(Fraction f){
    return Fraction(num*f.den+f.num*den, den*f.den);
}
Fraction Fraction::operator-(Fraction f){
    return Fraction(num*f.den-f.num*den, den*f.den);
}
Fraction::operator int(){
    return num/den;
}
Fraction::operator float(){
    return (float)num/(float)den;
}
Fraction::operator double(){
    return (double)num/(double)den;
}

string Fraction::to_string(){
    return std::to_string(num)+"/"+std::to_string(den);
}

string to_string(Fraction f){
    return to_string(f.num)+"/"+to_string(f.den);
}