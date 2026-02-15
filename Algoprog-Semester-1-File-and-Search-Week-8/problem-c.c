#include <stdio.h>
#include <string.h>

int main(void) {
    FILE *fp = fopen("testdata.in", "r");
    if(fp == NULL)
    return 1;
    
    // getting the sum of testcases
    char buffer[105] = {0};
    int tcase;
    fgets(buffer, 105, fp);
    sscanf(buffer, "%d", &tcase);
    
    for (int i = 0; i < tcase; i++) {
        struct {
            char string[105];
            char og_char[30];
            char change[30];
        } data;
        memset(&data, 0, sizeof(data)); // clearing the memory of the struct
        
        // handling the input
        fgets(data.string, 105, fp);
        // sscanf(buffer, "%[^\n]", data.string); // tmrw check with just fgets straight to string, with clearing the \n
        data.string[strcspn(data.string, "\n")] = '\0';
        
        int wanted = 0;
        fgets(buffer, 105, fp);
        sscanf(buffer, "%d", &wanted);

        int count = 0;
        while(fgets(buffer, 105, fp)) {
            sscanf(buffer, "%c %c", &data.og_char[count], &data.change[count]);
            if (count == wanted - 1) break;
            count++;
        }

        // changing the characters
        char mark_arr[26] = {0};
        int len = strlen(data.string);
        for (int j = 0; j < wanted; j++) {
            int idx = data.og_char[j] - 'A';
            if (mark_arr[idx] == 0) {
                for (int k = 0; k < len; k++) 
                    if (data.og_char[j] == data.string[k])
                        data.string[k] = data.change[j];
                
                mark_arr[idx] = 1;
            }
        }   
        // handling output
        for (int j = 0; j < 26; j++) {
            count = 0;
            int alphabet = 'A' + j;
            for (int k = 0; k < len; k++) 
                if (alphabet == data.string[k])
                    count++;
            
            if (count > 0)
                printf("%c %d\n", alphabet, count);
        }
    }
    fclose(fp);
    return 0;
}