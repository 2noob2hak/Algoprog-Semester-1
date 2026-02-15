#include <stdio.h>
#include <string.h>

typedef struct {
    char title[1005];
    char name[1005];
    int views;
} dat;

int main(void) {
    FILE *fp = fopen("testdata.in", "r");
    if (fp == NULL) {
        return 1;
    }

    dat data[105];
    
    char buffer[2100];
    int count = 0;

    while (fscanf(fp, " %[^#]#%[^#]#%d", data[count].title, data[count].name, &data[count].views) == 3) {
        if (count < 100)
        count++;    
    }
        
    // sort 1: title(ascend)
    dat temp;
    for (int i = 0; i < count; i++) {
        for (int j = i + 1; j < count; j++) {
            if (strcmp(data[i].title, data[j].title) > 0) {
                temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
        }
    }

    // sort 2: views(descend)
    for (int i = 0; i < count; i++) {
        for (int j = i + 1; j < count; j++) {
            if (data[i].views < data[j].views) {
                temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
        }
    }
    

    for (int i = 0; i < count; i++) {
        // printf("%d\n", arr_sorted[i]);
        printf("%s by %s - %d\n", data[i].title, data[i].name, data[i].views);
    }
    return 0;
}