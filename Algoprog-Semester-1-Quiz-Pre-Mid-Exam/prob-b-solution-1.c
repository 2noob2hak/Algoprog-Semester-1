// Title: Multiply String
#include <stdio.h>
#include <string.h>
// Using more advance functions than solution 2 or 3
int main(void) {
	// handling input
	char input_arr[1005];
	fgets(input_arr, sizeof(input_arr), stdin);
	
	int x, index;
	scanf("%d", &index);
	scanf("%d", &x);

	// change the inputted '\n' at the end of inputted strings to '\0' null terminator 
	input_arr[strcspn(input_arr, "\n")] = '\0';

	// declaring a pointer to be use later that will be aiming at input_arr based on index that have been inputted
	char* the_chosen_one = NULL; // NULL works just like int a = 0; (like safety switch)
	
	// declaring a pointer to the address of the first char of a string (that has been tokenized by strtok using '\0')
	char* token = strtok(input_arr, " "); // strtok finds the first ' ' (space) and change it to '\0'  

	for (int i = 0; i <= index; i++) { // searching the chosen one
		if (token == NULL) // just a safety nett if index is bigger than the actual inputted strings
			break;

		if (i == index) 
			the_chosen_one = token;
		
		token = strtok(NULL, " ");
	}

	// handling output
	for (int j = 0; j < x; j++) {
		printf("%s", the_chosen_one);
		if (j < x - 1) printf(" ");
	}
	printf("\n");

	return 0;
}

/*
NOTE: This code was made after the quiz, meaning I haven't had the chance to actually test it
with OJ systems. if you had the chance to check/use it with OJ and got "WRONG ANSWER", try changing
the array size(e.g. 1005, 1505, etc.).
*/



