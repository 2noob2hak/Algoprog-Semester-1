#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char name[45];
    char tree[45];
} data;

int main(void) {
    FILE *fp = fopen("testdata.in", "r");
    if (fp == NULL) {
        puts("unable to open file");
        return 1;
    }
    
    char buffer[100];
    fgets(buffer, 100, fp);
    int N = atoi(buffer);
    data plant[N];

    int count = 0;
    while (fgets(buffer, 100, fp)) {
        sscanf(buffer, "%[^#]#%[^\n]", plant[count].name, plant[count].tree);
        if (count == N - 1) break; // safety net
        count++;
    }

    fgets(buffer, 100, fp);
    int S = atoi(buffer);
    char wanted[S][45];
    count = 0;
    while (fgets(buffer, 45, fp)) {
        sscanf(buffer, "%s", wanted[count]);
        if (count == S - 1) break;
        count++;
    }

    for (int c = 0; c < S; c++) {
        int found = 0;
        for (int i = 0; i < N; i++) {
            if(strcmp(wanted[c], plant[i].name) == 0) {
                printf("Case #%d: %s\n", c + 1, plant[i].tree);
                found = 1;
                break;
            }
        }
        if (found != 1) printf("Case #%d: N/A\n", c + 1);
        else continue;
    }
    fclose(fp);
    return 0;
}