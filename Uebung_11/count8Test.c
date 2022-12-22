#include <stdio.h>

int count8(int num) {
    if (!num) {
        return 0;
    } else {
        if (num % 10 == 8) {
            if ((num / 10) % 10 == 8){
                return 2 + count8(num / 10);
            } else {
                return 1 + count8(num / 10);
            }
        } else {
            return 0 + count8(num / 10);
        }
    }
}

void testResult(int test, int actualResult, int expectedResult) {
	printf("count8(%d) Expected: => %d, Got: %d", test, actualResult, expectedResult);
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

	test = 8;
	result = count8(test);
	testResult(test, 1, result);

	test = 818;
	result = count8(test);
	testResult(test, 2, result);

	test = 8818;
	result = count8(test);
	testResult(test, 4, result);

	test = 8088;
	result = count8(test);
	testResult(test, 4, result);

	test = 123;
	result = count8(test);
	testResult(test, 0, result);

	test = 81238;
	result = count8(test);
	testResult(test, 2, result);

	test = 88788;
	result = count8(test);
	testResult(test, 6, result);

	test = 8234;
	result = count8(test);
	testResult(test, 1, result);

	test = 2348;
	result = count8(test);
	testResult(test, 1, result);

	test = 23884;
	result = count8(test);
	testResult(test, 3, result);

	test = 1818188;
	result = count8(test);
	testResult(test, 5, result);

	test = 8818181;
	result = count8(test);
	testResult(test, 5, result);

	test = 1080;
	result = count8(test);
	testResult(test, 1, result);

	test = 188;
	result = count8(test);
	testResult(test, 3, result);

	test = 88888;
	result = count8(test);
	testResult(test, 9, result);

	test = 9898;
	result = count8(test);
	testResult(test, 2, result);

	test = 78;
	result = count8(test);
	testResult(test, 1, result);

	return 0;
}
