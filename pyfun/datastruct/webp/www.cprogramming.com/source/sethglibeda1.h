/***************************************************
Graphics Library for Dos Based C++ Programs
Written by: Seth Thielemann a.k.a: The ProgBoss
Version: 1.8.06.01
progboss@sdf.lonestar.org
http://www.snakebyte.biz/progboss
complete documentation is at the site above.
Will Explain more later.
***************************************************/
#ifndef	_SETHS_GRAPHICS_LIB
#define _SETHS_GRAPHICS_LIB
#include<math.h>
const double pi = 3.14159265358979323846;
/*
	A nice little list of functions that this graphics library provides:
	int setup_graphics();
	int destroy_graphics();
	void set_color(int DAC_Color, int Red, int Green, int Blue);
	int  read_pixel(int x, int y);
	void plot_pixel(int x, int y, int color);
	void circle(int Central_x, int Central_y, int Radius_x, int Radius_y, int Color);
	void line(int x0, int y0, int x1, int y1, int color);
	void box(int x0, int y0, int x1, int y1, bool fill, int color);
	void fill(int x, int y, int NColorValue, int OColorValue);
	void color_print(char *pstr, int ForegroundC, int BackgroundC);
	void clrscr(int foreground, int background);
	void gotoxy(int des_x, int des_y);
	void beep(unsigned int frequency, unsigned long int duration);
	int  inkey();
*/
// CLASSES //////////////////////////////////////////////////////////////
class SPoint
{
public:
	int x,y;
};
//////////////////////////
class PStack
{
public:
	PStack(const unsigned long int depth)
	{
		max_depth = depth - 1;
		sp = depth - 1;
  		dArray = new SPoint [depth];
	}
	~PStack()
	{
		delete [] dArray;
	}
	void push(int px, int py);
	void pop();
	SPoint retrieve();
	unsigned int long max_depth, sp;
private:
	SPoint *dArray;
};
SPoint PStack::retrieve()
{
	SPoint retv = dArray[sp];
	return(retv);
}
void PStack::push(int px, int py)
{
	if (sp < 0) return;
	dArray[sp].x  = px;
	dArray[sp].y  = py;
	sp--;
}
void PStack::pop()
{
	if (sp > max_depth) return;
	sp++;
}
/////////////////////////////////////////////////////////////////////////
/*
	setup_graphics(), sets up computer into 320x200 VGA 256 color mode
*/
int setup_graphics();
/*
	destroy_graphics(), destroys and puts the computer back to text mode 80x25
*/
int destroy_graphics();
/*
	set_color(int dac_color, int red, int green, int blue) allows you to change
		and individual DAC REGISTER, but this is just changing the current
		RGB value that he DAC holds, 0-255 are legal DAC Registers.
*/
void set_color(int dac_color, int red, int green, int blue);
/*
	int read_pixel(int x, int y); returns the current pixel color at the given
		x, and y co-ordinates.
*/
int read_pixel(int x, int y);
/*
	plot_pixel(int,int,int) turns the given x,y co-ordinate to the screen
*/
void plot_pixel(int x, int y,int color);
/*
	circle(int,int,int,int,int) draws a circle to the screen given the central
			x,y co-ordinate points, and the radius.
*/
void circle(int Central_x, int Central_y, int Radius_x, int Radius_y, int Color);
/*
	line(int,int,int,int,int) draws a line from x,y co-ordinate 1 to x,y
			co-ordinate 2. Uses the Bresenham Algorithm, found from
			André Lamothe's "Tricks of the Game Programming Guru's." and
			changed a little bit.
*/
void line(int x0, int y0, int x1, int y1, int color);
/*
	box(int,int,int,int,bool,int) draws a box, x0, y0 are the top
			left of the box, the x1, y1 is the bottom right of the
			box, then if the boolean variable is false, it does not
			fill the box in, if its true, then it is filled in.
*/
void box(int x0, int y0, int x1, int y1, bool fill, int color);
/*
	void fill(int x, int y, int NColorValue, int OColorValue) fills in
	an object also if you wanted you could clear the screen with this function
	but it is very slow, just use my clrscr(). On an object this works
	pretty fast, this function basicly explains itself.
*/
void fill(int x, int y, int NColorValue, int OColorValue);
/*
	color_print(char *pstr, int ForegroundC, int BackgroundC)
	this will print your string that you send to the character
	pointer with the foreground (ForegroundC) and the Background
	(BackgroundC) of your choice to the screen, at the current
	cursor position.
*/
void color_print(char *pstr, int ForegroundC, int BackgroundC);
/*
   clrscr(int foreground, int background); CLeaRs the SCReen, with
   the given foregound and background colors.
*/
void clrscr(int foreground, int background);
/*
	gotoxy(int des_x, int des_y) supply the destination of
	x and y, and this function will move the cursor to that
	spot.
*/
void gotoxy(int des_x, int des_y);
/*
	void beep(unsigned int frequency, unsigned long int duration)
	this function send in the frequency of the beep, and the duration
	is of course how long the beep lasts, duration is measured in 
	microseconds.
*/
void beep(unsigned int frequency, unsigned long int duration);
/*
	inkey() if the user presses a key at the current time, it is
		returned as an integer, if it is a normal character in the
		ASCII character set, it will return the ASCII code for it.
		OTHERWISE, it sets the bottom portion of the integer to the
		byte scan code and sets the higher byte to a 1. So, if the
		key is a normal it will always be less than 256 otherwise its
		a scan code, subtract 256. Just use a char() typecast to change
		to a character.
*/
int inkey();
// function definitions
int setup_graphics()
{
	_asm
	{
		mov ax,0x0013
		int 0x10
	};
	return(0);
}
// *******************************
int destroy_graphics()
{
	_asm
	{
		mov ax,0x03
		int 0x10
	};
	return(0);
}
// ********************************
void set_color(int dac_color, int red, int green, int blue)
{
	_asm
	{
		mov ax,0x1010
		mov bx,dac_color
		xor bh,bh
		mov ch,green
		mov cl,blue
		mov dh,red
		int 0x10
	};
}
// ********************************
int read_pixel(int x, int y)
{
	int value;
	_asm
	{
		mov ax,0x0D00
		mov cx,x
		mov dx,y
		int 0x10
		xor ah,ah
		mov value,ax
	};
	return(value);
}
// ********************************
void plot_pixel(int x, int y, int color)
{
	_asm
	{
		mov ax,color
		mov ah,0x0C
		mov cx,x
		mov dx,y
		int 0x10
	};
}
// *********************************
void circle(int Central_x, int Central_y, int Radius_x, int Radius_y, int Color)
{
	int theta,
		old_x,
		old_y,
		new_x,
		new_y;
	old_y = int(sin(0) * Radius_y + Central_y);
	old_x = int(cos(0) * Radius_x + Central_x);
	for(theta = 0; theta < 361; theta++)
	{
		new_y = int(sin(theta * pi / 180) * Radius_y + Central_y);
		new_x = int(cos(theta * pi / 180) * Radius_x + Central_x);
		line(old_x,old_y,new_x,new_y,Color);
		old_y = new_y;
		old_x = new_x;
	}
}
// *************************************
void line(int x0, int y0, int x1, int y1,int color)
{
	int rise,
		run,
		rise2,
		run2,
		x_dif,
		y_dif,
		error,
		index;
	rise = y1 - y0;
	run  = x1 - x0;
	if( run >= 0 )
	{
		x_dif = 1;
	}
	else
	{
		x_dif = -1;
		run = -run;
	}
	if( rise >= 0 )
	{
		y_dif = 1;
	}
	else
	{
		y_dif = -1;
		rise = -rise;
	}
	rise2 = rise * 2;
	run2  = run  * 2;
	if ( run > rise )
	{
		error = rise2 - run;
		for(index = 0; index <= run; index++)
		{
			plot_pixel(x0,y0,color);
			if ( error >= 0 )
			{
				error -= run2;
				y0 += y_dif;
			}
			error += rise2;
			x0 += x_dif;
		}
	}
	else
	{
		error = run2 - rise;
		for(index = 0; index <= rise; index++)
		{
			plot_pixel(x0,y0,color);
			if (error >= 0)
			{
				error -= rise2;
				x0 += x_dif;
			}
			error += run2;
			y0 += y_dif;
		}
	}
}
// *************************************
void box(int x0, int y0, int x1, int y1, bool fill, int color)
{
	int index,
		distance_y;
	line(x0,y0,x1,y0,color);
	line(x0,y1,x1,y1,color);
	line(x0,y0,x0,y1,color);
	line(x1,y0,x1,y1,color);
	if( fill == true )
	{
		distance_y = int( sqrt((y1-y0) * (y1-y0)) );
		for( index = 0; index < distance_y; index++ )
		{
			line(x0,(y0 + index),x1,(y0 + index),color);
		}
	}
}
// ****************************************
void fill(int x, int y, int NColorValue, int OColorValue)
{
// try up, right, down, left...
	if ( (read_pixel(x,y) == OColorValue) || (read_pixel(x,y) == NColorValue) || (x >= 320) || (y>=200) || (x<=0) || (y<=0) )
		return;
	unsigned long int watch = 0;
	PStack stack(64000);
	SPoint dummyP;
	stack.push(x,y);
	watch++;
fill_right:
	x++;
	if( (read_pixel(x,y) == OColorValue) || (read_pixel(x,y) == NColorValue) || (x >= 320) || (y>=200) || (x<=0) || (y<=0) )
	{
   		x--;
		goto fill_down;
	}
	plot_pixel(x,y,NColorValue);
	stack.push(x,y);
	watch++;
	goto fill_right;
fill_down:
	y++;
	if( (read_pixel(x,y) == OColorValue) || (read_pixel(x,y) == NColorValue) || (x >= 320) || (y>=200) || (x<=0) || (y<=0) )
	{
   		y--;
		goto fill_left;
	}
	plot_pixel(x,y,NColorValue);
	stack.push(x,y);
	watch++;
	goto fill_right;
fill_left:
	x--;
	if( (read_pixel(x,y) == OColorValue) || (read_pixel(x,y) == NColorValue) || (x >= 320) || (y>=200) || (x<=0) || (y<=0) )
	{
   		x++;
		goto fill_up;
	}
   plot_pixel(x,y,NColorValue);
   stack.push(x,y);
   watch++;
   goto fill_right;
fill_up:
	y--;
	if( ((read_pixel(x,y) == OColorValue) || (read_pixel(x,y) == NColorValue)  || (x >= 320) || (y>=200) || (x<=0) || (y<=0)) && (watch == 0) )
   		return;
	if( (read_pixel(x,y) == OColorValue) || (read_pixel(x,y) == NColorValue) || (x >= 320) || (y>=200) || (x<=0) || (y<=0) )
	{
		  stack.pop();
		  watch--;
		  dummyP = stack.retrieve();
		  x = dummyP.x;
		  y = dummyP.y;
		  goto fill_right;
	}
	plot_pixel(x,y,NColorValue);
	stack.push(x,y);
	watch++;
	goto fill_right;
}
// **************************************
void color_print(char *pstr, int ForegroundC, int BackgroundC)
{
	char cc,temp;
	int attribute; 
	_asm
	{
		mov bx,BackgroundC
		mov cl,04
		shl bl,cl
		mov cx,ForegroundC
		add bl,cl
		xor bh,bh
		mov attribute,bx
	};
_color_print_topper:
	cc = *pstr;
    pstr++;
	if( cc != 0 )
	{
		_asm
		{
			mov ah,0x09
			mov al,cc
			mov bx,attribute
			xor bh,bh
			mov cx,01
			int 0x010
			mov ax,0x0300
			xor bh,bh
			int 0x010
			inc dl
			mov temp,dl
		};
		if ( temp >= 80 )
		{
			_asm
			{
				xor dl,dl
				inc dh
			};
		}
		_asm
		{
			mov ax,0x0200
			xor bh,bh
			int 0x010
		};
		goto _color_print_topper;
	}
}
// **************************************
void clrscr(int foreground, int background)
{
   _asm
   {
      mov ax,background
      mov bx,0x10
      mul bx
      add ax,foreground
      xchg bh,al
      xor cx,cx
      mov dh,24
      mov dl,79
      xor bl,bl
      mov ax,0x0600
      int 0x010
   };
}		
// **************************************
void gotoxy(int des_x, int des_y)
{
	_asm
	{
		mov ax,0x0200
		xor bh,bh
		mov dx,des_y
		xchg dh,dl
		mov cx,des_x
		xchg dl,cl
		int 0x010
	};
}
// **************************************
void beep(unsigned int frequency, unsigned long int duration)
{
	frequency = (unsigned int)1193180 / frequency; // 8253 timer Operational frequency
	_asm
	{
		in al,0x061
		push ax
		mov al,182 // 10110110b = Channel 2, LSB followed by MSB, Operation Mode 3, Binary Count
		out 0x043,al
		mov ax,frequency	// move calculated frequency into the ax register
		out 0x042,al		// send out lower byte of the frequency
		xchg ah,al			// exchange ah with al
		out 0x042,al		// send out the higher order byte
		in al,0x061
		or al,03			// lower 2 bits are for sound
		out 0x061,al		// start sound
		mov ax,0x8600					// delay interrupt
		mov cx,word ptr duration[2]		// higher order delay (in microseconds)
		mov dx,word ptr duration		// lower order delay word
		int 0x015						// cause interrupt
		pop ax
		out 0x061,al
	};
}
// **************************************
int inkey()
{
	int value;
	_asm
	{
		mov ax,0x0100
		int 0x16
		jnz _was_a_key_pressed
		mov value,00
	};
return(value);
_was_a_key_pressed:
	_asm
	{
		mov value,ax
	};
	if( value < 256 )
	{
		return(value);
	}
	else
	{
		// it is easier for me, and faster if I do this code portion in assembly....
		_asm
		{
			mov ax,value
			xchg al,ah
			xor ah,ah
			mov ah,01
			mov value,ax
		};
		return(value);
	}
}
#endif