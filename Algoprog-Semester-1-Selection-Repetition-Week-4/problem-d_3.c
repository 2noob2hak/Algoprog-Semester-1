#include <stdio.h>

int main (void) {
	int T,A,B,C,discount,i;
	scanf("%d", &T);
	for (i=0; i<T; i++) {
		scanf("%d %d %d",&A,&B,&C);
		discount = A * B/100;
		if (discount >= C) {
			printf("Case #%d: %d\n", i+1, C);
		} else {
			printf("Case #%d: %d\n", i+1, discount);
		}
	}
	return 0;
}
