#include <stdio.h>
#include <string.h>

int main(void) {
	char nama[100];
	fgets(nama, sizeof(nama), stdin);
	nama[strcspn(nama, "\n")] = '\0';
	printf("Congrats \"%s\" for joining the CS department at BINUS.\n", nama);
	return 0;
}
