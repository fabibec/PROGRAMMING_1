#include <stdio.h>

int count7(int num) {
	if (!num) {
        return 0;
    } else {
        if (num % 10 == 7) {
            return 1 + count7(num / 10);
        } else {
            return 0 + count7(num / 10);
        }
    }
}

void testResult(int test, int actualResult, int expectedResult) {
	printf("count7(%d) Expected: => %d, Got: %d", test, actualResult, expectedResult);
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

	test = 717;
	result = count7(test);
	testResult(test, 2, result);

	test = 7;
	result = count7(test);
	testResult(test, 1, result);

	test = 123;
	result = count7(test);
	testResult(test, 0, result);

	test = 77;
	result = count7(test);
	testResult(test, 2, result);

	test = 7123;
	result = count7(test);
	testResult(test, 1, result);

	test = 771237;
	result = count7(test);
	testResult(test, 3, result);

	test = 771737;
	result = count7(test);
	testResult(test, 4, result);

	test = 777777;
	result = count7(test);
	testResult(test, 6, result);

	test = 70701277;
	result = count7(test);
	testResult(test, 4, result);

	test = 777576197;
	result = count7(test);
	testResult(test, 5, result);

	test = 99999;
	result = count7(test);
	testResult(test, 0, result);

	test = 99799;
	result = count7(test);
	testResult(test, 1, result);

	return 0;
}
