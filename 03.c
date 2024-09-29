#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int i, n, a[1000], key, bottom, top, mid, j, temp;
    double clk;
    clock_t starttime, endtime;

    // Seed the random number generator
    srand(time(NULL));

    printf("Enter the number of Products: ");
    scanf("%d", &n);

    // Generate random product IDs and print them
    printf("The Product IDs are: \n");
    for (i = 0; i < n; i++) {
        a[i] = rand() % 100;
        printf("%d ", a[i]);
    }
    printf("\n");

    // Sort the array using bubble sort
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    // Print the sorted array
    printf("\nSorted Product ID List is: \n");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    // Get the product ID to search for
    printf("Enter the Product ID to be searched: ");
    scanf("%d", &key);

    // Start timing the binary search
    starttime = clock();

    // Initialize binary search bounds
    bottom = 0;
    top = n - 1;

    // Perform binary search
    while (bottom <= top) {
        mid = (bottom + top) / 2;
        if (key < a[mid]) {
            top = mid - 1;
        } else if (key > a[mid]) {
            bottom = mid + 1;
        } else {
            break; // Key found
        }
    }

    // Check if the key was found
    if (bottom <= top && a[mid] == key) {
        printf("Product found!!\n");
        printf("Product %d found in position: %d\n", key, mid + 1);
    } else {
        printf("Search failed\n");
        printf("%d not found\n", key);
    }

    // End timing the binary search
    endtime = clock();
    clk = (double)(endtime - starttime) / CLOCKS_PER_SEC;
    printf("Time taken for the search: %f seconds\n", clk);

    return 0;
}
