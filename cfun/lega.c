#include <stdio.h>

void get (int a, int b) {
	int sum;
	sum = (a+b);
	printf("%d\n", sum);
}

int main(int argc, char const *argv[])
{
	get(4, 4);
	return 0;
}