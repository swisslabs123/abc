#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to perform insertion sort
void insertion_sort(long a[], int n) {
    int i, j;
    long v;
    for (i = 1; i < n; i++) {
        v = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > v) {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = v;
    }
}

int main() {
    clock_t starttime, endtime;
    double clk;
    int i, n;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    long a[n];
    for (i = 0; i < n; i++) {
        a[i] = 9000000000 + (rand() % 99999999) + 1;
    }

    printf("Input numbers are:\n");
    for (i = 0; i < n; i++) {
        printf("%ld\n", a[i]);
    }

    starttime = clock();
    insertion_sort(a, n);
    endtime = clock();

    clk = (double)(endtime - starttime) / CLOCKS_PER_SEC;
    printf("Sorted numbers are:\n");
    for (i = 0; i < n; i++) {
        printf("%ld\n", a[i]);
    }

    printf("THE RUN TIME IS : %f\n", clk);

    return 0;
}
