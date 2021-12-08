#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char *append(char *data[], int count) {
    size_t totalSize = 0;
    for(int i = 0; i < count; i++) {
        totalSize += strlen(data[i]);
    }

    char *result  = malloc(totalSize + 1);
    if (*result == NULL) {
        perror("memory error");
        exit(1);
    }
    *result = 0;                                    // set it all to 0, malloc doesn't guarantee all 0s


    for(int i = 0; i < count; i++) {
        strcat(result, data[i]);
    }
    return result;
}

int main() {
    char *stringList[] = {"Hello", "World", "I", "MoreThanWelcomeHere"};
    char *result = append(stringList, 4);
    printf("%s\n", result);
    free(result);
    printf("%s\n", result);
    return 0;
}