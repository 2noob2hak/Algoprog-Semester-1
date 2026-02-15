#include <stdio.h>
#include <string.h>

int main(void) {
    FILE *fp = fopen("testdata.in", "r");
    if (fp == NULL) {
        return 1;
    }

    // handling input
    int T = 0;
    char buffer[105];
    fgets(buffer, 105, fp);
    sscanf(buffer, "%d", &T);
    
    for (int i = 0; i < T; i++) {
        int N = 0;
        fgets(buffer, 105, fp);
        sscanf(buffer, "%d", &N);
        
        struct {
            char info[8];
            char product[55];
            int quantity;
        } data[N];
        memset(data, 0, sizeof(data));

        for (int j = 0; j < N; j++) {
            fgets(buffer, 105, fp);
            sscanf(buffer, "%[^#]#%[^#]#%d", data[j].info, data[j].product, &data[j].quantity);
        }

        // sort for diff product
        char mark_arr[N][55];
        memset(mark_arr, 0, sizeof(mark_arr));
        int count = 0;
        
        for (int k = 0; k < N; k++) {
            int dupe = 0;
            for (int j = 0; j < count; j++) {
                if (strcmp(mark_arr[j], data[k].product) == 0){
                    dupe = 1;
                    break;
                } 
            }
            if (dupe != 1) {
                strcpy(mark_arr[count], data[k].product);
                count++;
            }
        }

        // check for stock after transaction
        int current_stock[count];
        memset(current_stock, 0, sizeof(current_stock));
        for (int j = 0; j < count; j++) {
            for (int k = 0; k < N; k++) {
                if (strcmp(mark_arr[j], data[k].product) == 0) {
                    if (strcmp(data[k].info, "buy") == 0) 
                        current_stock[j] += data[k].quantity;
                    else current_stock[j] += -(data[k].quantity); 
                }
                else continue;
            }
        }

        // check if there is any stock that is not enough
        int possible = 1, mark_idx[count], temp = 0;
        memset(mark_idx, 0, sizeof(mark_idx));
        for (int j = 0; j < count; j++) {
            if (current_stock[j] < 0) {
                possible = 0;
                mark_idx[temp] = j;
                temp++;
            }
        }

        // handling output
        printf("Case #%d:\n", i + 1);
        if (possible == 1) 
            for (int j = 0; j < count; j++) 
                printf("%s - %d\n", mark_arr[j], current_stock[j]);
        
        else 
            for (int j = 0; j < temp; j++)    
                printf("stock is not enough for product %s\n", mark_arr[mark_idx[j]]);
    }
    return 0;
}