#include<iostream.h>
void shift(int,char,char,char);
int main()
{
  int n;
  cout<<"How many disks do you have :";
  cin>>n;                      //taking input from the user..
  cout<<"\n";
  shift(n,'L','R','T');        //calling the function which done our job...
  return 0;
}
void shift(int num,char from,char to,char temp)
{
  if(num>0)
    {
      //first shift n-1 disks from the top of the stack to one temperory disk
      //then shift the last one to the right most one.
      
      shift((num-1),from,temp,to);
      cout<<"Move \t"<<num<<"\t from \t"<<from<<"\t to \t"<<to;
      cout<<"\n";
      
      //then do the process to get the whole disks onto one stack
      shift((num-1),temp,to,from);
    }
  return;
}
