/*brushing up my c skills*/
#include <stdio.h>

main() {

	printf("Screw us all\n");
	long set = negar(100);
	printf("%lu\n", set);
	return 0;
}

negar (long num) {
	if (num == 0) {
		return 1;

	}else{
	return	num*(negar(num-1));
	}
}