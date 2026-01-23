// Title: Multiply String
#include <stdio.h>
#include <string.h>
// with 2d array
int main(void) {
    char input_arr[505];
    // handling input
    scanf("%[^\n]", input_arr);
    
    int x, index;
    
    scanf("%d", &index);
    scanf("%d", &x);
    
    int null_count = 0, i = 0, j = 0, length = strlen(input_arr);

    // replacing ' ' with '\0' (null terminator) and mark the position of the first character after '\0'
    for (int i = 0; i < length - 1; i++) {
        if (input_arr[i] == ' ') {
            input_arr[i] = '\0';
            null_count++;
        }
        else continue;
    }

    char sorted_arr[null_count + 1][length];
    int k = 0, l = 0;
    // tokenize
    for (int j=0; j < null_count + 1; j++) {
        while (l<=length) {
            if (input_arr[l] != '\0') {
                sorted_arr[j][k] = input_arr[l];
                k++;
                l++;                
            }
            else {
                sorted_arr[j][k] = '\0';
                k=0;
                l++;
                break;
            }
        }
    }
    
    // handling output
    for (int k = 0; k < x; k++) {
        printf("%s", sorted_arr[index]);
        if (k < x-1) printf(" ");
    }

    printf("\n");
    return 0;
}

/*
NOTE: This code was made after the quiz, meaning I haven't had the chance to actually test it
with OJ systems. if you had the chance to check/use it with OJ and got "WRONG ANSWER", try changing
the array size(e.g. 1005, 1505, etc.).
*/
