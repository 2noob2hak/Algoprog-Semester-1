#include <stdio.h>
#include <string.h>

typedef struct {
    char ID[15];
    char name[20];
    int score;
} data;

int main(void) {
    int N = 0;
    scanf("%d", &N); getchar();
    data avg[N];

    long long sum = 0;
    for (int i = 0; i < N; i++) {
        scanf("%10s", avg[i].ID); 
        while(getchar() != '\n');
        fgets(avg[i].name, 20, stdin);
        avg[i].name[strcspn(avg[i].name, "\n")] = '\0';
        scanf("%d", &avg[i].score); getchar();
        sum += avg[i].score;
    }

    double average = (double)sum / N;
    for (int i = 0; i < N; i++) {
        if (avg[i].score >= average) {
            printf("%s", avg[i].ID);
            printf(" %s\n", avg[i].name);
        }
        else continue;
    }

    return 0;
}
