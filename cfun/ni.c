#include <stdio.h>
#include <stdlib.h>

main()
{
	int z[5];
	int c;
	int *po;

	z[0] = 3;
	z[1] = 4;
	z[2] = 3;
	z[3] = 2;
	z[4] = 1;

	po = &z[0];

	c = *po;
	printf("%d\n", c);
	exit(0);
}