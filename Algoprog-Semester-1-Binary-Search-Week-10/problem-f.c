#include <stdio.h>
#include <string.h>

void merge(int arr[], int l, int m, int r) {
    int left_length = m - l + 1;
    int right_length = r - m;

    int temp_left[left_length];
    int temp_right[right_length];

    // copying data
    for (int i = 0; i < left_length; i++) 
        temp_left[i] = arr[l + i];
    for (int i = 0; i < right_length; i++) 
        temp_right[i] = arr[m + 1 + i];
    
    int i = 0, j = 0, k = l;
    while (k <= r) {
        if(i < left_length && (j >= right_length || temp_left[i] <= temp_right[j])) { // the j >= right_length means the temp_right array is empty so the right side condition of OR never been checked and force it to use the left arr
            arr[k] = temp_left[i];
            i++;
        }
        else {
            arr[k] = temp_right[j];
            j++;
        }  
        k++;
    }
}

void merge_sort(int arr[], int length, int L, int R) {
    if (L < R) {
        int M = (L + (R - L)) / 2;

        // split left
        merge_sort(arr, length, L, M);
        // split right
        merge_sort(arr, length, M + 1, R);
    
        merge(arr, L, M, R);
    }
}

int binary_search(int arr[], int len, long long target) {
    int mark_arr[len], count = 0;
    memset(mark_arr, 0, sizeof(mark_arr));

    for (int i = 0; i < len; i++) {
        if (arr[i] < target) {
            int pair1 = arr[i];
            int pair2 = target - pair1;
            
            int l = 0, r = len - 1;
            while (l <= r) {
                int mid = (l + (r - l)) / 2;
                
                if (mark_arr[mid] != i && pair2 == mid){
                    pair2 = arr[mid];
                    mark_arr[i] = i;
                    count++;
                    break;
                }
                
                else if (pair2 > mid)
                    l = mid++;

                else if (pair2 < mid)
                    r = mid--;
            }
        }
        else continue;
    }
    return count;
}

int main(void) {
    int T;
    scanf("%d", &T);
    for (int tc = 0; tc < T; tc++) {
        int N;
        long long M;
        scanf("%d %lld", &N, &M);
        
        int arr[N];
        for (int i = 0; i < N; i++)
            scanf("%d", &arr[i]);

        merge_sort(arr, N, 0, N - 1);

        printf("Case #%d: %d", tc, binary_search(arr, N, M));
    }
    return 0;
}