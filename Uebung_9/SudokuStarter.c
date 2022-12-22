/*
*
* SudokuStarter.c
*
* This program checks whether a sudoko square contains
* numbers in the right range (i.e. 1 to 9) and whether
* each number occurs only once in a square.
*
*/

#include <stdio.h>

int checkSudokuSquare(int sudokuSquare[][3]) {
	int numbers_present[9] = {0};

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int num = sudokuSquare[j][i];
            if (num >= 0 && num <= 9 && numbers_present[num - 1] == 0){
                numbers_present[num - 1] = 1;
            } else {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
	// Test square - Run your solution against all three two dimensional arrays
	int sudokuSquareOne[3][3] = { {1, 2, 3},
						{7, 8, 9},
						{4,5,6}};
	int sudokuSquareTwo[3][3] = { {1, 1, 3},
						{8, 8, 9},
						{4,5,6}};
	int sudokuSquareThree[3][3] = { {10, 2, 3},
						{7, -1, 9},
						{4,5,6}};

	int result = checkSudokuSquare(sudokuSquareOne);
	printf("Dieser Sudokulösungsversuch 1 ist (0 = falsch, 1 = richtig): %d\n", result);
    result = checkSudokuSquare(sudokuSquareTwo);
    printf("Dieser Sudokulösungsversuch 2 ist (0 = falsch, 1 = richtig): %d\n", result);
    result = checkSudokuSquare(sudokuSquareThree);
    printf("Dieser Sudokulösungsversuch 3 ist (0 = falsch, 1 = richtig): %d\n", result);
	return 0;
}
