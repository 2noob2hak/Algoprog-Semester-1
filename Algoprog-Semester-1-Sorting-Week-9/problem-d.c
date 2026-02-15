#include <stdio.h>

#define SIZE 25

int main(void) {
    // handling input
    int T = 0;
    scanf("%d", &T);

    for (int tc = 1; tc <= T; tc++) {
        int arr[25];
        for (int i = 0; i < SIZE; i++) {
            scanf("%d", &arr[i]);
        }

        // sorting(ascend horizontally l to r)
        for (int i = 0; i < SIZE; i++) {
            for (int j = i + 1; j < SIZE; j++) {
                if (arr[i] > arr[j]) {
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }

        // process
        int guess[5] = {0};
        int mark[25] = {0};
        guess[0] = arr[0] / 2;
        mark[0] = 1;

        for (int i = 1; i < 5; i++) {
            // getting the next smallest sum
            int smallest_sum = 0;
            for (int j = 0; j < SIZE; j++) {
                if (mark[j] == 0) {
                    smallest_sum = arr[j];
                    mark[j] = 1;
                    break;
                }
            }

            // calculate the now guess
            guess[i] = smallest_sum - guess[0];

            // mark handshakes(a + b & b + a);
            int check = 0;
            for (int j = 0; j < i; j++){
                int handshake = guess[j] + guess[i];
                int copy_needed = (j == 0) ? 1 : 2;
                int count = 0;
                for (int k = 0; k < SIZE; k++) {
                    if (mark[k] == 0 && arr[k] == handshake) {
                        mark[k] = 1;
                        count++;
                        if (count == copy_needed) break;
                    }
                }
            }

            // mark self sum
            int self_sum = guess[i] * 2;
            for (int j = 0; j < SIZE; j++) {
                if (mark[j] == 0 && arr[j] == self_sum) {
                    mark[j] = 1;
                    break; // only remove one
                }
            }
        }
        
        // handling output
        printf("Case #%d:", tc);
        for (int i = 0; i < 5; i++) {
            printf(" %d", guess[i]);
        }
        printf("\n");
    }
}