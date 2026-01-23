#include <stdio.h>

int main(void) {
	int T,A,B,i,empty,total;
	scanf("%d", &T);
	for (i=0;i<T;i++) {
        scanf("%d %d", &A, &B);
        empty = A;
        total = A;
        while (empty >= B) {
            empty = empty-B+1;
            total++;
        }
		printf("Case #%d: %d\n", i+1, total);
	}
	return 0;
}
