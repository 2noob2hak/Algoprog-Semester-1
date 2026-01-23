// Title: Multiply String
#include <stdio.h>
#include <string.h>
// w/o 2d array
int main(void) {
    char input_arr[505];
    // handling input
    scanf("%[^\n]", input_arr);
    
    int x, index;
    
    scanf("%d", &index);
    scanf("%d", &x);
    
    int word_count = 0, i = 0, j = 0, length = strlen(input_arr);
    char* point[250]; // if you don't want to use array, you can use int instead(to mark the position of '\0')
    // tokenize
    if (length > 0) {
        point[word_count] = &input_arr[0];
        word_count++;
    }

    // replacing ' ' with '\0' (null terminator) and mark the position of the first character after '\0'
    for (int i = 0; i < length - 1; i++) {
        if (input_arr[i] == ' ') {
            input_arr[i] = '\0';
            point[word_count] = &input_arr[i+1];
            word_count++;
        }
        else continue;
    }
    // handling output
    for (int j = 0; j < x; j++) {
        printf("%s", point[index]);
        if (j < x-1) printf(" ");
    }
    printf("\n");
    return 0;
}

/*
NOTE: This code was made after the quiz, meaning I haven't had the chance to actually test it
with OJ systems. if you had the chance to check/use it with OJ and got "WRONG ANSWER", try changing
the array size(e.g. 1005, 1505, etc.).
*/
