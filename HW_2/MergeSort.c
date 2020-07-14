/*
CS5006
Homework 2 - Problem 1: Merge Sort
2020/07/14
Randy Lirano
*/

// This program implements divide-and-conquer algorithm using a merge sort.

#include <stdio.h>

// Requirement for random number generator
#include <stdlib.h>
#include <time.h>

// The number of element in the array
#define ELEMENTS 50

// The limit for random number is 0 - 99
#define LIMIT 100


// Utility methods
void printArray(int arr[], int size, int row) {
    int i;
    int j;
    int k  = size / row;

    for (i = 0; i < row; i++) {
        for (j = i * k; j < (i + 1) * k; j++) {
            printf("%4d", arr[j]);
        }
        printf("\n");
    }
}

// Merge
void merge(int arr[], int l, int m, int r) {
    int i = 0, j = 0, k = l;
    int leftSize = m - l + 1;
    int rightSize = r - m;

    int left[leftSize];
    int right[rightSize];

    // Populate left array with arr[l:m]
    for (i = 0; i < leftSize; i++) {
        left[i] = arr[l + i];
    }

    // Populate right array with arr[m + 1, r]
    for (j = 0; j < rightSize; j++) {
        right[j] = arr[m + 1 + j];
    }

    i = 0;
    j = 0;

    // Start merging left and right array
    // The smaller number between the two will be inserted first
    while (i < leftSize && j < rightSize) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    // If left still have some elements
    while (i < leftSize) {
        arr[k] = left[i];
        i++;
        k++;
    }

    // If right still have some elements
    while (j < rightSize) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}


int main() {
    // Initialize an array of integer with the size of ELEMENTS
    int arr[ELEMENTS];

    // Seed for random number generator
    srand((unsigned) time(NULL));

    // Populate arr with random number between 0 and 99
    for (int i = 0; i < ELEMENTS; i++) {
        arr[i] = rand() % LIMIT;
    }

    // int arr[] = { 12, 11, 13, 5, 6, 7 };
    // int arraySize = sizeof(arr) / sizeof(arr[0]);

    // Print original array
    printArray(arr, ELEMENTS, 5);
    mergeSort(arr, 0, ELEMENTS - 1);
    printArray(arr, ELEMENTS, 5);

    return 0;
}
