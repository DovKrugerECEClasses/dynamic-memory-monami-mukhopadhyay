/*
Author: Monami Mukhopadhyay
Program: Template functions
*/
#include<iostream>
using namespace std;

template<typename T>
void sort(T x[],int n){
  for(int i=0;i<n-1;i++){
    for(int j=0;j<n-1;j++){
      if (x[j]>x[j+1]){
	swap(x[j],x[j+1]);
      }
    }
  }
}

template<typename T>
void print(T x[],int n){
  for(int i=0;i<n;i++){
    cout << x[i] << ' ';
  }
  cout << '\n';
}

template<typename T>
T sum(T x[],int n){
  T s=0;
  for(int i=0;i<n;i++){
    s += x[i];
  }
  return s;
}

int main() {
	int a[] = {5, 4, 3, 1, 7, 8, 9, 2, 1};
	sort(a, sizeof(a)/sizeof(int));
	print(a, sizeof(a)/sizeof(int));
	
	double b[] = {5.5, 4.5, 1.2, 2.9, 9.2, 5.2};
	sort(b, sizeof(b)/sizeof(double));
	print(b, sizeof(b)/sizeof(double));

	cout << sum(a, sizeof(a)/sizeof(int)) << '\n';
	cout << sum(b, sizeof(b)/sizeof(double)) << '\n';

	string c[] = {"yo", "ho", "test", "foo", "bar"};
	sort(c, sizeof(c)/sizeof(string));
	print(c, sizeof(c)/sizeof(string));
	//TODO?	cout << sum(c, sizeof(c)/sizeof(string)) << '\n';
}
