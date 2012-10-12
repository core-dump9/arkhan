/*
   Shiny text with simple and small code.
   You can see its effect on Colored  Monitor
   This Program is made in TURBO C++ Version 3.0

   Last updated 24th January 2002.

   NUM2WORD.C :  1 Fnctions (Main).
   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
   This Program is only for Educational Purpose.
   By Trilochan Singh
   ~~~~~~~~~~~~~~~~~~~
	 ษอออออออออออออออออออออออออออออออป
	 บ         REPORT ERRORS         บ
	 บ         Edited levels         บ
	 บ     Questions/Comments/Bugs   บ
	 ศออออออออออออออหออออออออออออออออผ
	 ษออออออออออออออสออออออออออออออออป
	 บ trilochan_saini@indiatimes.comบ
	 บ trilochansaini_177@yahoo.co.inบ
	 ศอออออออออออออออออออออออออออออออผ
*/
/**************************************************************
*                    I N C L U D E  F I L E S             *
**************************************************************/
#include<stdio.h>
#include<conio.h>


/**************************************************************
*                   M A I N   F U N C T I O N                 *
**************************************************************/
int main()
{
	char *name;
	int len,count,place,row;
	clrscr();
	textbackground(0);
	printf("\n Enter Your Name : ");
	gets(name);
	len=strlen(name); // Find the Length of name
	for(count=0;count<=len;count++)
	{
		row=30;
		for(place=0;place<len;place++)
		{
			if(place==count)
			{
				textcolor(13);
				gotoxy(row++,10);
				cprintf("%c",name[count]);
			}
			else
			{
				textcolor(10);
				gotoxy(row++,10);
				cprintf("%c",name[place]);
			}
		}
		delay(200); // Wait for 200 milliseconds
	}
        return 0;
}
/****************** E N D   O F   P R O G R A M **************/
