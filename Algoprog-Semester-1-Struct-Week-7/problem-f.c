#include <stdio.h>
#include <string.h>

typedef struct {
    char name[105];
    int NIM;
    int age;
    int pos_code;
    char place_birth[105];
    char date_birth[105];
    char hs[105];
    int sibling_sum;
    int height;
    int account_num;
} data;

int main(void) {
    int N = 0;
    scanf("%d", &N);
    data college[N];

    for (int i = 0; i < N; i++) {
        scanf("%100s", college[i].name);
        scanf("%d", &college[i].NIM); 
        scanf("%d", &college[i].age); 
        scanf("%d", &college[i].pos_code); 
        scanf("%s", college[i].place_birth); 
        scanf("%s", college[i].date_birth); 
        while(getchar() != '\n');
        fgets(college[i].hs, 105, stdin);
        college[i].hs[strcspn(college[i].hs, "\n")] = '\0'; 
        scanf("%d", &college[i].sibling_sum);  
        scanf("%d", &college[i].height); 
        scanf("%d", &college[i].account_num); 
    }

    // handling the freakin output
    for (int i = 0; i < N; i++) {
        printf("Mahasiswa ke-%d:\n", i + 1);
        printf("Nama: %s\n", college[i].name);
        printf("NIM: %d\n", college[i].NIM);
        printf("Umur: %d\n", college[i].age);
        printf("Kode Pos: %d\n", college[i].pos_code);
        printf("Tempat Lahir: %s\n", college[i].place_birth);
        printf("Tanggal Lahir: %s\n", college[i].date_birth);
        printf("Almamater SMA: %s\n", college[i].hs);
        printf("Jumlah Saudara Kandung: %d\n", college[i].sibling_sum);
        printf("Tinggi Badan: %d\n", college[i].height);
        printf("NOMOR REKENING: %d\n", college[i].account_num);
    }

    return 0;
}