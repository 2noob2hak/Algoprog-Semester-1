#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define SIZE 5

bool check_bound (int x, int y) {
    return (x >= 0 && y >= 0 && y < SIZE && x < SIZE);
}

bool search(char arr[SIZE][6], int x, int y, char* word, int in, bool mark[SIZE][SIZE]) { // NOTE: *word == word[], both are fine in case u forgot one.
    int len = strlen(word); 

    if (in == len) // all found
        return true;

    if (!check_bound(x, y) || mark[x][y] || arr[x][y] != word[in])
        return false;

    // marking
    mark[x][y] = true;

    // 4 cardinal directions(up, down, left, right)
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {-1, 1, 0, 0}; 

    // recursion to find the next path like time travels ahead
    for (int i=0; i < 4; i++) {
        int nx = dx[i] + x;
        int ny = dy[i] + y;
        if (search(arr, nx, ny, word, in+1, mark))
            return true;
    }
    // for backtracking if it meets dead end(until it reaches the first starting point, and it continues searching for other paths)
    mark[x][y] = false;
    return false; 
}

// wrapper(simplifying the functions)
bool word_finder(char arr[SIZE][6], int x, int y, char *word) { // NOTE: *word == word[], both are fine in case u forgot one.
    bool mark[SIZE][SIZE] = {false}; 
    int in = 0; // you can just pass 0 directly to search function below but I prefer to declaring it to avoid ambiguity
    return search(arr, x, y, word, in, mark);
}

int main(void) {
    // handling input
    char arr[SIZE][6];
    int x, y, N;
    
    for (int i = 0; i<5; i++) {
        scanf("%5s", arr[i]);
    }
    
    scanf("%d %d", &x, &y);
    scanf("%d", &N);
    
    char wanted_word[26];
    scanf(" %25s", wanted_word); 

    // handling output
    if (word_finder(arr, x, y, wanted_word))
        printf("Found!\n");
    else 
        printf("Not Found!\n");
    return 0;
}