#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateRandomSubset(int n) {
    if (n <= 0) {
        printf("Invalid input. Please enter a positive integer.\n");
        return;
    }

    // Initialize an array from 1 to n
    int* numbers = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        numbers[i] = i + 1;
    }

    // Seed the random number generator
    srand(time(NULL));

    // Perform Fisher-Yates shuffle to shuffle the array
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        // Swap numbers[i] and numbers[j]
        int temp = numbers[i];
        numbers[i] = numbers[j];
        numbers[j] = temp;
    }

    // Calculate the size of the random subset (k)
    int k = rand() % (n + 1);

    // Print the random subset
    printf("Random Subset of {1, 2, ..., %d} with size %d: {", n, k);
    for (int i = 0; i < k; i++) {
        printf("%d", numbers[i]);
        if (i < k - 1) {
            printf(", ");
        }
    }
    printf("}\n");

    // Free dynamically allocated memory
    free(numbers);
}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    generateRandomSubset(n);

    return 0;
}
