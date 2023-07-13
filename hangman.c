#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ATTEMPTS 6
#define MAX_WORD_LENGTH 20

int main(){
    int i, j, found;
    int attempts = 0;
    int wordLength;
    int correctGuesses = 0;
    char word[MAX_WORD_LENGTH];
    char guessed[MAX_WORD_LENGTH];
    char guess;

    printf("Welcome to Arthur's Hangman :) !\n");
    printf("Input the word to be guessed (up to %d characters): ", MAX_WORD_LENGTH);
    fgets(word, sizeof(word), stdin);

    wordLength = strlen(word) - 1;
    word[wordLength] = '\0';

    for (i=0; i < wordLength; i++) {
        guessed[i] = '_';
    }

    while (attempts < MAX_ATTEMPTS && correctGuesses < wordLength){
        printf("\nCurrent word: ");
        for (i = 0; i < wordLength; i++){
            printf("%c ", guessed[i]);
        }

        printf("\nAttempts remaining: %d\n", MAX_ATTEMPTS - attempts);
        printf("Enter a letter: ");
        scanf(" %c", &guess);
        guess = tolower(guess);

        found = 0;
        for (i=0; i < wordLength; i++){
        if (word[i] == guess && guessed[i] == '_'){
            guessed[i] = guess;
            correctGuesses++;
            found = 1;
        }
    }

    if (!found){
        attempts++;
        printf("WRONG!! Try better next time LOSER!!\n");
    }
}

    if (attempts == MAX_ATTEMPTS) {
        printf("\nMan you really suck at this. The word was %s\n", word);
    } else {
        printf("\n Sheeshhh that boy the GOAT for guessing the word: %s\n", word);
    }
    return 0;
}

