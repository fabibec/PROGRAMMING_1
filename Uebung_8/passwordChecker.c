#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void removeNewlines(char word[]);
int checkPassword(char word[]);

int main (void) {
    //Get String for User and remove \n
    char *input = NULL;
    int length;
    unsigned int buffer;
    printf("Willkommen zum Passwortchecker.\nBitte Passwort eingeben:");
    length = getline(&input, &buffer, stdin);
    char password[length];
    strcpy(password,input);
    removeNewlines(password);
    free(input);
    //Check Safety
    int isSafe = checkPassword(password);
    return (isSafe) ? printf("OK - Passwort sicher.") : printf("Achtung - Passwort unsicher.");
}

//Replaces \n Character with \ß
void removeNewlines(char word[]) {
    int i = -1;
    while(word[++i] != '\n');
    word[i] = '\0';
}

int checkPassword(char word[]) {
    int numbers = 0;
    int upper_letters = 0;
    int lower_letters = 0;
    int special_characters = 0;
    int i = -1;
    while(word[++i] != '\0') {
        //Check for uppercase letters
        if(word[i] >= 65 && word[i] <= 90) {
            upper_letters++;
            goto CHECK;
        }
        //Check for lowercase letters
        if(word[i] >= 97 && word[i] <= 122) {
            lower_letters++;
            goto CHECK;
        }
        //Check for numbers
        if(word[i] >= 48 && word[i] <= 57) {
            numbers++;
            goto CHECK;
        }
        //special characters
        special_characters++;
        //stop as soon as password is safe
        CHECK:if (special_characters >= 1 && numbers >= 2 && upper_letters >= 1 && lower_letters >= 1 && i >= 7)
            return 1;
    }
    return 0;
}