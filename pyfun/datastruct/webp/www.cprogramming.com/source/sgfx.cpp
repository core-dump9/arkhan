/*Copyright (C) Aleksandr G. Chukhlebov...
      ...alexc@miacom.net
  SGFX...6 function BASM unit for Borland Turbo C++ 3.0
      ...X,Y...640x480
      ...x256 color
      ...
  message:  does any one know how to write a pixel directly to the video
	    memory?
*/
#include <conio.h>
#include <stdlib.h>
//------------------------------------------------------------------------
int getmaxx(void)
  {
    return 639;
  }
//------------------------------------------------------------------------
int getmaxy(void)
  {
    return 479;
  }
//------------------------------------------------------------------------
int getmaxcolor(void)
  {
    return 255;
  }
//------------------------------------------------------------------------
void setsvga(void)
  {
    asm mov ax,0x4f02;
    asm mov bx,0x101;
    asm int 0x10;
  }
//------------------------------------------------------------------------
void settext(void)
  {
    asm mov ax,0x0003;
    asm int 0x10;
  }
//------------------------------------------------------------------------
void putpixel(unsigned int x,unsigned int y,unsigned char color)
  {
    asm mov ah,0x0c;
    asm mov al,color;
    asm mov cx,x;
    asm mov dx,y;
    asm mov bx,0x01;
    asm int 0x10;
  }
//------------------------------------------------------------------------
void main(void)
  {
    setsvga();
    randomize();
    do
      {
	putpixel(random(getmaxx()),
		 random(getmaxy()),
		 random(getmaxcolor()));
      }
    while(!kbhit());
    settext();
  }