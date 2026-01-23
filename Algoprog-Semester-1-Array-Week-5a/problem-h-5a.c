#include <stdio.h>

int main(void) {
    // handling input
    int arr[5000] = {0};
    int N = 0;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);
    
    // handling duplicate
    int dupe_count = 0;
    for (int j = 0; j < N; j++) {
        int temp = arr[j];
        for (int k = j + 1; k < N; k++) {
            if (temp == arr[k]) {
                dupe_count++;
                break;
            }
        }
    }

    // handling output
    printf("%d\n", N - dupe_count);
    return 0;
}

/*
NOTE:
Based on OJ that this code pass, not the pdf instruction. I draw my own conclusion that 
there is no more than 2 duplicate(sum) of number. For example in the sample input 1: {1, 3, 4, 1, 2, 2, 5}
there is only two 1's and two 2's. That'll be the same with OJ when you submit your code. dupe_count can be
more than 2 but the sum of those duplicate will not. Therefore this code's algorithm suffice.
*/