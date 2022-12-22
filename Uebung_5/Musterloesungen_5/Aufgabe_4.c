#include <stdio.h>

void cube (int *n) {
	*n = (*n) * (*n) * (*n);
}

int main (void) {
	int number = 5;

	printf ("The number: %d\n", number);
	cube(&number);
	printf ("The result: %d\n", number);

	return 0;
}
