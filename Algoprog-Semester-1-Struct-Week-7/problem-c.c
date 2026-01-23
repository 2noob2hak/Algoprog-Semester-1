#include <stdio.h>
#include <string.h>

int main(void) {
    int N;
    scanf("%d", &N); 
    struct {
        char lecturer_code[35];
        char lecturer_name[35];
        char lecturer_gender[35];
        int student_sum;

        char student_code[35];
        char student_name[35];
        char student_gender[35];

        char father_name[35];
        char mother_name[35];
        int sibling_sum;
    } data[N][100];

    memset(data, 0, sizeof(data));

    for (int i = 0; i < N; i++) {
        scanf("%34s", data[i][0].lecturer_code); 
        scanf("%34s", data[i][0].lecturer_name); 
        scanf("%34s", data[i][0].lecturer_gender); 
        scanf("%d", &data[i][0].student_sum); 

        for (int j = 0; j < data[i][0].student_sum; j++) {
            scanf("%s", data[i][j].student_code); 
            scanf("%s", data[i][j].student_name); 
            scanf("%s", data[i][j].student_gender); 
            scanf("%s", data[i][j].father_name); 
            scanf("%s", data[i][j].mother_name); 
            scanf("%d", &data[i][j].sibling_sum);
        }
    }

    int wanted = 0;
    scanf("%d", &wanted); wanted -= 1; // translating into base 0

    // handling output
    printf("Kode Dosen: %s\n", data[wanted][0].lecturer_code);
    printf("Nama Dosen: %s\n", data[wanted][0].lecturer_name);
    printf("Gender Dosen: %s\n", data[wanted][0].lecturer_gender);
    printf("Jumlah Mahasiswa: %d\n", data[wanted][0].student_sum);
    for (int i = 0; i < data[wanted][0].student_sum; i++) {
        printf("Kode Mahasiswa: %s\n", data[wanted][i].student_code);
        printf("Nama Mahasiswa: %s\n", data[wanted][i].student_name);
        printf("Gender Mahasiswa: %s\n", data[wanted][i].student_gender);
        printf("Nama Ayah: %s\n", data[wanted][i].father_name);
        printf("Nama Ibu: %s\n", data[wanted][i].mother_name);
        printf("Jumlah Saudara Kandung: %d\n", data[wanted][i].sibling_sum);
    }
    return 0;
}