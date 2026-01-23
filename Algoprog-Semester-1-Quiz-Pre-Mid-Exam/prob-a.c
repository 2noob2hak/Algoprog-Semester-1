// Title: Oddrage
#include <stdio.h>

int main(void) {
	int N; 
	// handling input 
	scanf("%d", &N);
	long long arr[N];

	for (int a=0; a<N; a++) 
		scanf("%lld", &arr[a]);
	
	int odd=1;
	int odd_rage=0;

	// records the first even numbers from the inputted array value
	long long first_even = 0;
	for (int i=0; i<N; i++) {
		if (arr[i] % 2 == 0) {
			first_even = arr[i];
			break;
		}
	}

	// making the first even number as absolute
	long long abs_first_even = 0;
	if (first_even < 0) abs_first_even = first_even * -1;
	else abs_first_even = first_even;

	// compute
	for (int j=0; j<N; j++) 
	{
		if (arr[j] % 2 != 0 && odd < 3) 
		{
			if (arr[j] > 0) // for positive numbers
				arr[j] = arr[j] - 1;
			
			else if (arr [j] < 0) // for negative numbers
				arr[j] = arr[j] + 1;	
			
			odd++;
		}
		else if (odd >= 3 && odd_rage <= abs_first_even) 
		{
			arr[j] = first_even;
			odd_rage++;
			if (odd_rage == abs_first_even) {
				odd = 0; // resets the odd
				odd_rage = 0; // resets the odd_rage as per the absolute value of the first even number
			}
			
		}
	}

	// handling output
	for (int k=0; k<N; k++) {
		if (k <= N-1 && k != 0) {
			printf(" ");
		}
		printf("%lld", arr[k]);
	}
	printf("\n");
	return 0;
}

/*
NOTE:
This code was made after the quiz, so I haven't got the chance to 
test it with the online judge. If this code got "WRONG" answer, possibly
because I resets the odd count and odd_rage count (line 33-36).

*/
