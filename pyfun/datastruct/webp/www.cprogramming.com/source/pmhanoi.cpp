#include<stdio.h>
#include<conio.h>
int LDisc[8],RDisc[8],CDisc[8],lc=0,rc=0,cc=0,nod;
void transfer(int n,char from,char to,char temp,int i);
void Display(int a[],int count,int col);
void main()
{
	int i;
	clrscr();
	printf("Welcome to Tower Of Hanoi Problem!\n");
	printf("How Many Disk ?");
	scanf("%d",&nod);
	for(i=0;i<nod;i++)
	LDisc[lc++]=nod-i;
	clrscr();
	gotoxy(2,2);
	Display(LDisc,lc,2);
	getch();
	transfer(nod,'L','R','C',1);
}
	
	void transfer(int n,char from,char to,char temp,int i)
	{
		if( n > 0 )
		{
			transfer(n-1,from,temp,to,i+1);
			clrscr();
			printf("Move Disk %d from %c to %c \n",n,from,to);
			switch(from)
			{
				case 'L': if(lc)
					  lc--; break;
				case 'R': if(rc)
					  rc--;break;
				case 'C': if(cc)
					  cc--;break;
			}
			switch(to)
			{
				case 'L': LDisc[lc++]=n;
					  break;
				case 'R':RDisc[rc++]=n;
					 break;
				case 'C':CDisc[cc++]=n;
					 break;
			}	
			gotoxy(2,2);
			Display(LDisc,lc,2);
			gotoxy(27,2);
			Display(RDisc,rc,27);
			gotoxy(52,2);
			Display(CDisc,cc,52);
		    	printf("\n");
			printf("Press Any Key For Next Move ");
			getch();
			transfer(n-1,temp,to,from,i+1);
	}
	return;
}
	
void Display(int a[],int count,int col)
{
	int i,j,k;
	for(i=0;i<nod;i++)
	{
		if(count+i ==	nod)
		{
			for(j=nod;j > a[count-1]-1;j--)
			printf(" ");
			for(j=0;j < a[count-1];j++)
			printf("-");
			printf("|");
			for(j=0;j<a[count-1];j++)
			printf("-");
			for(j=nod;j > a[count-1]-1;j--)
			printf(" ");
			count--;
		}
		else
		{
			for(j=0;j<=nod;j++)
			printf(" ");
			printf("|");
			for(j=0;j<=nod;j++)
			printf(" ");
		}
		k=wherey();
		gotoxy(col,k+1);
	}
}
									
	
	
