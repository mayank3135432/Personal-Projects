#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10000

int main() {
    int array[ARRAY_SIZE];
    int i;

    // Seed the random number generator
    srand(time(NULL));

    // Fill the array with random positive integers
    for (i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % 100000 + 1; // Generate a random number between 1 and 10000
    }

    // Print the array
    printf("Array contents:\n");
    printf("{");
    for (i = 0; i < ARRAY_SIZE; i++) {
        printf("%d,", array[i]);
    }
    printf("\b}");
    printf("\n");
    

    return 0;
}