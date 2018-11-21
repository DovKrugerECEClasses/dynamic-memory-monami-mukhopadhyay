/*
Author: Monami Mukhopadhyay
Program: Template- Vec3d
*/

#include<iostream>
#include "Vec3d.h"

using namespace std;

int main() {
	Vec3d<float> a(1,2,3);
	Vec3d<double> b(1.5, 2.2, 3.5);
	cout << a << b << '\n';
	Vec3d<double> c(1.9, 1.1, 4.1);
	cout << b + c << '\n';
}
