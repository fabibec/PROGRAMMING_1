#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void getUserWord (char **buffer, int *length);
void checkScrabbleScore(char word[], int *score);

int main (void) {
    //Get word from user
    char *wordbuffer = NULL;
    int len = 0;
    getUserWord(&wordbuffer, &len);
    //Copy word from char* into char[] and free allocated memory
    char word[len];
    strcpy(word, wordbuffer);
    free(wordbuffer);
    //Calculate Score
    int score = 0;
    checkScrabbleScore(word, &score);
    printf("Score: %d", score);
    return 0;
}
/**
 * Allows the user to enter a string of a flexible length
 * Return the String in the format of char* and the length of the string including the \0 character
 * @param word char pointer where the string will be saved
 * @param length variable where the link will be saved
 */
void getUserWord (char **buffer, int *length) {
    int read;
    unsigned int len;
    printf("Bitte geben Sie ein Wort ein: ");
    printf("\n");
    read = getline(&*buffer, &len, stdin);
    *length = read;
}

/**
 *
 * @param word the word whose score should be calculated
 * @param length
 */
void checkScrabbleScore(char word[], int *score) {
    *score = 0;
    int i = 0;
    int letter_score[] = {1,3,3,2,1,4,2,4,1,8,5,1,3,1,1,3,
                    10,1,1,1,1,4,4,8,4,10};
    while (word[i] != '\0') {
        //Uppercase all chars
        if (word[i] >= 97 && word[i] <= 122) {
            word[i] -= 32;
        }
        //Calculate Score
        if (word[i] >= 65 && word[i] <= 90) {
            *score = *score + letter_score[word[i] - 65];
        }
        i++;
    }
}