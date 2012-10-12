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
#include <dos.h>
#define VIDEO 0x10
union REGS regs;
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
   regs.x.ax = 0x4f02;
   regs.x.bx = 0x101;
   int86(VIDEO, &regs, &regs);
}
//------------------------------------------------------------------------
void settext(void)
{
   regs.x.ax = 0x0003;
   int86(VIDEO, &regs, &regs);
}
//------------------------------------------------------------------------
void putpixel(unsigned int x,unsigned int y,unsigned char color)
{
   regs.h.ah = 0x0c;
   regs.h.al = color;
   regs.x.cx = x;
   regs.x.dx = y;
   regs.x.bx = 0x01;
   int86(VIDEO, &regs, &regs);
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
