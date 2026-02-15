// solution 1: divided by string and nums

#include <stdio.h>

int main(void) {
    FILE *fp = fopen("testdata.in", "r");
    if (fp == NULL) {
        // puts("Error: unable to read file");
        return 1;
    }

    int N = 0;
    char buffer[115];
    if (fgets(buffer, 105, fp) != NULL) // getting the first line info
        sscanf(buffer, "%d", &N);
    char name[N][25];
    long long ID[N];
    
    int count = 0;
    while(fgets(buffer, 105, fp)) {
        sscanf(buffer, "%lld %s", &ID[count], name[count]);

        if (count == N - 1) break;
        count++;
    }

    int S = 0;
    if (fgets(buffer, 15, fp) != NULL)  // getting the wanted size
        sscanf(buffer, "%d", &S);
    
    long long wanted[S];
    count = 0;
    while(fgets(buffer, 105, fp)) {
        sscanf(buffer, "%lld", &wanted[count]);
        if (count == S - 1) break;
        count++;
    }

    for (int i = 0; i < S; i++) {
        int found = 0;
        for (int j = 0; j < N; j++) {
            if (wanted[i] == ID[j]) {
                printf("Case #%d: %s\n", i + 1, name[j]);
                found++;
                break;
            }
        }
        if (found == 0)
            printf("Case #%d: N/A\n", i + 1);
    }
    fclose(fp);
    return 0;
}