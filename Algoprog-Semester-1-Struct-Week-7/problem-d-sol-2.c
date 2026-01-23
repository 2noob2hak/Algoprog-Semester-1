#include <stdio.h>
#include <string.h>

typedef struct {
    char code[10];
    char name[105];
    int credits;
} data;

int main(void) {
    int N = 0;
    scanf("%d", &N); getchar();
    data db[N];
    for (int i = 0; i < N; i++) {
        scanf("%s", db[i].code); 
        while(getchar() != '\n');
        fgets(db[i].name, 105, stdin);
        db[i].name[strcspn(db[i].name, "\n")] = '\0';
        scanf("%d", &db[i].credits);
        while(getchar() != '\n');
    }

    int Q;
    scanf("%d", &Q);
    int q_arr[Q];
    for (int i = 0; i < Q; i++) {
        int temp = 0;
        scanf("%d", &temp);
        temp -= 1; // translating to base 0;
        printf("Query #%d:\n", i + 1);
        printf("Code: %s\n", db[temp].code);
        printf("Name: %s\n", db[temp].name);
        printf("Credits: %d\n", db[temp].credits);
    }

    return 0;
}