#include <stdio.h>

int main(void) {
    int in = 0;
    scanf("%d", &in);
    int arr[in];
    for (int i = 0; i < in; i++) {
        scanf("%d", &arr[i]);
    }

    // sort
   int temp[in];

    // size = 1, 2, 4, 8, ...
    for (int size = 1; size < in; size *= 2) {
        for (int left = 0; left < in - size; left += 2 * size) {

            int mid = left + size - 1;
            int right = left + 2 * size - 1;
            if (right >= in) right = in - 1;

            // merge arr[left..mid] & arr[mid+1..right]
            int i = left;
            int j = mid + 1;
            int k = left;

            while (i <= mid && j <= right) {
                if (arr[i] <= arr[j]) temp[k++] = arr[i++];
                else temp[k++] = arr[j++];
            }
            while (i <= mid) temp[k++] = arr[i++];
            while (j <= right) temp[k++] = arr[j++];

            // copy back
            for (int x = left; x <= right; x++)
                arr[x] = temp[x];
        }
    }

    // find max diff
    int max_diff = arr[1] - arr[0];
    if (max_diff < 0) max_diff = -max_diff;

    for (int x = 0; x < in - 1; x++) {
        int diff = arr[x + 1] - arr[x];
        if (diff < 0) diff = -diff;
        if (diff > max_diff) max_diff = diff;
    }

    // output pairs w max diff
    int space = 1;
    for (int y = 0; y < in - 1; y++) {
        int diff = arr[y + 1] - arr[y];
        if (diff < 0) diff = -diff;
        if (diff == max_diff) {
            if (!space) printf(" ");
            printf("%d %d", arr[y], arr[y+1]);
            space = 0;
        }
    }
    printf("\n");
    return 0;
}