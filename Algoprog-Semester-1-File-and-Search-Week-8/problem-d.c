// solution 1: using a bit advance string.h (strtok and strcat)
#include <stdio.h>
#include <string.h>

int main(void) {
    FILE *fp = fopen("testdata.in", "r");
    if (fp == NULL) {
        return 1;
    }

    // handling input
    int T = 0;
    char buffer[105] = {0};
    fgets(buffer, 105, fp);
    sscanf(buffer, "%d", &T);

    struct {
        char short_string[55];
        char og_string[55];
    } data[T];

    int count = 0;
    while(fgets(buffer, 105, fp)) {
        sscanf(buffer, "%[^#]#%s", data[count].short_string, data[count].og_string);
        if (count == T - 1) break;
        count++;
    }

    int TC = 0;
    fgets(buffer, 105, fp);
    sscanf(buffer, "%d", &TC);
    char arr_wanted[TC][105];

    count = 0;
    while(fgets(buffer, 105, fp)) {
        sscanf(buffer, "%[^\n]", arr_wanted[count]);
        if (count == TC - 1) break;
        count++;
    }
    
    // handling output
    for (int i = 0; i < TC; i++) {
        char temp_replace[205] = "";
        char *token = strtok(arr_wanted[i], " ");
        while (token != NULL) {
            int found = 0;
            for (int j = 0; j < T; j++) {
                if (strcmp(token, data[j].short_string) == 0) {
                    strcat(temp_replace, data[j].og_string);
                    found = 1;
                    break;
                }
                else continue;
            } 
            if (found != 1)
                strcat(temp_replace, token);

                strcat(temp_replace, " "); // can't forget the space for each word
                token = strtok(NULL, " "); // continue from NULL/last position(" " + 1)
            }
            int len = strlen(temp_replace);
            if (temp_replace[len - 1] == ' ')
                temp_replace[len - 1] = '\0';
            printf("Case #%d:\n%s\n", i + 1, temp_replace);
    }
    fclose(fp);
    return 0;
}