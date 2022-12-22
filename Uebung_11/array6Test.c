#include <stdio.h>

int array6(int nums[], int startIndex, int length) {
    if (!length) {
        return 0;
    } else if(nums[startIndex] == 6) {
        return 1;
    } else {
        return array6(nums, (startIndex + 1), (length - 1));
    }
}

void testResult(int actualResult, int expectedResult) {
	printf("array6() Expected: => %d, Got: %d", actualResult, expectedResult);
	if (actualResult == expectedResult) {
		printf(" - PASS");
	} else {
		printf(" - FAIL");
	}
	printf("\n");
}

int main() {
	int result;

	int test1[] = {1, 6, 4};
	result = array6(test1, 0, 3);
	testResult(1, result);

	int test2[] = {1, 4};
	result = array6(test2, 0, 2);
	testResult(0, result);

	int test3[] = {6};
	result = array6(test3, 0, 1);
	testResult(1, result);

	int test4[] = {};
	result = array6(test4, 0, 0);
	testResult(0, result);

	int test5[] = {6, 2, 2};
	result = array6(test5, 0, 3);
	testResult(1, result);

	int test6[] = {2, 5};
	result = array6(test6, 0, 2);
	testResult(0, result);

	int test7[] = {1, 9, 4, 6, 6};
	result = array6(test7, 0, 5);
	testResult(1, result);

	int test8[] = {2, 5, 6};
	result = array6(test8, 0, 3);
	testResult(1, result);

	return 0;
}
