#include <stdio.h>

int main(void) {
	int num1, num2, num3, num4, num5, num6;
    char op1, op2, op3, op4, op5, op6;

	scanf("%d %c %d %c", &num1, &op1, &num2, &op2);
	scanf("%d %c %d %c", &num3, &op3, &num4, &op4);
	scanf("%d %c %d %c", &num5, &op5, &num6, &op6);

	printf("%d\n", num1 + num2);
	printf("%d\n", num3 + num4);
	printf("%d\n", num5 + num6);
   
	return 0;
}

//%.2f utk print 2 diblkg koma
//%% utk menampilkan persen, contoh %.2f%% hasil: xx.xx%