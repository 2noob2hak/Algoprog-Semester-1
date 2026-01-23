#include <stdio.h>

int moveX[] = {2, 1, 1, 2, -1, -2, -2, -1};
int moveY[] = {1, 2, -2, -1, 2, 1, -1, -2};

int min_step = 100;

void knight(int idx_pos1, int idx_pos2, int idx_des1, int idx_des2, int step) {
    if (step >= min_step || step > 6) // safety net: if step is bigger than min_step, don't use it + break || if step is bigger than 6(based on hint) break
        return;

    if (idx_pos1 == idx_des1 && idx_pos2 == idx_des2) { // if they reach the destination then stop
        min_step = step;
        return;
    }

    for (int i = 0; i < 8; i++) {
        int nextX = idx_pos1 + moveX[i];
        int nextY = idx_pos2 + moveY[i];

        if (nextX >= 0 && nextX < 8 && nextY >= 0 && nextY < 8) // the nextX < 8 because we have make it zero based.
            knight(nextX, nextY, idx_des1, idx_des2, step + 1);
    }   
}

int main (void) {
    int T = 0;
    scanf("%d", &T); getchar();

    for (int tc = 1; tc <= T; tc++) {
        int idx_pos1 = 0, idx_pos2 = 0, idx_des1 = 0, idx_des2 = 0;
        char temp[2];
        scanf("%c%d %c%d", &temp[0], &idx_pos2, &temp[1], &idx_des2); getchar();

        //translating from char to number
        idx_pos1 = temp[0] - 'A';
        idx_des1 = temp[1] - 'A';

        min_step = 100;
        knight(idx_pos1, idx_pos2 - 1, idx_des1, idx_des2 - 1, 0); // the - 1 is for 0-based

        printf("Case #%d: %d\n", tc, min_step);
    }
    return 0;
}