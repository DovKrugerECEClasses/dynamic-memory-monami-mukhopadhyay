/*
Author: Monami Mukhopadhyay & Xingyuan Guo
Program: Bitmap
*/

#pragma once

#include<cstdint>

enum ColorCode {
  RED='R', BLUE='B', GREEN='G', WHITE='W', BLACK='b', NOCOL='\0'
};

class Color {
    
     private:
      uint32_t rgba;
      
      public:
        Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
            rgba = (r<<24) | (g<<16) | (b<<8) | a ;
        }
		char getColor() {
          char code = NOCOL;
		  switch(rgba) {
		    case 0xFF0000FF : code = RED ; break;
			case 0x00FF00FF : code = GREEN; break ;
			case 0x0000FFFF : code = BLUE; break;
			case 0xFFFFFFFF : code = WHITE; break;
			case 0x000000FF : code = BLACK; break;
		  }
		  return code;          		  
        }
};
