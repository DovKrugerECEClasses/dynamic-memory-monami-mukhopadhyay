/*
Author : Monami Mukhopadhyay
Program : Postscript output
*/

#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string>
#include "Postscript.h"
using namespace std;

int main(){
  Postscript p("test.ps");
  p.line(0,0,300,400);
  p.setcolor(1,0,0);
  p.drawRect(100,50,50,20);
  p.fillRect(100,50,50,20);
  p.drawTriangle(100,100,50,50,25,25);
  p.fillTriangle(100,100,50,50,25,25);
  p.drawCircle(100,100,50);
  p.fillCircle(100,100,50);
  p.setFont("Helvetica",32);
  p.text(100,100,"testing testing 123");
  p.grid(300,50,500,400,50,700);

  return 0;
}
