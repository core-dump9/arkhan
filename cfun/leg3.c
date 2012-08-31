#include <stdlib.h>
#include <stdio.h>

main() {

	int i = 0 ;
	for ( ; ; ) {
		printf("loop started\n");
		printf("%d\n", i);
		if (i > 10) {
			exit(0);
		}
		i+=1;
	}
	printf("loop ended\n");
}