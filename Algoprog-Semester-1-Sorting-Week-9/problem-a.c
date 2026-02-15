#include <stdio.h>
#include <string.h>

int main(void) {
    // handling input
    int a = 0, b = 0;
    scanf("%d %d", &a, &b);
    char arr[a][b + 1];
    for (int i = 0; i < a; i++) {
        scanf("%s", arr[i]);
    }

    // first sort(horizontally per char)
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            for (int k = j + 1; k < b; k++) {
                if (arr[i][j] > arr[i][k]) {
                    char temp = arr[i][j];
                    arr[i][j] = arr[i][k];
                    arr[i][k] = temp;
                }

                else continue;
            }
        }
    }

    // second sort(vertically per string)
    for (int i = 0; i < a; i++) {
        for (int j = i + 1; j < a; j++) {
            if (strcmp(arr[i], arr[j]) < 0) {
                char temp[b + 1];
                strcpy(temp, arr[i]);
                strcpy(arr[i], arr[j]);
                strcpy(arr[j], temp);
            }
        }
    }

    // handling output
    for (int i = 0; i < a; i++) {
        printf("%s\n", arr[i]);
    }
    return 0;
}