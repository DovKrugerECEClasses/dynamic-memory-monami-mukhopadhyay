/*
Author: Monami Mukhopadhyay & Xingyuan Guo
Program: Fraction
*/
#include<iostream>
#include "Fraction.h"
using namespace std;

Fraction::Fraction(int n, int d):num(n),den(d) {}

// member operator
Fraction Fraction::operator -(const Fraction& f) {
  return Fraction(num*f.den-den*f.num,den*f.den);
}

