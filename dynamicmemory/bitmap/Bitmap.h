/*
Author: Monami Mukhopadhyay & Xingyuan Guo
Program: Bitmap
*/

#pragma once

#include<iostream>
#include "Color.h"

using namespace std;

class Bitmap {

private :
    char **bitmap;
    int l;
    int b;

    void lineSimple(int x1, int x2, Color color) {
        for (int i = x1; i <= x2; i++) {
            if (i >= b || i >= l) {
                return;
            }
            bitmap[i][i] = color.getColor();
        }
    }

    void lineBresenham(int x1, int y1, int x2, int y2, Color color) {
        int m_new = 2 * (y2 - y1);
        int err = m_new - (x2 - x1);
        for (int x = x1, y = y1; x <= x2; x++) {
            bitmap[x][y] = color.getColor();
            err += m_new;
            if (err >= 0) {
                y++;
                err -= 2 * (x2 - x1);
            }
        }
    }

public :
    Bitmap(int length, int breadth) {
        l = length;
        b = breadth;
        bitmap = new char *[length];
        for (int i = 0; i < length; i++) {
            bitmap[i] = new char[breadth];
        }
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < b; j++) {
                bitmap[i][j] = '\0';
            }
        }
    }

   //~Bitmap()
  //  {
//        for (int i = 0; i < l; i++)
//            delete[] bitmap[i];
   //     delete[] bitmap;
   // }


    friend ostream &operator<<(ostream &s, const Bitmap b) {
        for (int i = 0; i < b.l; i++) {
            for (int j = 0; j < b.b; j++) {
                if (b.bitmap[i][j] != '\0') {
                    s << b.bitmap[i][j] << " ";
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
        if (x2 == y2 && x1 == y1) {
            lineSimple(x1, x2, color);
        } else {
            // using Bresenham
            lineBresenham(x1, y1, x2, y2, color);
        }
    }

    void horizLine(int x1, int x2, int y, Color color) {
        for (int i = x1; i <= x2; i++) {
            bitmap[y][i] = color.getColor();
        }
    }

    void vertLine(int x, int y1, int y2, Color color) {
        for (int i = y1; i <= y2; i++) {
            bitmap[i][x] = color.getColor();
        }
    }

    void fillRect(int x, int y, int w, int h, Color color) {
        int x_limit = (l > (x + w)) ? (x + w) : l;
        int y_limit = (b > (y + h)) ? (y + h) : b;
        for (int i = x; i <= x_limit; i++) {
            for (int j = y; j <= y_limit; j++) {
                bitmap[i][j] = color.getColor();
            }
        }
    }

    void drawRect(int x, int y, int w, int h, Color color) {
        int x_limit = (l > (x + w)) ? (x + w) : l;
        int y_limit = (b > (y + h)) ? (y + h) : b;
        for (int i = x; i <= x_limit; i++) {
            for (int j = y; j <= y_limit; j++) {
                if ((i == x) | (i == x_limit) | (j == y) | (j == y_limit))
                    bitmap[i][j] = color.getColor();
            }
        }
    }

    void ellipse(int xc, int yc, int w, int h, Color color) {
        int b = h / 2;
        int a = w / 2;
        int x, y;
        float p = b * b - a * a * b + a * a / 4;
        x = 0;
        y = b;

        while (2.0 * b * b * x <= 2.0 * a * a * y) {
            if (p < 0) {
                x++;
                p = p + 2 * b * b * x + b * b;
            } else {
                x++;
                y--;
                p = p + 2 * b * b * x - 2 * a * a * y - b * b;
            }
            plot(yc + y, xc + x, color);
            plot(yc - y, xc + x, color);
            plot(yc + y, xc - x, color);
            plot(yc - y, xc - x, color);
        }

        p = b * b * (x + 0.5) * (x + 0.5) + a * a * (y - 1) * (y - 1) - a * a * b * b;

        while (y > 0) {
            if (p <= 0) {
                x++;
                y--;
                p = p + 2 * b * b * x - 2 * a * a * y + a * a;
            } else {
                y--;
                p = p - 2 * a * a * y + a * a;
            }
            plot(yc + y, xc + x, color);
            plot(yc - y, xc + x, color);
            plot(yc + y, xc - x, color);
            plot(yc - y, xc - x, color);
        }
    }

    void plot(int x, int y, Color color) {
        if (x >= 0 && x < b && y >= 0 && y < l) {
            bitmap[x][y] = color.getColor();
        }
    }
};
