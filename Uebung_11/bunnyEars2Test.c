#include <stdio.h>

int bunnyEars2(int bunnies) {
    if (!bunnies) {
        return bunnies;
    } else if (!(bunnies % 2)) {
        return 3 + bunnyEars2(bunnies - 1);
    } else {
        return 2 + bunnyEars2(bunnies - 1);
    }
}

void testResult(int test, int actualResult, int expectedResult) {
	printf("bunnyEars2(%d) \t Expected: => %d, Got: %d", test, actualResult, expectedResult);
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
	result = bunnyEars2(test);
	testResult(test, 0, result);

	test = 1;
	result = bunnyEars2(test);
	testResult(test, 2, result);

	test = 2;
	result = bunnyEars2(test);
	testResult(test, 5, result);

	test = 3;
	result = bunnyEars2(test);
	testResult(test, 7, result);

	test = 4;
	result = bunnyEars2(test);
	testResult(test, 10, result);

	test = 5;
	result = bunnyEars2(test);
	testResult(test, 12, result);

	test = 6;
	result = bunnyEars2(test);
	testResult(test, 15, result);

	test = 10;
	result = bunnyEars2(test);
	testResult(test, 25, result);

	return 0;
}
