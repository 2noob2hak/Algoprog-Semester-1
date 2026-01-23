// THIS SOLUTION IS USING A TRADITIONAL/SIMPLER METHOD

#include <stdio.h>

struct {
    char name[200][15];
    int student_count; // total students of the group
} data[20];

int main(void) {
    int T;
    scanf("%d", &T);

    for (int tc = 1; tc <= T; tc++) {
        int N;
        scanf("%d", &N); 

        for (int i = 0; i < 20; i++)
            data[i].student_count = 0;


        for (int i = 0; i < N; i++) {
            char arr[15];
            int temp;
            scanf("%10s %d", arr, &temp);
            temp -= 1; // making it 0-based
            snprintf(data[temp].name[data[temp].student_count], 15, "%s", arr);
            data[temp].student_count++;
        }

        printf("Case #%d:\n", tc);
        for (int i = 0; i < 20; i++) {
            if (data[i].student_count > 0) {
                printf("Group %d(%d):\n", i + 1, data[i].student_count);
                for (int j = 0; j < data[i].student_count; j++)
                    printf("%s\n", data[i].name[j]);
            }
        }
    }
    return 0;
}