#include <stdio.h>
#include <string.h>
#include <assert.h>

#define MAX_WORD_LENGTH 20
#define MAX_NUMBER_OF_WORDS 100

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
}

int getNumberOfWordsForNextLine(char tokens[MAX_NUMBER_OF_WORDS][MAX_WORD_LENGTH],
                                int numberOfWordsProcessedSoFar,
                                int totalNumberOfWords,
                                int lineLength) {
    int numberOfWordsForNextLine = 0;
    int lineCapacityRemaining = lineLength;
    for (int currentWordIndex = numberOfWordsProcessedSoFar; currentWordIndex < totalNumberOfWords; currentWordIndex++) {
        if (getCurrentTokenSize(tokens[currentWordIndex]) <= lineCapacityRemaining) {
            lineCapacityRemaining -= (getCurrentTokenSize(tokens[currentWordIndex]) + 1);
            numberOfWordsForNextLine++;
        } else {
            // numberOfWordsProcessedSoFar += numberOfWordsForNextLine;
            return numberOfWordsForNextLine;
        }
    }
    return numberOfWordsForNextLine;
}

void printWordAndSpaces(char tokens[MAX_NUMBER_OF_WORDS][MAX_WORD_LENGTH],
                        int numberOfWordsProcessed,
                        int numberOfWordsForNextLine,
                        int numberOfSpacesBetweenWords,
                        int leftOverSpaces) {
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

void formatAndPrintCurrentLine(char tokens[MAX_NUMBER_OF_WORDS][MAX_WORD_LENGTH],
                               int numberOfWordsProcessed,
                               int numberOfWordsForNextLine,
                               int lineLength) {
    int numberOfCharactersWithoutSpaces = 0;
    for (int currentWordIndex = numberOfWordsProcessed; currentWordIndex < numberOfWordsProcessed + numberOfWordsForNextLine; currentWordIndex++) {
        numberOfCharactersWithoutSpaces += (int)strlen(tokens[currentWordIndex]);
    }
    int numberOfSpacesRequired = lineLength - numberOfCharactersWithoutSpaces;
    int numberOfWordsThatNeedSpaces;
    if (numberOfWordsForNextLine - 1 <= 0) {
        numberOfWordsThatNeedSpaces = 1;
    } else {
        numberOfWordsThatNeedSpaces = numberOfWordsForNextLine - 1;
    }
    int numberOfSpacesBetweenWords = numberOfSpacesRequired / (numberOfWordsThatNeedSpaces);   // last word doesn't need a space
    int leftOverSpaces = numberOfSpacesRequired % (numberOfWordsThatNeedSpaces);

    printWordAndSpaces(tokens, numberOfWordsProcessed, numberOfWordsForNextLine, numberOfSpacesBetweenWords, leftOverSpaces);

//    for (int tokenIndex = numberOfWordsProcessed; tokenIndex < numberOfWordsProcessed + numberOfWordsForNextLine ; tokenIndex++) {
//        printf("%s", tokens[tokenIndex]);
//        for (int space = 0; space < numberOfSpacesBetweenWords; space ++) {
//            printf(" ");
//        }
//        if (leftOverSpaces > 0) {
//            printf(" ");
//            leftOverSpaces --;
//        }
//    }
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

//int main(){
//    char *paragraph = "  Hi everyone. This is the 2nd assignment. Please make sure you start early "
//                          "as this is going to take some time!  ";
//    int lineLength = 15;
//    formatAndPrintParagraph(paragraph, lineLength);
//
//    return 0;
//}


int main() {
    char paragraph[] = "         Hi everyone. This is          the 2nd assignment. Please make sure you start early as this is going to take some time!     ";
    char tokens[MAX_NUMBER_OF_WORDS][MAX_WORD_LENGTH];
    int numberOfTokens = tokenize(paragraph, tokens);
    assert(numberOfTokens == 21);
    for (int i = 0; i < numberOfTokens; i++) {
        printf("Token[%d] = %s\n", i, tokens[i]);
    }
    printf("\n");
    formatAndPrintParagraph(paragraph, 15);
    printf("\n");
    formatAndPrintParagraph(paragraph, 25);
    printf("\n");
    formatAndPrintParagraph(paragraph, 35);
    printf("\n");
    formatAndPrintParagraph(paragraph, 100);
    printf("\n");
    formatAndPrintParagraph(paragraph, 120);
    return 0;
}