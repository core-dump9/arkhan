#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	//float t;
	int i;
	int j;
	int zingy;
	for ( i = 1, j = 15; i < 15, j > 0; ++i, --j)
	{
		//printf("%d %d\n", i, j);
		zingy = i*j;

		printf("%d\n", zingy);
	}
	return 0;
}