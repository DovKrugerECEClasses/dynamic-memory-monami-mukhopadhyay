/*
Author: Monami Mukhopadhyay & Xingyuan Guo
Program: Fraction
*/

#pragma once

#include<iostream>
using namespace std;

class Fraction {
private:
	int num, den;
public:
	Fraction(int n, int d);
	
	//friend operator
	friend Fraction	operator +(const Fraction& left, const Fraction& right){
	  return Fraction(left.num*right.den+left.den*right.num,left.den*right.den);
	}
	
	Fraction operator -(const Fraction& f);
	
	friend ostream& operator <<(ostream& s, const Fraction& f){
	  return s << f.num << '/' << f.den;
	}
};
