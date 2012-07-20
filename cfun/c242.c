#include <stdio.h>

/*print fahrenheit-celsius*/

int main(int argc, char const *argv[])
{
	float fahr, celsius, lower, upper, step;
	lower = 0;
	upper = 300;
	step = 20;

	fahr = lower;

	while(fahr <= upper) {
		celsius = 5 * (fahr-32)/9;
		printf("%3.0f\t%6.1f\n", fahr, celsius);
		if (fahr == upper) {
			printf("Git a life\n");
		}
		fahr = fahr +step;
	}
	return 0;
}