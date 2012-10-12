// Author: Rohan Dighe
#include <iostream>        
#include <cctype>

void inttobin(int); 

int main(int argc,char *argv[])
{
    if(argc!=2)
    {
        std::cout<<"Input is of format 'dectobin num'"<<std::endl;
    }
    else
    {
        inttobin(atoi(argv[1])); 
    }
}

void inttobin(int x) 
{
    int i, k, mask;
    std::cout<<std::endl<<"The Decimal Number is: "<<x<<std::endl<<"Required binary is: ";
    for(i=sizeof(int) * 8 - 1; i>=0; i--)    // i selects the no of bit positions required
    {
        mask=1<<i;
        k=mask&x;
       if(k==0)
        {
            std::cout<<"0";
        }
        else
        {
            std::cout<<"1";
        }
        // if this is the last in a series of 8 digits, add a space after it
        if ( i % 8 == 0 )
        {
            std::cout<<" ";
        }
        
    }
    std::cout<<std::endl<<std::endl;
} 
