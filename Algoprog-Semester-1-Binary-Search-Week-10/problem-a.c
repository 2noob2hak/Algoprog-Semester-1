#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct data {
    char name[260];
    int score;
};

int bin_search (struct data list[], char* target, int left, int right) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int result = strcmp(list[mid].name, target);
        if (result == 0) 
            return mid;
        else if (result < 0)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int main(void) {
    int t;
    scanf("%d", &t); getchar();
    struct data list[t];

    // players list and score input
    for (int i = 0; i < t; i++) {
        scanf("%255s %d", list[i].name, &list[i].score);
        while(getchar() != '\n');
    }

    int m;
    scanf("%d", &m); getchar();
    for (int i = 0; i < m; i++) {
        char player1[260], player2[260];
        // input player 1 and 2
        scanf("%255s %255s", player1, player2);

        int in1 = bin_search(list, player1, 0, t-1), in2 = bin_search(list, player2, 0, t-1);
        if (in1 == -1 || in2 == -1) puts("not found");
        else if (in1 == in2) puts("not valid");
        else {
            int score_gap, rank_gap;
            score_gap = abs(list[in1].score - list[in2].score);
            rank_gap = abs(in1 - in2);
            printf("%d %d\n", score_gap, rank_gap);
        }
    }
    return 0;
}