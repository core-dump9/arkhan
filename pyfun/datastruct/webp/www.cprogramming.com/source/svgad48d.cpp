/*
|---------------------------------------------------------|
|Welcome to the great and mischevous world of my program  |
|have fun in here, I've labled it nicely so you should    |
|find your away in here just fine.  Have fun!  		  |
|Pat Lorton                                               |
|_________________________________________________________|
*/
#include <conio.h>    // getch(), clrscr()
#include <dos.h>      // MK_FP, geninterrupt()
#include <mem.h>      // memset()
#include <stdio.h>    // printf()
#include <stdlib.h>   // rand()
void SetSVGA();
void SetText();
void TestPixel();
void PutPixel(int x, int y, int drawcolor);
void Intro(){
  clrscr();
  printf ("This is a program that shows you how to use assembler to\ninitialize SVGA and points.  It loops it in an easy to\nsee manner, randomly choosing the color each time\nto see the max colors.\n\nHit any key to continue.....");
  getch();
  clrscr();
}
void Conclusion(){
  clrscr();
  printf ("All done. This concludes this program.  The next one of these that");
  printf ("\ncomes out will be able to load .pcx files, so stay tuned!\n");
  printf ("\nThis Demo program was provided by me, Pat Lorton.");
  printf ("\nIf you wish to contact me to ask how something works,");
  printf ("\nor to report this doesn't work on a certain compiler,");
  printf ("\nthen you can reach me at:\nlortonent2001@yahoo.com");
  getch();
  clrscr();
}
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// SetSVGA() - This function gets you into 640x480x256 mode.
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void SetSVGA() {
  _AX = 0x4f02;
  _BX = 0x101;
  geninterrupt (0x10);
}
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// SetText() - This function gets you into text mode.
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void SetText() {
  _AX = 0x0003;
  geninterrupt (0x10);
}
/* Puts a pixel down by using interputs, REALLY slow, but it works until
I can figure out how to put it down a faster way...... */
 void PutPixel(int x, int y, int drawcolor) {
   _AH = 0x0C;
   _AL = drawcolor;
   _CX = x;
   _DX = y;
   _BX = 0x01;
   geninterrupt (0x10);
}
void TestPixel()
{
int startx=1;
int starty=1;
int drawcolor=1;
while((startx!=640) || (starty!=480))
{
if(startx<640){startx++;}
if((startx==640) && (starty<=480)){starty++;startx=1;}
if((starty==480)&&(startx==639)){startx=640;}
PutPixel(startx,starty,rand());
}
}
// Main Fuction
void main() {
  Intro();              //Tells what I told it to say in intro
  SetSVGA();            //Sets the graphix mode to SVGA
  TestPixel();          //Tests the graphix with my set function
  getch();              //Waits till a key is hit to go on
  SetText();            //Returns to text mode, THE PROGRAM WILL SCREW UP THE MONITOR WITHOUT THIS, SO DON'T TAKE IT OUT!
  Conclusion();         //Says what I told it to say in conclusion
}
