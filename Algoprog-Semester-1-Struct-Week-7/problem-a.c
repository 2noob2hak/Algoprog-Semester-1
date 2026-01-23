#include <stdio.h> 
#include <string.h>

int main(void) {
    int N;
    scanf("%d", &N); getchar();

    struct {
    char ID[25];
    char Name[105];
    int Age;
    } data[N];

    for (int i = 0; i < N; i++) {
        scanf("%20s", data[i].ID); getchar();
        fgets(data[i].Name, 105, stdin);
        data[i].Name[strcspn(data[i].Name, "\n")] = '\0';
        scanf("%d", &data[i].Age); getchar();
    }

    int Q;
    scanf("%d", &Q); getchar();
    for (int query = 1; query <= Q; query++) {
        int temp = 0;
        scanf("%d", &temp); getchar();
        printf("Query #%d:\n", query);
        printf("ID: %s\n", data[temp-1].ID);
        printf("Name: %s\n", data[temp-1].Name);
        printf("Age: %d\n", data[temp-1].Age);
    }
    return 0;
}