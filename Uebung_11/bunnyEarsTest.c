#include <stdio.h>

int bunnyEars(int bunnies) {
    if (!bunnies) {
        return bunnies;
    } else {
        return 2 + bunnyEars(bunnies - 1);
    }
}

void testResult(int test, int actualResult, int expectedResult) {
	printf("bunnyEars(%d) \t Expected: => %d, Got: %d", test, actualResult, expectedResult);
	if (actualResult == expectedResult) {
		printf(" - PASS");
	} else {
		printf(" - FAIL");
	}
	printf("\n");
}

int main() {
	int test;
	int result;

	test = 0;
	result = bunnyEars(test);
	testResult(test, 0, result);

	test = 1;
	result = bunnyEars(test);
	testResult(test, 2, result);

	test = 2;
	result = bunnyEars(test);
	testResult(test, 4, result);

	test = 3;
	result = bunnyEars(test);
	testResult(test, 6, result);

	test = 4;
	result = bunnyEars(test);
	testResult(test, 8, result);

	test = 5;
	result = bunnyEars(test);
	testResult(test, 10, result);

	test = 12;
	result = bunnyEars(test);
	testResult(test, 24, result);

	test = 50;
	result = bunnyEars(test);
	testResult(test, 100, result);

	test = 234;
	result = bunnyEars(test);
	testResult(test, 468, result);
	return 0;
}