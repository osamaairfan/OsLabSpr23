#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

	/* Function to merge two subarrays of arr[] */
void merge(int* arr, int l, int m, int r) {
    int i, j, k, n1 = m - l + 1, n2 = r - m;
    int L[n1], R[n2];
	/* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
    }
	/* Merge the temp arrays back into arr[l..r]*/
    i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
/* Copy the remaining elements of L[], if there are any */

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
	/* Copy the remaining elements of R[], if there are any */

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
	/* Recursive function to sort subarrays using merge sort */

void merge_sort(int* arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
    /* Divide the array into two subarrays and sort them concurrently */

        #pragma omp parallel sections num_threads(2)
        {
            #pragma omp section
            {
                merge_sort(arr, l, m);
            }
            #pragma omp section
            {
                merge_sort(arr, m + 1, r);
            }
        }
    /* Merge the sorted subarrays */

        merge(arr, l, m, r);
    }
}

int main() {
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Given array is \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
	/* Sort the array using merge sort */
    #pragma omp parallel num_threads(2)
    {
        #pragma omp single
        {
            merge_sort(arr, 0, n - 1);
        }
    }
	/* Print the sorted array */
    printf("\nSorted array is \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
