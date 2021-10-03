#include <stdio.h>
#include <string.h>

#define MAX_WORD_LENGTH 20
#define MAX_NUMBER_OF_WORDS 100

//char moveToBeginningOfNextToken(char *inputString) {
//    for (int index = 0; index < strlen(inputString); index ++) {
//        if (*inputString != ' ') {
//            return 0;
//        } else {
//            inputString++;
//        }
//    }
//}

int getCurrentTokenSize(char *inputString) {
    int tokenSize = 0;
    for (int index = 0; index < strlen(inputString); index++ ) {
        if (*(inputString + index) != ' ') {
            tokenSize++;
        } else {
            return tokenSize;
        }
    }
    return tokenSize;
}

int tokenize(char *paragraph, char tokens[MAX_NUMBER_OF_WORDS][MAX_WORD_LENGTH]) {
    for (int index = 0; index < MAX_NUMBER_OF_WORDS; index++) {
        *tokens[index] = 0;
    }

    int currentTokenIndex = 0;
    for (int charIndex = 0; charIndex < strlen(paragraph); charIndex++) {
        if (*(paragraph + charIndex) != ' ') {
            strncat(tokens[currentTokenIndex], paragraph + charIndex, 1);
        } else if (*tokens[currentTokenIndex] != 0) {
            currentTokenIndex++;
        }
    }
    return (*tokens[currentTokenIndex] == 0)? currentTokenIndex: currentTokenIndex + 1;
//    if (*tokens[currentTokenIndex] == 0) {
//        return currentTokenIndex;
//    }
//    return currentTokenIndex + 1;
}

int getNumberOfWordsForNextLine(char tokens[MAX_NUMBER_OF_WORDS][MAX_WORD_LENGTH],
                                int numberOfWordsProcessedSoFar,
                                int totalNumberOfWords,
                                int lineLength) {
    int numberOfWordsForNextLine = 0;
    int lineCapacityRemaining = lineLength;
    for (int word = numberOfWordsProcessedSoFar; word < totalNumberOfWords; word++) {
        if (getCurrentTokenSize(tokens[word]) <= lineCapacityRemaining) {
            lineCapacityRemaining -= (getCurrentTokenSize(tokens[word]) + 1);
            numberOfWordsForNextLine++;
        } else {
            numberOfWordsProcessedSoFar += numberOfWordsForNextLine;
            return numberOfWordsForNextLine;
        }
    }
    return numberOfWordsForNextLine;
}

//int getNumberOfTokens(char tokens[MAX_NUMBER_OF_WORDS][MAX_WORD_LENGTH]) {
//    int numberOfWords = 0;
//    for (int index = 0; index < MAX_NUMBER_OF_WORDS; index++) {
//        if (*tokens[index] != 0) {
//            numberOfWords++;
//        }
//    }
//    return numberOfWords;
//};

void printWordAndSpaces(char *word, int numberOfSpaces) {
    printf("%s", word);
    for (int spaceNumber = 0; spaceNumber < numberOfSpaces; spaceNumber++) {
        printf(" ");
    }
}

void formatAndPrintCurrentLine(char tokens[MAX_NUMBER_OF_WORDS][MAX_WORD_LENGTH],
                               int numberOfWordsProcessed,
                               int numberOfWordsForNextLine,
                               int lineLength) {
    int numberOfCharactersWithoutSpaces = 0;
    for (int i = numberOfWordsProcessed; i < numberOfWordsProcessed + numberOfWordsForNextLine; i++) {
        numberOfCharactersWithoutSpaces += (int)strlen(tokens[i]);
    }
    int numberOfSpacesRequired = lineLength - numberOfCharactersWithoutSpaces;
    int numberOfSpacesBetweenWords = numberOfSpacesRequired / (numberOfWordsForNextLine - 1);   // last word doesn't need a space
    int leftOverSpaces = numberOfSpacesRequired % (numberOfWordsForNextLine - 1);


    //printWordAndSpaces(word, numberOfSpaces);
    int lastWordOnThisLineIndex = numberOfWordsProcessed + numberOfWordsForNextLine;


    for (int tokenIndex = numberOfWordsProcessed; tokenIndex < numberOfWordsProcessed + numberOfWordsForNextLine ; tokenIndex++) {
        printf("%s", tokens[tokenIndex]);
        for (int space = 0; space < numberOfSpacesBetweenWords; space ++) {
            printf(" ");
        }
        if (leftOverSpaces > 0) {
            printf(" ");
            leftOverSpaces --;
        }

    }
}

void formatAndPrintParagraph(char *paragraph, int lineLength) {
    char tokens[MAX_NUMBER_OF_WORDS][MAX_WORD_LENGTH];
    int totalNumberOfWords = tokenize(paragraph, tokens);
    int numberOfWordsProcessed = 0;
    //int numberOfWordsForNextLine;

    while (numberOfWordsProcessed < totalNumberOfWords) {
        int numberOfWordsForNextLine = getNumberOfWordsForNextLine(tokens, numberOfWordsProcessed, totalNumberOfWords, lineLength);

        //printf("%d\n", numberOfWordsProcessed);
        formatAndPrintCurrentLine(tokens, numberOfWordsProcessed, numberOfWordsForNextLine, lineLength);
        numberOfWordsProcessed += numberOfWordsForNextLine;
        printf("\n");

    }
}

int main(){
//    char *moveToBeginningOfNextTokenTestString = "   hi   there";
//    moveToBeginningOfNextToken(moveToBeginningOfNextTokenTestString);
//    getCurrentTokenSize(moveToBeginningOfNextTokenTestString);

    char *paragraph = "Hi everyone. This is the 2nd assignment. Please make sure you start early "
                          "as this is going to take some time!";
    int lineLength = 40;
    formatAndPrintParagraph(paragraph, lineLength);
//    char tokens[MAX_NUMBER_OF_WORDS][MAX_WORD_LENGTH];
//    int totalNumberOfWords = tokenize(paragraph, tokens);
//    int numberOfWordsProcessed = 0;

//    while (numberOfWordsProcessed < totalNumberOfWords) {
//        numberOfWordsProcessed += getNumberOfWordsForNextLine(tokens, numberOfWordsProcessed, totalNumberOfWords, 20);
//        printf("%d\n", numberOfWordsProcessed);
//
//    }
    return 0;
}