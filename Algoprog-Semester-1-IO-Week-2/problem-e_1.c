#include <stdio.h>

int main(void) {
	char id[11];
	char name[101];
	int num;
	char class;

	scanf("%s", id); 
	getchar();
	scanf(" %[^\n]", name); 
	getchar();
	scanf(" %c %d", &class, &num); 
	getchar();

	printf("Id    : %s\n", id);
	printf("Name  : %s\n", name);
	printf("Class : %c\n", class);
	printf("Num   : %d\n", num);

return 0;
}
