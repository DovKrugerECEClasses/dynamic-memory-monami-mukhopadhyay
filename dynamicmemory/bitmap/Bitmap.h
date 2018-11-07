/*
Author: Monami Mukhopadhyay
Program: Bitmap
*/

#pragma once

#include<iostream>
#include "Color.h"

using namespace std;

class Bitmap {
    
    private :
      void lineSimple(int x1, int x2, Color color) {
           for(int i=x1; i<=x2; i++) {
                  if(i >= b || i>= l) {
                      return;
                  }
                  bitmap[i][i] = color.getColor();
              }
      }
    void lineBresenham(int x1, int y1, int x2, int y2, Color color) {
	int m_new = 2 * (y2-y1);
	int err = m_new - (x2-x1);
	for(int x=x1,y=y1;x<=x2;x++)
	  {
	    bitmap[x][y] = color.getColor();
	    err += m_new;
	    if (err >= 0)
	      {
		y++;
		err -= 2 * (x2-x1);
	      }
	  }         
      }
  /*  lineWu(int x1, int y1, int x2, int y2, Color color) {
          
      }*/
    public :
	  char ** bitmap;
	  int l;
      int b;
      Bitmap(int length, int breadth) {
	  l = length;
	  b = breadth;
          bitmap = new char * [length];
		  for(int i=0; i<length; i++) {
		     bitmap[i] = new char[breadth];
		  }
          for(int i=0;i<l;i++) {
              for(int j=0;j<b;j++) {
                bitmap[i][j] = '\0';   
              }
          }
      }
	  
	  ~Bitmap(){
		  delete [] bitmap;
	  }
	  
  
     friend ostream& operator <<(ostream& s, const Bitmap b) {
          for(int i=0;i<b.l;i++) {
              for(int j=0;j<b.b;j++) {
                  if(b.bitmap[i][j] != '\0') {
                      s<< b.bitmap[i][j] << " ";
                  } else {
                      s << " ";
                  }
              }
              s << endl;
          }
		  return s;
      } 
  
  void getColor(ColorCode code, int i, int j) {
          bitmap[i][j] = code;
      }
  
  void line(int x1, int y1, int x2, int y2, Color color) {
          if(x2 == y2 && x1==y1) {
             lineSimple(x1,x2,color);
          } else {
              // using Bresenham
              lineBresenham(x1, y1, x2, y2, color);
          }
      }
  
  void horizLine(int x1, int x2, int y, Color color) {
    for(int i=x1; i<=x2; i++) {
       bitmap[y][i] = color.getColor();
     }
  }
  
  void vertLine(int x, int y1, int y2, Color color) {
    for(int i=y1; i<=y2; i++) {
       bitmap[i][x] = color.getColor();
      }
  }
  
  void fillRect(int x,int y,int w,int h,Color color) {
	int x_limit = (l>(x+w))? (x+w) : l;
    int y_limit = (b>(y+h))? (y+h) : b; 	
    for(int i=x; i<=x_limit; i++) {
      for(int j=y; j<=y_limit; j++){
          bitmap[i][j] = color.getColor();
       }
    }
  }
};
