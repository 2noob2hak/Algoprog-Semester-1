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
                
        int cool_count = 0;

        for (int i = 0; i < N; i++) {
            int found = 0; // to avoid duplicates(marking)
            for (int j = 0; j < N && !found; j++) {
                for (int k = j + 1; k < N; k++) {
                    if (i != j && i != k && arr[i] == arr[j] + arr[k]) {
                        found =  1;
                        break;
                    }
                }
            }
            if (found) cool_count++;
        }
        printf("Case #%d: %d\n", tc, cool_count);
    } 
    return 0;
}