#include <stdio.h>

int main(void) {
    int T;
    scanf("%d", &T);

    for (int tc=1; tc<=T; tc++) {
        int N;
        scanf("%d", &N);
        int arr[N]; 
        
        for (int i=0; i<N; i++)
            scanf("%d", &arr[i]);

        for (int i=0; i<N; i++) {
            // sorting from lowest to highest
            for (int j=0; j<N-i-1; j++) {
                if (arr[j] > arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
            }
        }
        // compute the cool factor
        int cool_count = 0;
        for (int i = 0; i<N; i++) {
            int left = 0, right = N - 1, found = 0;
            while (left < right) {
                if (left == i) {left++; continue;}
                if (right == i) {right--; continue;}
                int sum = arr[left] + arr[right];
                if (sum == arr[i]) {
                    found = 1;
                    break;
                }
                else if (sum < arr[i])
                    left++;
                else 
                    right--;
            }
            if (found) cool_count++;
        }
        printf("Case #%d: %d\n", tc, cool_count);
    } 
    return 0;
}