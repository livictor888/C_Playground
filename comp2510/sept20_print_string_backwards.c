#include <stdio.h>

//prints a given string backwards
void mystery(char *string) {

    //check if the string is empty, an empty string is a valid string
    if (!*string) {
        return;
    }

    char *beginning = string;

    // looks ahead +1 to check if there's a character there, move the pointer, moves to the last character
    // the last value in the string is /0
    while (*(string+1)) {
        string++;
    }

    // while the current character is not the first character, print out the character and move the pointer
    // towards the front
    while ((string + 1) != beginning) {
        printf("%c", *string--); //after the last loop the point will be out of index range : -1
                                        //you must code around this to avoid it
    }
}

int main() {
    char *testString = "Hello";
    mystery(testString);
    return 0;
}
