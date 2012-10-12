/* Slot Machine Program by Joe Tchamitchian*/ 
#include <iostream.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	
	int x,a, b, c, token=4;
	srand(time(0));
	
	cout<<"\t********************************************************\n"
	    <<"\t*              Welcome to slot machine.                *\n"
		<<"\t*  Would you like to play? (1 to play, 2 not to play)  *\n"
		<<"\t********************************************************\n\n";
	cin>>x;
	while(token!=0)
	{cout<<"You have "<<token<< " tokens\n\n"
	    <<"Pull? (1 to pull, 2 not to pull)\n\n";
	cin>>x;
	
	
	
	
	if(x==1)
{	
	
	 a = 1+rand() %10;
	 b = 1+rand() %10;
	 c = 1+rand() %10;
	
	
	cout<<"\t\t"<<a<<"          "<<b<<"          "<<c<<"\n\n";
	
}
		else
		cout<<"OK\n";
		{		
				
		if(a==b==c)
		{
			
			token+=4;
			cout<<"You win\n\n";
		}		
		if(a==b || b==c || a==c)
		{
			token+=1;
		
		cout<<"You got two out of three\n\n";
		
		
		}
		else
		{
			token-=1;
			
		
		cout<<"You loose\n\n";
		}
		
		}
	}
		
		
				
			return 0;
}