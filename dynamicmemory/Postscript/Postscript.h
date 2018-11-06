/*
Author : Monami Mukhopadhyay
Program : Postscript class
*/
#pragma once

#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string>
using namespace std;

class Postscript{
private:
  int r,g,b;
  int x,y,w,h,x1,y1,x2,y2,x3,y3;
  string s;
  ofstream outfile;
public:
  Postscript(const string f):outfile(f){}
    
  void line(int x1,int y1,int x2,int y2){
    ofstream outfile;
    outfile.open("test.ps",ios::app);
    outfile << x1 << ' '<< y1 << ' '<< "moveto" << "\r\n";
    outfile << x2 << ' '<< y2 << ' '<< "lineto" << "\r\n";
    outfile << "stroke" << "\r\n";
    outfile.close();
  }
  void setcolor(int r,int g,int b){
    ofstream outfile;
    outfile.open("test.ps",ios::app);
    outfile <<r<<' '<<g<<' '<<b<<' '<<"setrgbcolor"<< "\r\n";
    outfile.close();
  }
  void drawRect(int x,int y,int w,int h){
    ofstream outfile;
    outfile.open("test.ps",ios::app);
    outfile << x <<' '<<y<<' '<<"moveto"<< "\r\n";
    outfile << x <<' '<<y<<' '<<"lineto"<< "\r\n";
    outfile << x+w <<' '<<y+h<<' '<<"lineto"<< "\r\n";
    outfile <<"closepath"<< "\r\n";
    outfile <<"stroke"<< "\r\n";
    outfile.close();
  }
  void fillRect(int x,int y,int w,int h){
    ofstream outfile;
    outfile.open("test.ps",ios::app);
    outfile << x <<' '<<y<<' '<<"moveto"<< "\r\n";
    outfile << x <<' '<<y<<' '<<"lineto"<< "\r\n";
    outfile << x+w <<' '<<y+h<<' '<<"lineto"<< "\r\n";
    outfile <<"closepath"<< "\r\n";
    outfile <<"fill"<< "\r\n";
    outfile.close();
  }
  void drawTriangle(int x1,int y1,int x2,int y2,int x3,int y3){
    ofstream outfile;
    outfile.open("test.ps",ios::app);
    outfile << x1 <<' '<<y1<<' '<<"moveto"<<"\r\n";
    outfile << x2 <<' '<<y2<<' '<<"lineto"<<"\r\n";
    outfile << x3 <<' '<<y3<<' '<<"lineto"<<"\r\n";
    outfile <<"closepath"<<"\r\n";
    outfile <<"stroke"<<"\r\n";
    outfile.close();
  }
  void fillTriangle(int x1,int y1,int x2,int y2,int x3,int y3){
    ofstream outfile;
    outfile.open("test.ps",ios::app);
    outfile << x1 <<' '<<y1<<' '<<"moveto"<<"\r\n";
    outfile << x2 <<' '<<y2<<' '<<"lineto"<<"\r\n";
    outfile << x3 <<' '<<y3<<' '<<"lineto"<<"\r\n";
    outfile <<"closepath"<<"\r\n";
    outfile <<"fill"<<"\r\n";
    outfile.close();
  }
  void drawCircle(int x,int y,int r){
    ofstream outfile;
    outfile.open("test.ps",ios::app);
    outfile << x <<' '<<y<<' '<<"0 360"<<"\r\n";
    outfile <<"arc"<<"\r\n";
    outfile <<"stroke"<<"\r\n";
    outfile.close();
  }
  void fillCircle(int x,int y,int r){
    ofstream outfile;
    outfile.open("test.ps",ios::app);
    outfile << x <<' '<<y<<' '<<"0 360"<<"\r\n";
    outfile <<"arc"<<"\r\n";
    outfile <<"fill"<<"\r\n";
    outfile.close();
  }
  void setFont(const string s,int x){
    ofstream outfile;
    outfile.open("test.ps",ios::app);
    outfile << '/' << s << ' '<<"findfont"<<"\r\n";
    outfile << x <<' '<<"scalefont setfont"<<"\r\n";
    outfile.close();
    }
  void text(int x,int y,const string s){
    ofstream outfile;
    outfile.open("test.ps",ios::app);
    outfile <<x<<' '<<y<<' '<<"moveto"<<"\r\n";
    outfile <<'('<<s<<')'<<' '<<"show"<<"\r\n";
    outfile.close();
    }
  void grid(int x1,int dx,int x2,int y1,int dy,int y2){
    ofstream outfile;
    outfile.open("test.ps",ios::app);
    for(int i=x1;i<=x2;i+=dx){
    outfile <<i<<' '<<0<<' '<<"moveto"<<"\r\n";
    outfile <<i << ' '<< y2+100 << ' '<< "lineto" << "\r\n";
    outfile << "stroke" << "\r\n";
    }
    for(int i=y1;i<=y2;i+=dy){
    outfile <<0<<' '<<i<<' '<<"moveto"<<"\r\n";
    outfile <<x2+100 << ' '<< i << ' '<< "lineto" << "\r\n";
    outfile << "stroke" << "\r\n";
    }
    outfile.close();
    }
};


