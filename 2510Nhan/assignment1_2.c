#include <stdio.h>
#include <string.h>

#define MAX_WORD_LENGTH 20
#define MAX_NUMBER_OF_WORDS 100
#define SPACE ' '

void printWordAndSpaces(char word[MAX_WORD_LENGTH], int numberOfSpaceInBetweenWord, int *numberOfExtraSpace) {
    while(numberOfSpaceInBetweenWord--) {
        printf("%c", SPACE);
    }
    if (*numberOfExtraSpace > 0) {
        printf("%c", SPACE);
        *numberOfExtraSpace -= 1;
    }
    printf("%s", word);
}

int getTotalWordsLengthByIndex(char tokens[MAX_NUMBER_OF_WORDS][MAX_WORD_LENGTH], int startIndex, int stopIndex) {
    int totalWordsLength = 0;
    for (int i = startIndex; i <= stopIndex; i++) {
        totalWordsLength += (int) strlen(tokens[i]);
    }
    return totalWordsLength;
}

void formatAndPrintCurrentLine(char tokens[MAX_NUMBER_OF_WORDS][MAX_WORD_LENGTH], int startIndex, int stopIndex, int lineLength) {
    // Handle the case where last line only have one word
    if (startIndex == stopIndex) {
        printf("%s\n", tokens[startIndex]);
        return;
    }

    int totalWordsLengthInLine = getTotalWordsLengthByIndex(tokens, startIndex, stopIndex);
    int numberOfSpaceInBetweenWord = (lineLength - totalWordsLengthInLine) / (stopIndex - startIndex);
    int numberOfSpaceLeft = lineLength - totalWordsLengthInLine - (stopIndex - startIndex) * numberOfSpaceInBetweenWord;

    printf("%s", tokens[startIndex]);
    for (int i = startIndex + 1; i <= stopIndex; i++) {
        printWordAndSpaces(tokens[i], numberOfSpaceInBetweenWord, &numberOfSpaceLeft);
    }
    printf("\n");
}

int getLastWordIndexForNextLine(char tokens[MAX_NUMBER_OF_WORDS][MAX_WORD_LENGTH], int startIndex, int totalNumberOfWords, int lineLength) {
    int currentLineLength = 0;
    int count = 0;

    for (int i = startIndex; i < totalNumberOfWords; i++) {
        int currentTokenLength = (int) strlen(tokens[i]) + (count > 0 ? 1 : 0); // Reserve for at least one space

        if (currentLineLength + currentTokenLength > lineLength) {
            return startIndex + count - 1;
        } else {
            currentLineLength += currentTokenLength;
            count++;
        }
    }

    return startIndex + count - 1;
}

int tokenize(char *paragraph, char tokens[MAX_NUMBER_OF_WORDS][MAX_WORD_LENGTH]) {
    int currentIndex = 0;
    while (currentIndex < MAX_NUMBER_OF_WORDS) {
        *tokens[currentIndex++] = 0;
    }

    currentIndex = 0;
    while(*paragraph) {
        if (*paragraph != SPACE) {
            strncat(tokens[currentIndex], paragraph, 1);
        } else if (*tokens[currentIndex]) {
            currentIndex++;
        }
        paragraph++;
    }

    return currentIndex + (*tokens[currentIndex] ? 1 : 0);
}

void formatAndPrintParagraph(char *paragraph, int lineLength) {
    char tokens[MAX_NUMBER_OF_WORDS][MAX_WORD_LENGTH];
    int numberOfWords = tokenize(paragraph, tokens);

    int startIndex = 0;
    while(startIndex < MAX_NUMBER_OF_WORDS && *tokens[startIndex]) {
        int stopIndex = getLastWordIndexForNextLine(tokens, startIndex, numberOfWords, lineLength);
        formatAndPrintCurrentLine(tokens, startIndex, stopIndex, lineLength);
        startIndex = stopIndex + 1;
    }
};

int main() {
    char *paragraph = "         Hi everyone. This is          the 2nd assignment. "
                       "Please make sure you start early as this is going to take some time!  ";
    char tokens[MAX_NUMBER_OF_WORDS][MAX_WORD_LENGTH];
    int numberOfTokens = tokenize(paragraph, tokens);
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