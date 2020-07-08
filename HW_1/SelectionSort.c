/*
CS5006
Homework 1 - Problem 1: Selection Sort
2020/07/07
Randy Lirano
*/

// This program implements selection sort algorithm using a single array.
// The modification done on an actual array without building a sorted copy array.

#include <stdio.h>

// Requirement for random number generator
#include <stdlib.h>
#include <time.h>

#define ELEMENTS 100

// Swap method takes two pointers, and switch the value pointed between two pointers
void swap(int* p1, int* p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}


// Selection sort takes an unsorted array and its size
// iterate the array using two index (i and j)
// The left-hand-side of i will be sorted
void selectionSort(int arr[], int size) {
    int i;
    int j;
    int temp;

    for (i = 0; i < size - 1; i++) {
        for (j = i + 1; j < size; j++) {
            if (arr[j] <= arr[i]) {
                swap(&arr[i], &arr[j]);
            }
        }
    }
}

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


int main() {
    int r, a, b;

    // Initialize an array of integer with the size of ELEMENTS
    int arr[ELEMENTS];

    // Seed for random number generator
    srand((unsigned) time(NULL));

    // Populate arr with random number between 0 and 99
    for (a = 0; a < ELEMENTS; a++) {
        arr[a] = rand() % ELEMENTS;
    }

    // Print original array
    printArray(arr, ELEMENTS, 5);

    selectionSort(arr, ELEMENTS);

    printf("Sorted Array:\n");
    printArray(arr, ELEMENTS, 5);

    
    return 0;
}
