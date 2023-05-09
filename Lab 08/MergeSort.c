#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_SIZE 100000

int arr[MAX_SIZE]; 
int n; // number of elements in the array

// function to merge two sorted subarrays into a single sorted array
void merge(int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1; // size of left subarray
    int n2 = right - mid; // size of right subarray
    int leftArr[n1], rightArr[n2]; // temporary arrays to store the subarrays

    // copy the elements of the left subarray to the temporary array
    for (i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];

    // copy the elements of the right subarray to the temporary array
    for (j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];

    // merge the two subarrays into a single sorted array
    i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }
    // copy the remaining elements of the left subarray to the sorted array
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    // copy the remaining elements of the right subarray to the sorted array
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

// function to sort a subarray using merge sort algorithm
void *mergeSort(void *args) {
    int *params = (int *)args;
    int left = params[0]; // starting index of the subarray
    int right = params[1]; // ending index of the subarray

    if (left < right) {
        int mid = left + (right - left) / 2; // find the middle index of the subarray

        // create two subarrays for the left and right halves of the original subarray
        int params1[2] = {left, mid};
        int params2[2] = {mid + 1, right};

        // create two threads to sort the two subarrays
        pthread_t tid1, tid2;
        pthread_create(&tid1, NULL, mergeSort, params1);
        pthread_create(&tid2, NULL, mergeSort, params2);

        // wait for the two threads to finish sorting their respective subarrays
        pthread_join(tid1, NULL);
        pthread_join(tid2, NULL);

        // merge the sorted subarrays into a single sorted array
        merge(left, mid, right);
    }

    pthread_exit(NULL);
}

int main() {
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int params[2] = {0, n - 1}; // create parameters for the first call to mergeSort

    // create a thread to sort the entire array using merge sort
    pthread_t tid;

    pthread_create(&tid, NULL, mergeSort, params);
    pthread_join(tid, NULL);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n");

    return 0;
}
