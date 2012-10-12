#include <stdio.h>
int findzeros(unsigned int n);
int main(int argv, char ** argc)
{
    unsigned int i = 0;
    printf("Please enter the factorial: ");
    scanf("%u",&amp;i);
    printf("The amount of zeros in factorial %u! is %u\n",i,findzeros(i));

    for (i = 0;i &lt; 0;i++)
    {
        printf("The amount of zeros in factorial %u! is %u\n",i,findzeros(i));
    }
    return 0;
}
int findzeros(unsigned int n)
{
    int result = 0;
    while ( n &gt; 0)
    {
        n /= 5;
        result += n;
    }
    return result;
}

