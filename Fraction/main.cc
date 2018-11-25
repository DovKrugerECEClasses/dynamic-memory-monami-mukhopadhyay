/*
Author: Monami Mukhopadhyay & Xingyuan Guo
Program: Fraction
*/
#include<iostream>
#include "Fraction.h"
#include "Fraction.cc"
using namespace std;

int main() {
	Fraction a(1,2);
	Fraction b(1,3);
	Fraction c = a + b;
	cout << c << '\n';
	Fraction d = a - b;
	cout << d << '\n';
}
