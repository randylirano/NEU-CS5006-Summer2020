/*
CS5006
Homework 4 - Problem 1 and 2: Max Heap and Heap Sort
2020/07/14
Randy Lirano
*/

// This program implements max heap package

// Utility import
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// The number of element a heap can hold
#define CAPACITY 100
// The top limit for random number
#define RANDOM_NUMBER_LIMIT 100

// Array representation of the Heap
int heap[CAPACITY];
// The number of element in the Heap
int heapSize = 0;

// Source array
int source[CAPACITY];
int heap_sort[CAPACITY];


// Utility swap index
void swap(int* p1, int* p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

// Return the index of the parent
int parent(int i) {
    return (i - 1) / 2;
}

// Return the index of the left child
int leftChild(int i) {
    return (i * 2) + 1;
}

// Return the index of the right child
int rightChild(int i) {
    return (i * 2) + 2;
}

// Return true if the heap is empty, and false otherwise
bool isEmpty() {
    return heapSize == 0;
}

// Return true if the heap is full, and false otherwise
bool isFull() {
    return heapSize == CAPACITY;
}

void rebalanceUp(int i) {
    int left = leftChild(i);
    int right = rightChild(i);
    int largest = i;

    // check if the left node is larger than the current node
    if (left <= heapSize && heap[left] > heap[largest]) {
        largest = left;
    }

    // check if the right node is larger than the current node
    if (right <= heapSize && heap[right] > heap[largest]) {
        largest = right;
    }

    // swap the largest node with the current node
    // and repeat this process until the current node is larger than
    // the right and the left node
    if (largest != i) {
        swap(&heap[i], &heap[largest]);
        rebalanceUp(largest);
    }

}

// insert value d into the heap and re-balance the heap
// if the heap is full, print an error msg
void push(int d) {
    if (isFull()) {
        printf("Heap is already full, cannot insert anymore element.");
        return;
    }

    // Insert element at the end of the heap
    heapSize += 1;
    int i = heapSize - 1;
    heap[i] = d;

    while (i != 0 && heap[parent(i)] < heap[i]) {
        swap(&heap[i], &heap[parent(i)]);
        i = parent(i);
    }
}

// returns d from top of heap (the largest value in the heap) and re-balance the heap
// if heap is empty, print an error msg
int pop() {
    if (isEmpty()) {
        printf("Heap is empty, no element to pop. returning -1 instead\n");
        return -1;
    }

    int root = heap[0];
    heap[0] = heap[heapSize - 1];
    heap[heapSize - 1] = 0;
    heapSize--;
    rebalanceUp(0);
    return root;
}

void printHeap() {
    for (int j = 0; j < CAPACITY; j++) {
        printf("%3.2d", heap[j]);
    }
    printf("\n");
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
    // Test Max-Heap
    // printf("Test Max-Heap:\n");
    // printHeap();

    // Test push and pop
    // push(66);
    // printHeap();
    // push(35);
    // printHeap();
    // push(29);
    // printHeap();
    // push(33);
    // printHeap();
    // pop();
    // pop();
    // printHeap();

    // Test pop on empty heap
    // pop();

    // Seed for random number generator
    srand((unsigned) time(NULL));

    // Populate source with random number between 0 and 99
    for (int i = 0; i < CAPACITY; i++) {
        source[i] = rand() % RANDOM_NUMBER_LIMIT;
    }
    printf("Source array\n");
    printArray(source, CAPACITY, 5);
    printf("\n");

    for (int i = 0; i < CAPACITY; i++) {
        push(source[i]);
    }
    printf("Heap\n");
    printArray(heap, CAPACITY, 5);
    printf("\n");

    for (int i = 0; i < CAPACITY; i++) {
        heap_sort[i] = pop();
    }
    printf("Sorted array\n");
    printArray(heap_sort, CAPACITY, 5);
    printf("\n");


    return 0;
}
